MACHINE = "genericx86-64"

INITRAMFS_IMAGE_BUNDLE = "1"
INITRAMFS_IMAGE = "trustx-cml-initramfs"

IMAGE_FSTYPES = "cpio ext4"
TRUSTME_FSTYPES = "wic wic.bmap"
TRUSTME_PARTTABLE_TYPE = "gpt"
TRUSTME_CONTAINER_ARCH = "qemux86-64"

TRUSTME_HARDWARE = "x86"
TRUSTME_LOGTTY = "tty11"

PKI_UEFI_KEYS = "y"

PACKAGE_CLASSES = "package_ipk"
BBMULTICONFIG = "container installer"

PREFERRED_PROVIDER_virtual/kernel:genericx86-64 ?= "linux-rolling-stable"
PREFERRED_PROVIDER_virtual/kernel:gyroidos-cml ?= "linux-rolling-stable"

INITRAMFS_MODULES = ""

INITRAMFS_MAXSIZE = "150000"

PACKAGE_INSTALL:append:pn-trustx-cml-initramfs = "${INITRAMFS_MODULES}"
PACKAGE_INSTALL:append:pn-trustx-installer-initramfs = "${INITRAMFS_MODULES}"

IMAGE_BOOT_FILES:genericx86-64 = "${KERNEL_DEPLOYSUBDIR}/bzImage-initramfs-${MACHINE}.bin.signed;EFI/BOOT/BOOTX64.EFI"
WKS_FILE:genericx86-64 = "trustx-cml.genericx86.wks.in"
