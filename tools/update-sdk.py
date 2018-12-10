import os, subprocess, shutil
sdk_path = os.environ['IDF_PATH']
lib_path = os.environ['HOME'] + '/hsrn/ros/esp32/'

config_files = subprocess.check_output(['find', lib_path + '/build/include/', '-name', '*.h']).decode().splitlines()
sdk_files = subprocess.check_output(['find', sdk_path, '-name', '*.h']).decode().splitlines()
sdk_files = [
    fn
    for fn in sdk_files
    if 'libcoap/examples/lwip/' not in fn
]
my_files = subprocess.check_output(['find', 'sdk', '-name', '*.h']).decode().splitlines()

def find_file(flist, name, counts=[1]):
    cand = [ f for f in flist if f.endswith('/' + name) ]
    if len(cand) in counts:
        return cand[0]

for path in my_files:
    if '/sdkconfig.h' in path: continue
    for i in [2, 1]:
        name = '/'.join(path.split('/')[-i:])
        fn = find_file(sdk_files, name)
        if fn:
            shutil.copy(fn, path)
            break

for path in my_files:
    if '/sdkconfig.h' in path: continue
    if '/include/config/' in path:
        fn = find_file(config_files, path.split('/')[-1])
        shutil.copy(fn, path)

my_libs = subprocess.check_output(['find', 'sdk', '-name', 'lib*.a']).decode().splitlines()
my_libs = set(my_libs) | set([
    'sdk/lib/libemhusarnet.a', 'sdk/lib/libhusarnet.a', 'sdk/lib/librosem.a',
    'sdk/lib/liblibsodium.a',
])
sdk_libs = subprocess.check_output(['find', lib_path, sdk_path, '-name', 'lib*.a']).decode().splitlines()
sdk_libs = [ l for l in sdk_libs if '/bootloader/' not in l ]

for lib in my_libs:
    if 'libesp32.a' in lib: continue
    fn = find_file(sdk_libs, lib.split('/')[-1], counts=[1,2])
    assert fn, lib
    shutil.copy(fn, lib)
