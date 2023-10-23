

#define EINFACH    196 //ASCII-Code fuer Linienelement der einfachen waagerechten Linie
#define DOPPELT    205 //ASCII-Code fuer Linienelement der doppelten waagerechten Linie
#define SENKRECHT  179 //ASCII-Code fuer Linienelement der einfachen senkrechten Linie
#define KREUZ      197 //ASCII-Code fuer Tabellenkreuz

#define STDINFLUSH while('\n'!=getchar());  //Makro leert den Tastaturpuffer

void Linie(int nLng, char cZeichen);
////////////////////////////////////////////////////////////////////////////
// cZeichen ASCII-Code des Zeichen, das mehrfach ausgegeben wird
// nLng Länge der Linie, d.h wie oft das Zeichen ausgegeben wird
// am Ende führt die Funktion noch einen Zeilenvorsprung aus


void Titel(const char* szTitel, char cZeichen);
////////////////////////////////////////////////////////////////////////////
// Gibt den Text in szTitel aus und unterstreicht ihn
// mit dem Zeichen dessen ASCII-Code in cZeichen übergeben wurde.

void TitelLz(const char* szTitel, char cZeichen);
////////////////////////////////////////////////////////////////////////////
// Gibt den Text in szTitel aus und unterstreicht ihn
// mit dem Zeichen dessen ASCII-Code in cZeichen übergeben wurde.
// Außerdem wird unter der Linie noch eine Leerzeile ausgegeben

FILE* OeffneDatMitNam(const char* szDtNam, const char* szModus);
////////////////////////////////////////////////////////////////////////////
//Öffnet eine Datei mit dem vollständigen Dateinamen in dem Modus, die der 
//Funktion in den Parametern szDtNam bzw szModus übergeben wurden. 
//Der Modus kann jeder in der Sprache C mögliche Modus sein
//Die Funktion gibt die Adresse der FILE-Struktur mit den Steuerdaten der
//geöffneten Datei zurück. Schlägt das Öffnen der Datei fehlt, wird die
//NULL-Adresse zurückgegeben und eine entsprechende Meldung ausgegeben. 

FILE* OeffneDat(const char* szModus);
////////////////////////////////////////////////////////////////////////////
//Öffnet eine Datei in dem Modus, der im Parameter szModus übergeben wird
//Der Modus kann jeder in der Sprache C mögliche Modus sein
//Der Nutzer wird aufgafordert, den vollständigen Dateinamen einzugeben
//Die Funktion gibt die Adresse der FILE-Struktur mit den Steuerdaten der
//geöffneten Datei zurück. Schlägt das Öffnen der Datei fehlt, wird die
//NULL-Adresse zurückgegeben und eine entsprechende Meldung ausgegeben. 


FILE* OeffneTxtDat(const char* szModus);
////////////////////////////////////////////////////////////////////////////
//Öffnet eine Datei in dem Modus, der im Parameter szModus übergeben wird
//Der Modus kann jeder in der Sprache C mögliche Modus sein
//Der Nutzer wird aufgafordert, den Dateinamen ohne Erweiterung einzugeben
//Die Funktion hängt die Erweiterung '.txt' an den vom Nutzer eingegebenen
//Darteinamen an.
//Die Funktion gibt die Adresse der FILE-Struktur mit den Steuerdaten der
//geöffneten Datei zurück. Schlägt das Öffnen der Datei fehlt, wird die
//NULL-Adresse zurückgegeben, und eine entsprechende Meldung ausgegeben. 

void DblFldAusgabe(double dFld[], const char* szFmt, int nAnz, int nZeile);
////////////////////////////////////////////////////////////////////////////
//Die Funktion gibt die Werte double-Feldes dFld verteilt auf mehrere
//Zeilen mit dem in szFmt übergebenen Format aus. In nAnz wird die Anzahl
//der auszugebenen Werte übergeben, in nZeile steht wieviel Zahlen maximal
//in einer Zeile ausgegeben werden.

void DblFldAusgPositiv(double dFld[], const char* szFmt, int nAnz, int nZeile);
///////////////////////////////////////////////////////////////////////////////
//Die Funktion gibt die positiven Werte double-Feldes dFld verteilt auf mehrere
//Zeilen mit dem in szFmt übergebenen Format aus. Statt negativer Feldwerte
//gibt die Funktion Sterne aus. In nAnz wird die Anzahl der auszugebenen Werte
//übergeben, in nZeile steht wieviel Zahlen maximal in einer Zeile ausgegeben 
//werden.


int IntervallEingabe(const char* szKommentar, double** adFld);
////////////////////////////////////////////////////////////////////////////
//Die Funktion gibt den Eingabekommentar als einfach unterstrichene
//Zwischenüberschrift aus. Dann kann der Nutzer den von- umnd den bis-Wert 
//sowie die Schrittweite eingeben. Die Funktion berechnet die Anzahl der
//Intervallwerte und gibt diese Anzahl zurück

