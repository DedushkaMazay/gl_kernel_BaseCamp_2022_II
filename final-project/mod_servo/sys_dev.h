#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

#define CLASS_NAME	"servo"
#define DEVICE_NAME	"servo_control"

#define MAX_BUFFER_SIZE	256

extern dev_t MM;
extern struct cdev device;
extern struct class *class_folder;
extern struct device *dev_file;
extern struct file_operations dev_fs;

int32_t create_devFS(void);
void remove_devFS(void);

ssize_t dev_read (struct file *filep, char *to_user, size_t len, loff_t *offs);
ssize_t dev_write (struct file *filep, const char *from_user, size_t len, loff_t *offs);

int access_to_dev(struct device *dev, struct kobj_uevent_env *env);