/*libvirt program */

#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
int main(int argc, char *argv[])
{
    virConnectPtr conn;
    virDomainPtr vdp;
    int val=-1;
    int choice; 
    char *host;
    conn = virConnectOpen("xen:///");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to xen:///\n");
        return 1;
    }

    while(1)
    {
        printf("Enter choice..");
        printf("1.start\n2.suspend\n3.resume\n4.stop\n5.exit");
        scanf("%d",&choice);

        switch(choice)
        {

            vdp=virDomainLookupById(conn,1);


            /*start*/
            case 1: val=virDomainCreate(vdp);
                    if(val==0)
                    {
                        printf("Success");
                    }else{
                        printf("Failed");   
                    }

                    /* suspend*/    
            case 2: val=virDomainSuspend(vdp);

                    if(val==0)
                    {
                        printf("suspend Successfully");
                    }else{
                        printf("suspend Failed");   
                    }


                    /*resume*/
            case 3: val=virDomainResume(vdp);
                    if(val==0)
                    {i
                        printf("Resume Successfully");
                    }else{
                        printf("Resume Failed");   
                    }


                    /*shutdown*/
            case 4: val=virDomainDestroy(vdp);
                    if(val==0)
                    {
                        printf("Success");
                    }else{
                        printf("Failed");   
                    }
            case 5: virConnectClose(conn);
                    break;

        }   
        return 0;
    }
