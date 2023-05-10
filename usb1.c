#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/usb.h>
#define USB_VENDOR_ID (0x1d6b)
#define USB_PRODUCT_ID (0X0001)

static int usb_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
//printk(KERN_INFO "pen drive (%04x:%04x) plugged\n",id->idvendor,id->idproduct);
return 0;
}


static void usb_disconnect(struct usb_interface *interface)
{
dev_info(&interface->dev,"USB Driver disconnected\n");
//pr_info("USB disconnect function executed");
}

const struct  usb_device_id usb_table[]={
{ USB_DEVICE(USB_VENDOR_ID ,USB_PRODUCT_ID) },
{ //pr_info("ID Table function executed");
}
};

static struct usb_driver USB_driver ={
.name = "First USB driver prectice",
.probe =  usb_probe,
.disconnect = usb_disconnect,
.id_table = usb_table,
};

static int __init usb_driver_init(void)
{
return usb_register(&USB_driver);
}
static void __exit usb_driver_exit(void)
{
usb_deregister(&USB_driver);
}

module_init(usb_driver_init);
module_exit(usb_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MIRZA");
MODULE_DESCRIPTION("FIRST PRACTICE ON USB DRIVER");
MODULE_VERSION("1.1");

