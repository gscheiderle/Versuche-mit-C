#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

titel(void);
float auswahl(void);
float muenzEinwurf(float);
int muenzKontrolle(float);

int main() {

int kontrollen;

titel();
float preise=auswahl();
kontrollen=muenzKontrolle(preise);


return 0;
}


// Titel
titel (void) {

printf("GETRÄNKE-AUTOMAT\n\n");

printf("Bitte wählen Sie Ihr Getränk aus\n(durch Eingabe der entspr. Nummer.)\n\n");

printf("1) Wasser (0.50 Euro)\n");
printf("2) Limonade (1.20 Euro)\n");
printf("3) Bier (2.30 Euro)\n");

printf("\n\n");

}

//////////////////////////////////////////////////////////////////////////////////////////////////


// Getränke-Auswahl treffen
float auswahl(void) {

int getraenk=0;
char temp;
float preis;
float einwuerfe;
float einwurf;


printf("Geben Sie hier die Getränke-Nr. ein:");
scanf("%d%c", &getraenk, &temp);

switch(getraenk) {
	case 1: printf("gewählt: WASSER\n"),
	        preis=0.50;printf("Preis 50 Cent\n"); break;
	case 2: printf("gewählt: LIMONADE\n"),
	        preis=1.20;printf("Preis: 1.20 Euro\n"); break;
	case 3: printf("gewählt: BIER\n"),
	        preis=2.30;printf("Preis: 2.30 Euro\n"); break;
    default: printf("Bitte zahlen Sie %0.2f Euro \n", preis); break;
}

return (preis);
}


/////////////////////////////////////////////////////////////////////////////////////////////////


float muenzEinwurf(float einwurf) {

float preise;
float einwuerfe;
int kontrolle=0;

    einwurf=einwurf*100;

if ( einwurf == 5  ||
     einwurf == 10  ||
     einwurf == 20  ||
     einwurf == 50  ||
     einwurf == 100  ||
     einwurf == 200 ||
     einwurf == 0
)
{
  einwurf = einwurf / 100;
  kontrolle=1;
  ;
}

if ( kontrolle == 0 ) {
        einwurf = 0.0;
        printf("Das war eine FALSCHE Münze !");
      }

return einwurf;
}


////////////////////////////////////////////////////////////////////////////////////////////


muenzKontrolle(float preise) {

int kontrolle;
char temp;
float einwurf=0.00;
float einwurf_2=0.00;
float einwuerfe;
float einwuerfe_2=0.00;
float ergebnisMinus=0.0;
float ergebnisPlus=0.0;


printf("\nWerfen Sie hier Ihre Muenze ein:");
scanf("%f%c", &einwurf, &temp);

einwuerfe=muenzEinwurf(einwurf);

do {

if ( einwurf == 0 ) {
    printf("Sie haben den Vorgang abgebrochen\nund erhalten %.2f Euro zurück", einwuerfe);
           return 0;
}

if ( einwuerfe < preise ) {
     ergebnisMinus=preise-einwuerfe;

	 printf("\nEs fehlen noch %0.2f Euro.\nWerfen Sie Ihre Münzen hier ein: \n\n", ergebnisMinus);
	 scanf("%f%c", &einwurf, &temp);

einwuerfe_2=muenzEinwurf(einwurf);{

        einwuerfe+=einwuerfe_2;
        }
}

if ( einwuerfe > preise ) {
     ergebnisPlus = einwuerfe - preise;
    }
}
while( einwuerfe < preise );
	  {

	  if(einwuerfe == preise) {
            printf("\nVielen Dank, bitte entnehmen Sie Ihr Getraenk.\n\n");
      }

      if(ergebnisPlus > 0 ) {
            printf("\nSie haben %0.2f Euro zu viel bezahlt.\nWie Sie wissen, wechselt der Automat nicht.\nVielen Dank!\nBitte entnehmen Sie Ihr Getraenk.\n\n", einwuerfe-preise);
      }
   }
}





