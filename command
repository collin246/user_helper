dtc -@ -I dts -O dtb -o uart0-disable-overlay.dtb uart0_disable_overlay.dts
https://github.com/collin246/user_helper

win scp
1.	adduser ittraining in rootfs
2.	visudo =>set user ittraining without passwd
ittraining  ALL=(ALL) NOPASSWD: ALL
3.	reboot
4.	Changes in /etc/ssh/sshd_config 
subsystem	scp	/usr/lib/openssh/scp-server
5.	reboot

