#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"e22tools.h"


void Linie(int nLng, char cZeichen)
/**********************************/
{
	for(int k=0; k<=nLng; k++) putchar(cZeichen);
	putchar('\n');
}


void Titel(const char* szTitel, char cZeichen)
/***********************************************/
{
	int nLng = strlen(szTitel);
	puts(szTitel);
	Linie(nLng, cZeichen);
}

void TitelLz(const char* szTitel, char cZeichen)
/***********************************************/
{
	int nLng = strlen(szTitel);
	puts(szTitel);
	Linie(nLng, cZeichen);
	puts("");
}


FILE* OeffneDatMitNam(const char* szDtNam, const char* szModus)
/**************************************************************/
{
	FILE* af;
	af = fopen(szDtNam, szModus);
	if (!af)
	{
		printf("Datei %s konnte nicht geoeffnet werden,\n"
			   "Programm wird mit ENTER beendet...", szDtNam);
	}
	return af;
}

FILE* OeffneDat(const char* szModus)
/***********************************/
{
	char szDatNam[21];
	FILE* af;
	printf("Name der Datei: ");    
	fgets(szDatNam, 20, stdin);
	szDatNam[strlen(szDatNam)-1] = 0;
	af = fopen(szDatNam, szModus);
	if (!af)
	{
		printf("Datei %s konnte nicht geoeffnet werden,\n"
			   "Programm wird mit ENTER beendet...", szDatNam);
	}
	return af;
}


FILE* OeffneTxtDat(const char* szModus)
/*************************************/
{
	char szDatNam[21];
	FILE* af;
	printf("Name der Textdatei ohne Erweiterung: ");    
	fgets(szDatNam, 16, stdin);
	strcpy(&szDatNam[strlen(szDatNam)-1], ".txt");
	af = fopen(szDatNam, szModus);
	if (!af)
	{
		printf("Datei %s konnte nicht geoeffnet werden,\n"
			   "Programm wird mit ENTER beendet...", szDatNam);
	}
	return af;
}

void DblFldAusgabe(double dFld[], const char* szFmt, int nAnz, int nZeile)
/************************************************************************/
{
	int k;
	for (k = 0; k < nAnz; k++)
	{
		printf(szFmt, dFld[k]);
		if (k%nZeile == nZeile - 1) puts("");
	}
}

void DblFldAusgPositiv(double dFld[],  const char* szFmt, int nAnz, int nZeile)
/******************************************************************************/
{
	char szMinus[20]; 
	int  k, nMinus;
	szMinus[0] = szMinus[1] = ' ';
	nMinus = atoi(szFmt+1);
	for (k = 2; k<nMinus;k++) szMinus[k]='*';
	szMinus[nMinus]=0;
	for (k = 0; k < nAnz; k++)
	{
		if(dFld[k]>0) printf(szFmt, dFld[k]);
		else printf("%s",szMinus);
		if (k%nZeile == nZeile - 1) puts("");
	}
}


int IntervallEingabe(const char* szKommentar, double **adFld)
/************************************************************/
{
	int nAnz, nLng, k;
	double dVon, dBis, dSch;

	puts(szKommentar);
	nLng = strlen(szKommentar);
	Linie(nLng, EINFACH);
	printf("von:          ");   scanf("%lf", &dVon);   STDINFLUSH
	printf("bis:          ");   scanf("%lf", &dBis);   STDINFLUSH
	printf("Schrittweite: ");   scanf("%lf", &dSch);   STDINFLUSH
	Linie(nLng, EINFACH);

	nAnz = (int)((dBis-dVon)/dSch + 1.1);
	*adFld = (double*)malloc(nAnz*sizeof(double));
	for(k=0; k<nAnz; k++) (*adFld)[k]= dVon +k*dSch;

	return nAnz;
}





