#include <stdio.h>

struct pstruct
{
    int fno;   
    int pbit;
} ptable[10];

int pmsize, lmsize, psize;
int frame, page;
int ftable[20], frameno;


void info()
{
    printf("\n\nMEMORY MANAGEMENT USING PAGING\n\n");

    printf("Enter the Size of Physical Memory: ");
    scanf("%d", &pmsize);

    printf("Enter the Size of Logical Memory: ");
    scanf("%d", &lmsize);

    printf("Enter the Page Size: ");
    scanf("%d", &psize);

    frame = pmsize / psize;
    page  = lmsize / psize;

    printf("\nPhysical memory is divided into %d frames\n", frame);
    printf("Logical memory is divided into %d pages\n", page);
}


void assign()
{
    int i;

    
    for(i = 0; i < page; i++)
    {
        ptable[i].fno = -1;
        ptable[i].pbit = -1;
    }


    for(i = 0; i < frame; i++)
    {
        ftable[i] = -1;
    }

    
    for(i = 0; i < page; i++)
    {
        printf("\nEnter the frame number for page %d: ", i);
        scanf("%d", &frameno);

        ftable[frameno] = i;

        if(ptable[i].pbit == -1)
        {
            ptable[i].fno = frameno;
            ptable[i].pbit = 1;
        }
    }

    // Display Page Table
    printf("\n\nPAGE TABLE\n");
    printf("Page\tFrame\tPresence Bit\n");

    for(i = 0; i < page; i++)
    {
        printf("%d\t%d\t%d\n", i, ptable[i].fno, ptable[i].pbit);
    }

    
    printf("\nFRAME TABLE\n");
    printf("Frame\tPage\n");

    for(i = 0; i < frame; i++)
    {
        printf("%d\t%d\n", i, ftable[i]);
    }


}


void cphyaddr()
{
    int laddr, paddr, disp, phyaddr, baddr;

    printf("\n\nPROCESS TO FIND PHYSICAL ADDRESS\n");

    printf("\nEnter Base Address: ");
    scanf("%d", &baddr);

    printf("Enter Logical Address: ");
    scanf("%d", &laddr);

    paddr = laddr / psize;  
    disp  = laddr % psize;   

    if(ptable[paddr].pbit == 1)
    {
        phyaddr = baddr + (ptable[paddr].fno * psize) + disp;
        printf("\nPhysical Address = %d\n", phyaddr);
    }
    else
    {
        printf("\nPage Fault! Page not present.\n");
    }

}


void main()
{

    info();
    assign();
    cphyaddr();
}
