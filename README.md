# linux_check-page-table
# 檢驗各process的kernel space所對應到的physical address是否相同
## 簡介
在linux的設計中，一個process會有4G的virtual address  
其中3G是user space，1G是kernel space  
而所有process的kernel space所對應到的physical address大部分會是相同的  
所以要用這份code來驗證這個觀念
## check page table.c
#### task_struct
task_struct就是linux中的process descriptor  
其中會包含該process的資料  
而我們這次要搜尋的page table也在其中  
#### count
在使用**for_each_process**時計算總共遍歷了幾個process
#### pgd_t pte_t pud_t pmd_t
linux使用的page規則如下  
![螢幕擷取畫面 2021-03-05 183046](https://user-images.githubusercontent.com/79785416/110103470-f31f6780-7de0-11eb-98ad-ebb7f11ae9c9.png)  
pgd_t pte_t pud_t pmd_t等等資料是為了要一層一層對應到page frame  
#### PMD_MASK
在kernel space的對應到的page frame會先經過這個遮罩的轉換才對應到實際的page frame  
## check.cpp
輸入16進位後的virtual address後在終端機輸入dmesg以查看check page table.c中輸出的資料

