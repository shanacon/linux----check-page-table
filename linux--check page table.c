#include<linux/init.h>
#include<linux/pid.h>
#include<linux/sched.h>
#include<linux/module.h>
#include<linux/mm_types.h>
#include<linux/kernel.h>
#include<asm/pgtable.h>
#include<linux/highmem.h>


asmlinkage void sys_solve2(unsigned long addr){
    struct task_struct* task=NULL;
    int count=0;
    for_each_process(task){
        count++;
        printk("count%d:\n",count);
	printk("pid=%d\n",task->pid);
        pgd_t *pgd;
        pte_t *ptep;
       	pte_t pte;
	pud_t *pud;
       	pmd_t *pmd;
	pmd_t pmd2;
	unsigned long pa=0;
	unsigned long page_addr=0;
	unsigned long page_offset=0;
        struct mm_struct* mm=NULL;
        struct page *page=NULL;
        mm=get_task_mm(task);
	if(mm){
        	pgd = pgd_offset(mm, addr);
        	pud = pud_offset(pgd, addr);
        	pmd = pmd_offset(pud, addr);
		ptep = pte_offset_kernel(pmd, addr);
        	pte = *ptep;
        	pmd2= *pmd;
		if(addr>0xc0400000){
			page=pmd_page(pmd2);
			if(page){
				printk("page frame struct is @ %p\n", page);	
			}
			page_addr=pmd_val(*pmd) & PMD_MASK;
			page_offset=addr & ~PMD_MASK;
			pa=page_addr | page_offset;
			printk("pmd mask: @ %08x\n",pa);
		}
		else{
			page = pte_page(pte);
        		if (page){
           			printk("page frame struct is @ %p\n", page);
        		} 
		}
		page_addr=pte_val(*ptep) & PAGE_MASK;
		page_offset=addr & ~PAGE_MASK;
		pa=page_addr | page_offset;
		printk("mask: @ %08x\n",pa);
	}
	else{
		printk("mm=NULL\n");
	}
    }
}
