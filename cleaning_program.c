/* Ajankäyttöohjelma siivousfirma Putsikselle
 *
 * (c) Markus Nivasalo / 2014
 *
 * Ohjelmaan syötetään siivottavien wc-tilojen lukumäärä sekä näiden neliömäärä ja likaisuusaste.
 * Sitten syötetään siivottavien keittiöiden määrä sekä näiden neliömäärä.
 * Tämän jälkeen syötetään siivottavien toimistojen lukumäärä, toimistojen neliömäärä sekä yhden
 * toimistoneliön siivoamiseen käytettävä aika. Käytävät käsitellään samalla tavalla kuin toimistot.
 * Näillä tiedoilla ohjelma palauttaa jokaiseen jokaisen siivottavan tilan siivousajan, siivoukseen kuluvan
 * kokonaisajan, sekä tiedon siitä, montako kokopäiväistä ja osa-aikaista työntekijää tarvitaan.
 * 
 * Lisäksi ohjelma luo lopuksi tiedoston 'tulokset.txt' minne se tallettaa siivoukseen kuluvan ajan sekä 
 * tarvittavien työntekijöiden määrän myöhemminkin luettavaksi.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int wcLaskuri(int laskuri); // Laskee vessojen siivoukseen käytettävän ajan
int keittioLaskuri(int laskuri); // Laskee keittiöiden siivoukseen käytettävän ajan
int toimistoLaskuri(int laskuri, int nelioAika); // Laskee toimistojen siivoukseen käytettävän ajan
int kaytavaLaskuri(int laskuri, int nelioAika); // Laskee käytävien siivoukseen käytettävän ajan
int tulokset(int wcValinta, int keittioValinta, int toimistoValinta, int kaytavaValinta,
             int wcTaulukko[], int keittioTaulukko[], int toimistoTaulukko[], int kaytavaTaulukko[]); // Laskee ja ilmoittaa lopullisen siivousajan sekä tarvittavan määrän työntekijöitä

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
    while(scanf("%d%c",&wcValinta,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
        
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
    
    laskuri2 = 0; // Nollataan laskuri2 huonetyyppien välissä
    
    printf("Anna siivottavien keittioiden lukumaara > ");
    while(scanf("%d%c",&keittioValinta,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
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
    
    laskuri2 = 0; // Nollataan laskuri2 huonetyyppien välissä
    
    printf("Anna siivottavien toimistojen lukumaara > ");
    while(scanf("%d%c",&toimistoValinta,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
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
    while(scanf("%d%c",&nelioAika, &testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
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
    
    laskuri2 = 0; // Nollataan laskuri2 huonetyyppien välissä
    

    printf("Anna siivottavien kaytavien lukumaara > ");
    while(scanf("%d%c",&kaytavaValinta,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
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
    while(scanf("%d%c",&nelioAika, &testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
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
    
    printf("\nLopullinen siivousaika seka tarvittavien tyontekijöiden maara on talletettu tiedostoon 'tulokset.txt'. Paina mita tahansa lopettaaksesi ohjelman.");
    
    getch(0);
    
    return(0);
}

/* wcLaskuri-funktio laskee vessojen siivoamiseen käytettävän ajan. Se saa ainoana arvonaan funktion ulkopuolelta
   arvon 'laskuri', joka on main-funktiossa for-loopin laskuri. Käytännössä 'laskuri' arvo pyörii wcLaskurissa
   vessojen määränä, jotta ohjelma printtaisi aina oikean vessan numeron, esim: 

   printf("Anna wc[%d] neliömaara > ", laskuri);
   
   Funktio itsessään kysyy käyttäjältä vessojen neliömäärät sekä likaisuusasteet, ja laskee tämän perusteella
   siivoamiseen käytetyn ajan, ja palauttaa sen lopulta main-funktioon. Funktio testaa molemmat syötetyt arvot
   ja mikäli ne eivät ole numeroita, se kysyy ne uudelleen.

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
    while(scanf("%d%c",&neliot,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
        
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
    while(scanf("%d%c",&likaisuus,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
        
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

/* Keittiölaskurin toteutus aikalailla samanlainen kuin wc-laskurilla. Erona lähinnä se, että neliöiden
   siivoamiseen käytettävä aika arvotaan väliltä 80 - 100 rand:lla.

   Funktio laskee keittiöiden siivoamiseen käytetyn ajan kertomalla 'nelioAika' arvon annetulla neliömäärällä.
   Lopuksi funktio palauttaa siivoamiseen käytetyn ajan main-funktioon.*/

int keittioLaskuri(int laskuri) {
    
    int aika;
    int neliot;
    int nelioAika;
    char testaaja;
    
    srand(time(NULL));
    
    nelioAika = 80 + rand()%20;
    
    printf("Anna keittio[%d] neliomaara > ", laskuri);
    while(scanf("%d%c",&neliot,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
        
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

/* toimistoLaskuri-funktio laskee toimistojen siivoamiseen käytettävän ajan. Se saa main-funktiosta
   huoneen numeron kertovan laskuri-arvon. 

   Funktio itsessään kysyy käyttäjältä siivottavan toimiston neliömäärän ja kertoo tämän aikaisemmin saadulla
   neliön siivoamiseen kuluvalla ajalla ja saa näin huoneen siivoamisen kuluvan ajan. Tämän jälkeen aika palautetaan
   main-funktioon. */

int toimistoLaskuri(int laskuri, int nelioAika) {
    
    int aika;
    int neliot;
    char testaaja;
    
    printf("Anna toimisto[%d] neliomaara > ", laskuri);
    while(scanf("%d%c",&neliot,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
        
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

/* käytäväLaskuri-funktio laskee toimistojen siivoamiseen käytettävän ajan. Se toimii täsmälleen samalla tavalla
   kuin toimistoLaskuri-funktio. Se saa main-funktiosta huoneen numeron kertovan laskuri-arvon.

   Funktio itsessään kysyy käyttäjältä siivottavan käytävän neliömäärän ja kertoo tämän aikaisemmin saadulla
   neliön siivoamiseen kuluvalla ajalla ja saa näin huoneen siivoamisen kuluvan ajan. Tämän jälkeen aika palautetaan
   main-funktioon. */


int kaytavaLaskuri(int laskuri, int nelioAika) {
    
    int aika;
    int neliot;
    char testaaja;
    
    printf("Anna kaytava[%d] neliomaara > ", laskuri);
    while(scanf("%d%c",&neliot,&testaaja) != 2 || testaaja != '\n') { // Varmistetaan että integer
        
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
   huoneen siivoamiseen kuluvan ajan, eri huonetyyppeihin kuluvan kokonaisajan, sekä siivoukseen kaikkiaan yhteensä kuluvan ajan. Lopuksi funktio laskee
   montako kokopäiväistä ja montako osapäiväistä työntekijää siivoukseen tarvitaan ja ilmoittaa tämän.

   Tämän lisäksi funktio luo tiedoston 'tulokset.txt' josta tärkeimmät tiedot ovat luettavissa myöhemminkin.*/


int tulokset(int wcValinta, int keittioValinta, int toimistoValinta, int kaytavaValinta, int wcTaulukko[], int keittioTaulukko[], int toimistoTaulukko[], int kaytavaTaulukko[]) {
    
    FILE *tulokset;
    
    int wcTotal = 0; // Vessojen kokonaissiivousaika
    int keittioTotal = 0; // Keittiöiden kokonaissiivousaika
    int toimistoTotal = 0; // Toimistojen kokonaissiivousaika
    int kaytavaTotal = 0; // Käytävien kokonaissiivousaika
    int kokonaisaikaSekunti; // Siivoukseen kuluva aika sekunteina
    int kokonaisaikaTunti; // Siivoukseen kuluva aika tunteina
    int kokopaiva; // Kokopäiväinen työntekijä
    int osaAika; // Osa-aikainen työntekijä -laskuri
    
    int laskuri;
    int laskuri2 = 1;
    
    printf("\n");
    printf("______________________________________________________________\n");
    for (laskuri = 0; laskuri < wcValinta; laskuri++) {
        printf("wc[%d] siivousaika = %d sekuntia\n", laskuri2, wcTaulukko[laskuri]);
        laskuri2++;
        wcTotal = wcTotal + wcTaulukko[laskuri];
    }
    printf("wc-tilojen siivousaika yhteensä = %d sekuntia\n", wcTotal);
    
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
    
    kokopaiva = kokonaisaikaTunti / 6; // Lasketaan kokopäiväisten työntekijöiden määrä perus jakolaskulla
    osaAika = kokonaisaikaTunti % 6; // Lasketaan osapäiväisten työntekijöiden määrä jakojäännöksellä.
    
    /* Mikäli jakojäännöstä ei jää, ilmoitetaan ainoastaan tarvittavat kokopäiväiset siivoojat. Mikäli jakojäännöstä jää, ilmoitetaan tarvittavat osapäiväisetkin. 
       Tässä vaiheessa myös luodaan tiedosto 'tulokset.txt' ja talletetaan sinne tärkeimmät tiedot luettavaksi myöhemminkin. */
    
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
