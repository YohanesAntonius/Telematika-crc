#include <iostream.h>
#include <conio.h>
 
void main()
{
    int i,j,k,l;
     
    //Bingkai
    int fs;
    cout<<"\n Masukkan ukuran: ";
    cin>>fs;
     
    int f[20];
     
    cout<<"\n Masukkan bingkai:";
    for(i=0;i<fs;i++)
    {
        cin>>f[i];
    }
 
    //Generator
    int gs;
    cout<<"\n Masukkan ukuran: ";
    cin>>gs;
     
    int g[20];
     
    cout<<"\n Masukkan Generator:";
    for(i=0;i<gs;i++)
    {
        cin>>g[i];
    }
 
    cout<<"\n Pengirim:";
    cout<<"\n Bingkai: ";
    for(i=0;i<fs;i++)
    {
        cout<<f[i];
    }
    cout<<"\n Generator :";
    for(i=0;i<gs;i++)
    {
        cout<<g[i];
    }
 
    //Tambahkan 0's
    int rs=gs-1;
    cout<<"\n : Berubah menjadi"<<rs;
    for (i=fs;i<fs+rs;i++)
    {
        f[i]=0;
    }
 
    int temp[20];
    for(i=0;i<20;i++)
    {
        temp[i]=f[i];
    }
 
    cout<<"\n Setelah ditambahkan 0 :";
    for(i=0; i<fs+rs;i++)
    {
        cout<<temp[i];
    }
 
    //Division
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        //periksa dulu apakah itu dapat dibagi atau tidak
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    //CRC
    int crc[15];
    for(i=0,j=fs;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    cout<<"\n CRC bits: ";
    for(i=0;i<rs;i++)
    {
        cout<<crc[i];
    }
 
    cout<<"\n Bingkai yang ditransmisi: ";
    int tf[15];
    for(i=0;i<fs;i++)
    {
        tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    cout<<"\n Sisi penerima : ";
    cout<<"\n Bingkai diterima: ";
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    for(i=0;i<fs+rs;i++)
    {
        temp[i]=tf[i];
    }
 
    //Division
    for(i=0;i<fs+rs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    cout<<"\n Reaminder: ";
    int rrem[15];
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }
 
    int flag=0;
    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }
 
    if(flag==0)
    {
        cout<<"\n Karena sisa reaminder adalah 0 maka pesan yang dikirim dari pengirim ke penerima adalah benar";
    }
    else
    {
        cout<<"\n Karena sisa reaminder bukan 0 maka pesan yang dikirim dari pengirim ke penerima adalah salah (eror)";
    }
    getch();
}

