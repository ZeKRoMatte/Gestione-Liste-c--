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
            risposta='n';
            while (risposta!='y'&&risposta!='Y') {
                cout<<"inserisci carattere da immettere nella lista : ";
                cin>>ch;
                do {
                    cout<<endl<<"insrimento in testa o in coda t/c ?"<<endl;
                    cin>>risposta;
                }while(risposta!='t'&&risposta!='c'&&risposta!='T'&&risposta!='C');
                switch(risposta) {

                    case 't': case 'T' :
                        lc.inserisci(ch,false);
                        break;
                    case 'c':  case 'C' :
                        lc.inserisci(ch,true);
                        break;
                    default :
                        cout<<"Illegal input"<<endl;
                }
                do {
                    cout<<"vuoi uscire (y//n) ?";
                    cin>>risposta;
                } while (risposta!='y'&&risposta!='n'&&risposta!='Y'&&risposta!='N');


            }
            lc.stampaLista();
            if (lc.rimuovi('a',false)) {
                cout<<"almeno un elemento rimosso "<<endl;
                lc.stampaLista();
            }


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

            while (exit==false){
                do{
                    cout<<"1) stampa"<<endl<<"2) rimuovi e stampa "<<endl<<"3) rimuovi tutti e stampa"<<endl<<"4) reinserisci 3 valori"<<endl<<"5) inserisci nuova lista e confronta con precedente"<<endl<<"6) confronta le due liste"<<"7) DISTRUGGI TUTTE"<<endl<<endl<<"8) esci"<<endl<<endl;
                    cin>>risposta;
                }while (risposta!='1'&&risposta!='2'&&risposta!='3'&&risposta!='4'&&risposta!='5'&&risposta!='6'&&risposta!='7');
                switch (risposta) {
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
                        lc2.lunghezza();



                        break;
                    case '6':
                        if (lc==lc2) {
                            cout<<"liste uguali"<<endl;
                        }else {
                            cout<<"liste diverse"<<endl;
                        }
                        break;
                    case '7':
                        delete lc;
                        delete lc2;
                        break;
                    case '8':
                        exit=true;
                        cout<<"Ciao bro";
                        break;
                    default:
                        cout<<"Illegal input"<<endl;
                }
            }

            break;



    }







}