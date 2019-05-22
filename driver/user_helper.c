#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

/*
envp : 環境變數的設定
argv : user program執行參數
argv[0] : user program路徑
*/
static int call_user(char* p)
{
	int ret;
    char *argv[] = {"/home/user_helper/sample",NULL};
    
    static char *envp[] = {
	"SHELL=/bin/bash",
    "HOME=/root",
    "USER=root",
	"DISPLAY=:0",
    "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", NULL };
    
    printk("Call user program now \n");
    ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC); 
	if( ret != 0 )
		printk("call helper fail\n");
	
    return 0;
}

static void __exit hello_exit(void)
{
    printk("Goodbye\n");
}

static int __init hello_init(void)
{
	call_user("anything");
    return 0;
}

module_init(hello_init);
module_exit(hello_exit);

