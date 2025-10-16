#include <iostream>
#include<cstdlib>
#include "ClasseCartatteri.h"
using  namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    ListaCaratteri lc;
    ListaCaratteri lc2;

    char ch, risposta='n';
    do {
    cout<<"Modalità standard o veloce (s/v)"<<endl;
    cin>>risposta;;
    }while (risposta!='s'&&risposta!='S'&&risposta!='v'&&risposta!='V');

    switch(risposta) {
        case 's': case 'S':
            cout<<"--- PRIMA PARTE ---"<<endl
            <<"Lista iniziale vuota :"<<lc<<endl;
            lc.inserisci('a',true);
            lc.inserisci('b',true);
            lc.inserisci('c',true);

            cout<<"Dopo l'inserimento in coda (a, b, c) :"<<lc<<endl;
            lc.inserisci('z',false);

            cout<<"Dopo l'inserimento in testa (z) :"<<lc<<endl;
            cout<<"Rimozione caratteri : 110"<<endl;
            cout<<"Dopo la rimozione :"<<lc<<endl;
            lc.rimuovi('z',true);
            lc.rimuovi('a',true);
            lc.rimuovi('b',true);
            lc.rimuovi('c',true);
            lc.inserisci('a',true);
            lc.inserisci('c',true);
            lc.inserisci('e',true);
            lc.inserisci('c',true);
            lc.inserisci('a',true);
            lc.inserisci('r',true);



            cout<<"Lista prima della rimozione dei caratteri 'a' e 'c' : "<<lc<<endl;
            lc.rimuovi('a',true);
            lc.rimuovi('c',true);

            cout<<"Rimuovi tutti i caratteri 'a' e 'c' :"<<lc;
            cout<<"--- SECONDA PARTE ---"<<endl;
            break;

        case 'v': case 'V':
            int conta=0;
            bool exit = false;
            while (conta<3) {
                cout<<"inserisci lettera "<<conta<<endl;
                cin>>ch;
                lc.inserisci(ch,false);
                conta++;
            }
            if (lc.controllaPalindroma()) {
                cout<<"la lista e palindroma"<<endl;

            }else {
                cout<<"lista non palindroma"<<endl;
            }
            while (exit==false){
                do{
                    cout<<"1) stampa \t"<<"2) rimuovi e stampa "<<endl
                    <<"3) rimuovi tutti e stampa \t"<<"4) reinserisci 3 valori + check palindromo"<<endl
                    <<"5) inserisci nuova lista e confronta con precedente"<<endl
                    <<"6) confronta le due liste\t"<<"7) inverti lista 1"<<endl
                    <<"8) cerca sottostringa 2 in sottostringa 1 \t"<<"9) estrai n ultimo carattere e stampa valore del puntatore"<<endl
                    <<"0) esci"<<endl;
                    cin>>risposta;
                }while (risposta!='1'&&risposta!='2'&&risposta!='3'&&risposta!='4'&&risposta!='5'&&risposta!='6'&&risposta!='7'&&risposta!='8'&&risposta!='9'&& risposta!='0');
                switch (risposta) {
                    case '0':
                        exit=true;
                        cout<<"Ciao bro";
                        break;
                    case '1':
                        // lc.stampaLista();
                        cout<<lc;
                        cout<<"lunghezza :"<<lc.lunghezza()<<endl;
                        break;
                    case '2':
                        cout<<"inserisci carattere ";
                        cin>>ch;
                        if (lc.rimuovi(ch,false)) {
                            cout<<"elemento rimosso "<<endl;
                            lc.stampaLista();
                        }else {
                            cout<<"nessun elemento rimosso"<<endl;
                        }
                        break;
                    case '3':
                        cout<<"inserisci carattere ";
                        cin>>ch;
                        if (lc.rimuovi(ch,true)) {
                            cout<<"elementi rimossi "<<endl;
                            lc.stampaLista();
                        }else {
                            cout<<"nessun elemento rimosso"<<endl;
                        }
                        break;
                    case '4':
                        conta=0;
                        while (conta<3) {
                            cout<<"inserisci lettera "<<conta<<endl;
                            cin>>ch;
                            lc.inserisci(ch,false);
                            conta++;
                        }
                        if (lc.controllaPalindroma()) {
                            cout<<"la lista e' palindroma"<<endl;

                        }else {
                            cout<<"lista non palindroma"<<endl;
                        }
                        break;

                    case '5':
                        conta=0;
                        while (conta<3) {
                            cout<<"inserisci lettera "<<conta<<endl;
                            cin>>ch;
                            lc2.inserisci(ch,false);
                            conta++;
                        }
                        lc2.stampaLista();
                        cout<<"lunghezza :"<<int(lc2.lunghezza())<<endl;



                        break;
                    case '6':
                        if (lc==lc2) {
                            cout<<"liste uguali"<<endl;
                        }else {
                            cout<<"liste diverse"<<endl;
                        }
                        break;
                    case '7':
                        ~lc;
                        cout<<lc;
                        // delete lc;
                        // delete lc2;
                        break;
                    case '8':
                        if (lc.cercaSottostringa(lc2)) {
                            cout<<"sottostringa trovata "<<endl;
                        }else cout<<"sottostringa non trovata "<<endl;
                        break;
                    case '9':
                        int n;
                        cout<<"inserisci n"<<endl;
                        cin>>n;
                        if (char* result= lc.estraiNultimoCarattere(n); result!=NULL) {
                            cout<<"carattere trovato e rimosso :"<<result<<endl;
                        }else cout<<"carattere non trovato"<<endl;
                        break;
                    default:
                        cout<<"Illegal input"<<endl;
                }
            }

            break;



    }







}