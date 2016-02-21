#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/pci.h>


#define DRV_NAME		"PCIe enumerator"
#define DRV_DESCRIPTION		"PCIe enumeration sample code"
#define DRV_COPYRIGHT		"Copyright(c) @KSYST.ORG"

MODULE_DESCRIPTION(DRV_DESCRIPTION);
MODULE_AUTHOR(DRV_COPYRIGHT);
MODULE_LICENSE("GPL");

#define INTEL_8255X_ETHERNET_DEVICE(device_id, ich) {\
	PCI_VENDOR_ID_INTEL, device_id, PCI_ANY_ID, PCI_ANY_ID, \
	PCI_CLASS_NETWORK_ETHERNET << 8, 0xFFFF00, ich }
static DEFINE_PCI_DEVICE_TABLE(my_id_table) = {
	INTEL_8255X_ETHERNET_DEVICE(0x1094, 7),
	{ 0, }
};
MODULE_DEVICE_TABLE(pci, my_id_table);

static int my_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{

printk(KERN_INFO "Hi there, I am 'my_probe'!, device id is %c vendor id is %c",ent->device,ent->vendor);
return 0;
}
static void my_remove(struct pci_dev *pdev)
{
printk(KERN_INFO "Hi there, I am 'my_remove'!");
}
static struct pci_driver e100_driver = {
	.name =         DRV_NAME,
	.id_table =     my_id_table,
	.probe =        my_probe,
	.remove =       my_remove,
};

static int __init e100_init_module(void)
{
	return pci_register_driver(&e100_driver);
}

static void __exit e100_cleanup_module(void)
{
	pci_unregister_driver(&e100_driver);
}

module_init(e100_init_module);
module_exit(e100_cleanup_module);
