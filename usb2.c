#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>

#define USB_VENDOR_ID       ( 0x1db6 )
#define USB_PRODUCT_ID      ( 0x0001 )

static int my_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
//printk("Probe  called");
return 0;
}
 struct  usb_device_id my_table[] ={
{
USB_DEVICE(USB_VENDOR_ID,USB_PRODUCT_ID)}
};

static void usb_disconnect(struct usb_interface *interface)
{ dev_info(&interface->dev,"USB Driver disconnected\n");
}
MODULE_DEVICE_TABLE(usb,my_table);
static struct usb_driver USB_driver = {
.name =  "USB driver w/o module_int & module_exit",
.probe  = my_probe,
.disconnect = usb_disconnect,
.id_table = my_table,
};
module_usb_driver(USB_driver);


/*static int __init USB_driver(void)
{
return usb_register(&USB_driver);
}

static void  __exit USB_driver(void)
{
 usb_deregister(&USB_driver);
}*/

MODULE_LICENSE("'GPL");
MODULE_AUTHOR("MIRZA");
MODULE_DESCRIPTION("SIMPLE DRIVER");
MODULE_VERSION("1.1");
