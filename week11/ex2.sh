echo Text1 > lofsdisk/file1
echo Text2 > lofsdisk/file2

gcc ex2.c -o ex2
sudo cp ex2 lofsdisk
sudo chroot lofsdisk /ex2 > ex2.txt
./ex2 >> ex2.txt

sudo mkdir -p lofsdisk/bin
sudo mkdir -p lofsdisk/lib64
sudo mkdir -p lofsdisk/lib/x86_64-linux-gnu
sudo mkdir -p lofsdisk/usr/lib
sudo mkdir -p lofsdisk/usr/lib64

sudo cp /bin/bash lofsdisk/bin
sudo cp /bin/cat lofsdisk/bin
sudo cp /bin/echo lofsdisk/bin
sudo cp /bin/ls lofsdisk/bin

sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64

sudo ldd /bin/bash | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/ls | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/cat | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/echo | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
                    
