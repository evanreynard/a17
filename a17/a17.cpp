// a17.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
// Evan Sukarman

#define _CRT_SECURE_NO_WARNINGS

#include<math.h>
#include"fa17.h"
#include <malloc.h>
#include"e22tools.h"
int main()
{
    double R, C;
    double CU;
    double* f0, * L;
    int i, j,n;
    char szZeile[81];
    char szEinh[11];
    char* acKomma;
    char* acSuch;

    FILE* af;
    FILE* af1;


    TitelLz("Tiefpass", DOPPELT);

    af = OeffneTxtDat("rt");
    if (!af)
    {

        getchar();
        return 1;
    }
    
    af1 = OeffneDatMitNam("hlf.txt", "w+t");
    if (!af1)
    {

        getchar();
        return 1;
    }
    
    while (fgets(szZeile, 100, af)) {
        while (acKomma = strchr(szZeile, ',')) {
            *acKomma = '.';
           
        }
        fputs(szZeile, af1);
        fputs(szZeile, stdout);

    }
    rewind(af1);
    
    fscanf(af1, "%*s%*s%lg", &R);
    fscanf(af1, "%*s%*s%*s%lg%s", &C, &szEinh);
  

    n = 1;                                                          //Wegen der Zeilen(Widerstand: und Kapazität:)
 
    while(!strstr(szZeile,"Induk"))
    {
        fgets(szZeile, 100, af1);
        strstr(szZeile, "Induk");
        n++;
     
    }
   
   
    rewind(af1);
    for (int i = 0; i <n-1; i++)                                //fgets die Zeilen bis eine Zeile vor der Zeile wo "Induk" befindet,sodass das Integer vor dem Induktivität mit fscanf gespeichert  werden kann
    {
        fgets(szZeile, 100, af1);
    }
    
    fscanf(af1, "%i", &i);
    

    L = (double*)malloc(i * sizeof(double));
    f0 = (double*)malloc(i * sizeof(double));
   
    fgets(szZeile, 80, af1);
    fgets(szZeile, 80, af1);
 

    if (!strcmp(szEinh, "MikroF"))CU = 1e-6;
    else CU = 1e-9;

    puts("\ndazu gehoerende Resonanzfrequenzen");
    puts("---------------------------------------------------------");
    for (j = 0; j < i; j++) {
        fscanf(af1, "%lg", &L[j]);
        
       
        f0[j] = ResoFrequ(C * CU, L[j] * 1e-3, R)*1e-3;
        
       
      
    }
    DblFldAusgPositiv(f0, "%7.2lf", j, 8);
    free(L);
    free(f0);
    fclose(af);
    fclose(af1);
    printf("\nProgramm mit Enter beenden...");
    getchar();
    return 0;
}

