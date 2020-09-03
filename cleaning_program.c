/* Ajank�ytt�ohjelma siivousfirma Putsikselle
 *
 * (c) Markus Nivasalo / 2014
 *
 * Ohjelmaan sy�tet��n siivottavien wc-tilojen lukum��r� sek� n�iden neli�m��r� ja likaisuusaste.
 * Sitten sy�tet��n siivottavien keitti�iden m��r� sek� n�iden neli�m��r�.
 * T�m�n j�lkeen sy�tet��n siivottavien toimistojen lukum��r�, toimistojen neli�m��r� sek� yhden
 * toimistoneli�n siivoamiseen k�ytett�v� aika. K�yt�v�t k�sitell��n samalla tavalla kuin toimistot.
 * N�ill� tiedoilla ohjelma palauttaa jokaiseen jokaisen siivottavan tilan siivousajan, siivoukseen kuluvan
 * kokonaisajan, sek� tiedon siit�, montako kokop�iv�ist� ja osa-aikaista ty�ntekij�� tarvitaan.
 * 
 * Lis�ksi ohjelma luo lopuksi tiedoston 'tulokset.txt' minne se tallettaa siivoukseen kuluvan ajan sek� 
 * tarvittavien ty�ntekij�iden m��r�n my�hemminkin luettavaksi.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int wcLaskuri(int laskuri); // Laskee vessojen siivoukseen k�ytett�v�n ajan
int keittioLaskuri(int laskuri); // Laskee keitti�iden siivoukseen k�ytett�v�n ajan
int toimistoLaskuri(int laskuri, int nelioAika); // Laskee toimistojen siivoukseen k�ytett�v�n ajan
int kaytavaLaskuri(int laskuri, int nelioAika); // Laskee k�yt�vien siivoukseen k�ytett�v�n ajan
int tulokset(int wcValinta, int keittioValinta, int toimistoValinta, int kaytavaValinta,
             int wcTaulukko[], int keittioTaulukko[], int toimistoTaulukko[], int kaytavaTaulukko[]); // Laskee ja ilmoittaa lopullisen siivousajan sek� tarvittavan m��r�n ty�ntekij�it�

int main(){
    
    int wcAika;
    int wcValinta;
    int wcTaulukko [1000];
    
    int keittioValinta;
    int keittioAika;
    int keittioTaulukko [1000];
    int nelioAika;
    
    int toimistoValinta;
    int toimistoNelio;
    int toimistoAika;
    int toimistoTaulukko [1000];
    
    int kaytavaValinta;
    int kaytavaNelio;
    int kaytavaAika;
    int kaytavaTaulukko [1000];
    
    int laskuri;
    int laskuri2 = 0;
    int laskuri3 = 1;
    
    char testaaja;

    printf("Anna siivottavien wc-tilojen lukumaara > ");
    while(scanf("%d%c",&wcValinta,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        
        printf("Anna siivottavien wc-tilojen lukumaara > ");
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    
    for (laskuri = 1; laskuri <= wcValinta; laskuri++) {
    
        wcAika = wcLaskuri(laskuri);
        wcTaulukko[laskuri2] = wcAika;
        laskuri2++;
        
    }
    
    laskuri2 = 0; // Nollataan laskuri2 huonetyyppien v�liss�
    
    printf("Anna siivottavien keittioiden lukumaara > ");
    while(scanf("%d%c",&keittioValinta,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        printf("Anna siivottavien keittioiden lukumaara > ");
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    
    for (laskuri = 1; laskuri <= keittioValinta; laskuri++) {
        
        keittioAika = keittioLaskuri(laskuri);
        keittioTaulukko[laskuri2] = keittioAika;
        laskuri2++;
        
    }
    
    laskuri2 = 0; // Nollataan laskuri2 huonetyyppien v�liss�
    
    printf("Anna siivottavien toimistojen lukumaara > ");
    while(scanf("%d%c",&toimistoValinta,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        printf("Anna siivottavien toimistojen lukumaara > ");
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    paluu2:
    printf("Anna toimiston nelion siivoamiseen kaytetty aika (min. 50sek) > ");
    while(scanf("%d%c",&nelioAika, &testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        printf("Anna toimiston nelion siivoamiseen kaytetty aika (min. 50sek) > ");
        if(testaaja == '\n') {
            scanf("%c",&testaaja);
        }
        else
        {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    
    if (nelioAika < 50) {
        goto paluu2;
    }
    
    for (laskuri = 1; laskuri <= toimistoValinta; laskuri++) {
        
        toimistoAika = toimistoLaskuri(laskuri, nelioAika);
        toimistoTaulukko[laskuri2] = toimistoAika;
        laskuri2++;
        
    }
    
    laskuri2 = 0; // Nollataan laskuri2 huonetyyppien v�liss�
    

    printf("Anna siivottavien kaytavien lukumaara > ");
    while(scanf("%d%c",&kaytavaValinta,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        printf("Anna siivottavien kaytavien lukumaara > ");
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    paluu3:
    printf("Anna kaytavanelion siivoamiseen kaytetty aika (min. 50sek) > ");
    while(scanf("%d%c",&nelioAika, &testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        printf("Anna kaytavanelion siivoamiseen kaytetty aika (min. 50sek) > ");
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else
        {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    if (nelioAika < 50) {
        goto paluu3;
    }
    
    for (laskuri = 1; laskuri <= kaytavaValinta; laskuri++) {
        
        kaytavaAika = kaytavaLaskuri(laskuri, nelioAika);
        kaytavaTaulukko[laskuri2] = kaytavaAika;
        laskuri2++;
        
    }
    
    tulokset(wcValinta, keittioValinta, toimistoValinta, kaytavaValinta, wcTaulukko, keittioTaulukko, toimistoTaulukko, kaytavaTaulukko);
    
    printf("\nLopullinen siivousaika seka tarvittavien tyontekij�iden maara on talletettu tiedostoon 'tulokset.txt'. Paina mita tahansa lopettaaksesi ohjelman.");
    
    getch(0);
    
    return(0);
}

/* wcLaskuri-funktio laskee vessojen siivoamiseen k�ytett�v�n ajan. Se saa ainoana arvonaan funktion ulkopuolelta
   arvon 'laskuri', joka on main-funktiossa for-loopin laskuri. K�yt�nn�ss� 'laskuri' arvo py�rii wcLaskurissa
   vessojen m��r�n�, jotta ohjelma printtaisi aina oikean vessan numeron, esim: 

   printf("Anna wc[%d] neli�maara > ", laskuri);
   
   Funktio itsess��n kysyy k�ytt�j�lt� vessojen neli�m��r�t sek� likaisuusasteet, ja laskee t�m�n perusteella
   siivoamiseen k�ytetyn ajan, ja palauttaa sen lopulta main-funktioon. Funktio testaa molemmat sy�tetyt arvot
   ja mik�li ne eiv�t ole numeroita, se kysyy ne uudelleen.

   */

int wcLaskuri(int laskuri) {
    
    int puhdasWC = 60;
    int normaaliWC = 90;
    int likainenWC = 180;
    int aika;
    int neliot;
    int likaisuus;
    int tulos;
    char testaaja;
    
    printf("Anna wc[%d] neliomaara > ", laskuri);
    while(scanf("%d%c",&neliot,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        
        printf("Anna wc[%d] neliomaara > ", laskuri);
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    paluu:
    printf("Anna wc[%d]likaisuusaste\n      1 = Puhdas, 2 = Normaali, 3 = Likainen > ", laskuri);
    while(scanf("%d%c",&likaisuus,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        
        printf("Anna wc[%d]likaisuusaste\n      1 = Puhdas, 2 = Normaali, 3 = Likainen > ", laskuri);
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    
    if (likaisuus == 1) {
        aika = neliot * puhdasWC;
    }
    else if (likaisuus == 2) {
        aika = neliot * normaaliWC;
    }
    else if (likaisuus == 3) {
        aika = neliot * likainenWC;
    }
    else {
        goto paluu;
    }

    
    return(aika);
    
}

/* Keitti�laskurin toteutus aikalailla samanlainen kuin wc-laskurilla. Erona l�hinn� se, ett� neli�iden
   siivoamiseen k�ytett�v� aika arvotaan v�lilt� 80 - 100 rand:lla.

   Funktio laskee keitti�iden siivoamiseen k�ytetyn ajan kertomalla 'nelioAika' arvon annetulla neli�m��r�ll�.
   Lopuksi funktio palauttaa siivoamiseen k�ytetyn ajan main-funktioon.*/

int keittioLaskuri(int laskuri) {
    
    int aika;
    int neliot;
    int nelioAika;
    char testaaja;
    
    srand(time(NULL));
    
    nelioAika = 80 + rand()%20;
    
    printf("Anna keittio[%d] neliomaara > ", laskuri);
    while(scanf("%d%c",&neliot,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        
        printf("Anna keittio[%d] neliomaara > ", laskuri);
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    
    aika = neliot * nelioAika;  
    
    return(aika);
    
}

/* toimistoLaskuri-funktio laskee toimistojen siivoamiseen k�ytett�v�n ajan. Se saa main-funktiosta
   huoneen numeron kertovan laskuri-arvon. 

   Funktio itsess��n kysyy k�ytt�j�lt� siivottavan toimiston neli�m��r�n ja kertoo t�m�n aikaisemmin saadulla
   neli�n siivoamiseen kuluvalla ajalla ja saa n�in huoneen siivoamisen kuluvan ajan. T�m�n j�lkeen aika palautetaan
   main-funktioon. */

int toimistoLaskuri(int laskuri, int nelioAika) {
    
    int aika;
    int neliot;
    char testaaja;
    
    printf("Anna toimisto[%d] neliomaara > ", laskuri);
    while(scanf("%d%c",&neliot,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        
        printf("Anna toimisto[%d] neliomaara > ", laskuri);
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    
    aika = nelioAika * neliot;
    
    return(aika);
    
}

/* k�yt�v�Laskuri-funktio laskee toimistojen siivoamiseen k�ytett�v�n ajan. Se toimii t�sm�lleen samalla tavalla
   kuin toimistoLaskuri-funktio. Se saa main-funktiosta huoneen numeron kertovan laskuri-arvon.

   Funktio itsess��n kysyy k�ytt�j�lt� siivottavan k�yt�v�n neli�m��r�n ja kertoo t�m�n aikaisemmin saadulla
   neli�n siivoamiseen kuluvalla ajalla ja saa n�in huoneen siivoamisen kuluvan ajan. T�m�n j�lkeen aika palautetaan
   main-funktioon. */


int kaytavaLaskuri(int laskuri, int nelioAika) {
    
    int aika;
    int neliot;
    char testaaja;
    
    printf("Anna kaytava[%d] neliomaara > ", laskuri);
    while(scanf("%d%c",&neliot,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan ett� integer
        
        printf("Anna kaytava[%d] neliomaara > ", laskuri);
        if(testaaja == '\n')
            scanf("%c",&testaaja);
        else {
            while(testaaja != '\n')
                scanf("%c",&testaaja);
        }
    }
    
    aika = nelioAika * neliot;
    
    return(aika);
    
}

/* tulokset-funktio laskee lopulliset tulokset ohjelmalle ja ilmoittaa ne. Se saa kaikki aikaisemmin lasketut tarvittavat tiedot ja palauttaa jokaisen
   huoneen siivoamiseen kuluvan ajan, eri huonetyyppeihin kuluvan kokonaisajan, sek� siivoukseen kaikkiaan yhteens� kuluvan ajan. Lopuksi funktio laskee
   montako kokop�iv�ist� ja montako osap�iv�ist� ty�ntekij�� siivoukseen tarvitaan ja ilmoittaa t�m�n.

   T�m�n lis�ksi funktio luo tiedoston 'tulokset.txt' josta t�rkeimm�t tiedot ovat luettavissa my�hemminkin.*/


int tulokset(int wcValinta, int keittioValinta, int toimistoValinta, int kaytavaValinta, int wcTaulukko[], int keittioTaulukko[], int toimistoTaulukko[], int kaytavaTaulukko[]) {
    
    FILE *tulokset;
    
    int wcTotal = 0; // Vessojen kokonaissiivousaika
    int keittioTotal = 0; // Keitti�iden kokonaissiivousaika
    int toimistoTotal = 0; // Toimistojen kokonaissiivousaika
    int kaytavaTotal = 0; // K�yt�vien kokonaissiivousaika
    int kokonaisaikaSekunti; // Siivoukseen kuluva aika sekunteina
    int kokonaisaikaTunti; // Siivoukseen kuluva aika tunteina
    int kokopaiva; // Kokop�iv�inen ty�ntekij�
    int osaAika; // Osa-aikainen ty�ntekij� -laskuri
    
    int laskuri;
    int laskuri2 = 1;
    
    printf("\n");
    printf("______________________________________________________________\n");
    for (laskuri = 0; laskuri < wcValinta; laskuri++) {
        printf("wc[%d] siivousaika = %d sekuntia\n", laskuri2, wcTaulukko[laskuri]);
        laskuri2++;
        wcTotal = wcTotal + wcTaulukko[laskuri];
    }
    printf("wc-tilojen siivousaika yhteens� = %d sekuntia\n", wcTotal);
    
    laskuri2 = 1;
    printf("\n");
    for (laskuri = 0; laskuri < keittioValinta; laskuri++) {
        printf("keittio[%d] siivousaika = %d sekuntia\n", laskuri2, keittioTaulukko[laskuri]);
        laskuri2++;
        keittioTotal = keittioTotal + keittioTaulukko[laskuri];
    }
    printf("keittiotilojen siivousaika yhteensa = %d sekuntia\n", keittioTotal);
    
    laskuri2 = 1;
    printf("\n");
    for (laskuri = 0; laskuri < toimistoValinta; laskuri++) {
        printf("toimisto[%d] siivousaika = %d sekuntia\n", laskuri2, toimistoTaulukko[laskuri]);
        laskuri2++;
        toimistoTotal = toimistoTotal + toimistoTaulukko[laskuri];
    }
    printf("toimistotilojen siivousaika yhteensa = %d sekuntia\n", toimistoTotal);
    
    laskuri2 = 1;
    printf("\n");
    for (laskuri = 0; laskuri < kaytavaValinta; laskuri++) {
        printf("kaytava[%d] siivousaika = %d sekuntia\n", laskuri2, kaytavaTaulukko[laskuri]);
        laskuri2++;
        kaytavaTotal = kaytavaTotal + kaytavaTaulukko[laskuri];
    }
    printf("kaytavien siivousaika yhteensa = %d sekuntia\n", kaytavaTotal);
    printf("______________________________________________________________\n");
    
    kokonaisaikaSekunti = wcTotal + keittioTotal + toimistoTotal + kaytavaTotal;
    kokonaisaikaTunti = kokonaisaikaSekunti / 60;
    
    printf("\nYHTEENSA:   %d h\n", kokonaisaikaTunti);
    
    kokopaiva = kokonaisaikaTunti / 6; // Lasketaan kokop�iv�isten ty�ntekij�iden m��r� perus jakolaskulla
    osaAika = kokonaisaikaTunti % 6; // Lasketaan osap�iv�isten ty�ntekij�iden m��r� jakoj��nn�ksell�.
    
    /* Mik�li jakoj��nn�st� ei j��, ilmoitetaan ainoastaan tarvittavat kokop�iv�iset siivoojat. Mik�li jakoj��nn�st� j��, ilmoitetaan tarvittavat osap�iv�isetkin. 
       T�ss� vaiheessa my�s luodaan tiedosto 'tulokset.txt' ja talletetaan sinne t�rkeimm�t tiedot luettavaksi my�hemminkin. */
    
    if (osaAika > 0) {
        
        printf("\nTyontekijatarve on siis %d kokopaivaista siivoojaa seka yksi osapaivainen siivooja (tyo-aika %dh / paiva).\n", kokopaiva, osaAika);
        
        tulokset = fopen("tulokset.txt", "w");
    
        fprintf(tulokset, "Siivoukseen kuluva aika on siis yhteensa %d tuntia.\n\nTyontekijatarve on siis %d kokopaivaista siivoojaa seka yksi osapaivainen siivooja (tyo-aika %dh / paiva).\n", kokonaisaikaTunti, kokopaiva, osaAika);
        fclose(tulokset);
        
    }
    else {
        
        printf("\nTyontekijatarve on siis %d kokopaivaista siivoojaa.\n", kokopaiva);
        
        tulokset = fopen("tulokset.txt", "w");
    
        fprintf(tulokset, "Siivoukseen kuluva aika on siis yhteensa %d tuntia.\n\nTyontekijatarve on siis %d kokopaivaista siivoojaa.\n", kokonaisaikaTunti, kokopaiva);
        fclose(tulokset);
    }
        
    
    
    return(0);
}
