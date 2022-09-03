#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) =
{
    .name = KBUILD_MODNAME,
    .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
    .exit = cleanup_module,
#endif
    .arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
    __used
__attribute__((section("__versions"))) =
{
    { 0xe160d451, __VMLINUX_SYMBOL_STR(module_layout) },
    { 0x642e5414, __VMLINUX_SYMBOL_STR(seq_release) },
    { 0x2ea9c19f, __VMLINUX_SYMBOL_STR(seq_read) },
    { 0x29de961f, __VMLINUX_SYMBOL_STR(seq_lseek) },
    { 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
    { 0x5a125d23, __VMLINUX_SYMBOL_STR(proc_remove) },
    { 0xba660b26, __VMLINUX_SYMBOL_STR(proc_create) },
    { 0x1ac1543e, __VMLINUX_SYMBOL_STR(seq_open) },
    { 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
    { 0xf5daadf7, __VMLINUX_SYMBOL_STR(ns_to_timespec64) },
    { 0xac9657d8, __VMLINUX_SYMBOL_STR(ktime_get_with_offset) },
    { 0x9e683f75, __VMLINUX_SYMBOL_STR(__cpu_possible_mask) },
    { 0xd90043b5, __VMLINUX_SYMBOL_STR(vm_zone_stat) },
    { 0x785a93b4, __VMLINUX_SYMBOL_STR(si_mem_available) },
    { 0x7e16fb9b, __VMLINUX_SYMBOL_STR(vm_node_stat) },
    { 0x40c7247c, __VMLINUX_SYMBOL_STR(si_meminfo) },
    { 0x2408df2e, __VMLINUX_SYMBOL_STR(seq_puts) },
    { 0xa2ff9ec0, __VMLINUX_SYMBOL_STR(seq_printf) },
    { 0x9150838, __VMLINUX_SYMBOL_STR(seq_write) },
    { 0xdeaac3c5, __VMLINUX_SYMBOL_STR(seq_put_decimal_ull) },
    { 0xb19a5453, __VMLINUX_SYMBOL_STR(__per_cpu_offset) },
    { 0x6b46d923, __VMLINUX_SYMBOL_STR(cpu_info) },
    { 0x17de3d5, __VMLINUX_SYMBOL_STR(nr_cpu_ids) },
    { 0xc5e4a5d1, __VMLINUX_SYMBOL_STR(cpumask_next) },
    { 0x5a5a2271, __VMLINUX_SYMBOL_STR(__cpu_online_mask) },
    { 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
    "depends=";


MODULE_INFO(srcversion, "304BAAEB85F0F7B18E20008");
