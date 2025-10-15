//
// Created by matte on 08/10/2025.
//

#ifndef PROVA_CLASSECARTATTERI_H
#define PROVA_CLASSECARTATTERI_H

#endif //PROVA_CLASSECARTATTERI_H
#include<iostream>
#include<string>
using namespace std;


using namespace std;
class ListaCaratteri{
    protected:
    struct Nodo {
        char nome;
        Nodo *succ;
        Nodo* prec;
    };

    Nodo* testa;
    Nodo* coda;
    public:
    ListaCaratteri() {
        coda=new Nodo;
        coda=NULL;
        testa=new Nodo;
        testa = NULL;
    }


    ~ListaCaratteri() {
        delete coda;
        delete testa;
    }

    /* inserisci il carattere c , se fine = true inserisci in coda altrimenti inserisci in testa
     * char c -> carattere da inserire
     * bool fine -> se true inserisci c in coda , altrimenti in testa
     *
     */
     void inserisci(char c, bool fine) {
        Nodo* nuovo = new Nodo;
        nuovo->succ=NULL; // riempio il nuovo nodo di coda
        nuovo->nome=c;
        if (testa!=NULL) { // se la lista non è vuota

            Nodo* aux ;
            if (fine) { // allora inserisci in coda

                if (testa->succ!=NULL) {// se la testa non è l'ultimo elemneto allora coda=testa
                    aux=coda;
                    nuovo->succ=NULL;
                    aux->succ=nuovo; // nuovo ha il nuovo valore e punta a Null
                    nuovo->prec=coda; // aggiorno il valore del precedente
                    coda=nuovo; // salvo la posizione della coda



                }else {// se la testa è l'unico elemento
                    testa->succ=nuovo; // nuovo ha il nuovo valore e punta a Null
                    nuovo->prec=testa; // aggiorno il valore riferito all'elemento precedente
                    coda=nuovo; // mi salvo la posizione della coda nel momento della creazione di quest'ultima
                }

            }else { // inserisci in testa tenere conto testa unico elemento

                nuovo->succ=testa;
                testa->prec=nuovo; // aggiorno il valore riferito al nodo precedente
                testa=nuovo;
            }

        }else{// la lista è vuota
            testa= nuovo;
            coda=testa;
            // con un unico elemento prec punta ancora a null
        }
    }


    /* Rimuove il primo carattere = c , se tutti è true rimuove tutti i successivi elementi = c di qeulla lista
     * char c -> lettera interessata
     * bool tutti -> se true elimina tutte le lettere = c
     * @return true se almeno un carattere viene rimosso
     */
    bool rimuovi(char c, bool tutti) {
        if (testa!=NULL) {// se la lista contiene qualcosa
            Nodo* aux;
            Nodo* precedente ;
            aux=testa;
            if (tutti) { // vanno rimossi tutti
                bool rimosso=false;
                precedente=aux;
                do {
                    if (aux->nome == c) {// se la lettera è quella giusta
                        if (precedente==aux) { // è la prima iterazione
                            testa=testa->succ; // rimozione ex nodo testa
                            testa->prec=NULL; // impostato a nulla perchè è la testa
                            aux=testa;          // imposto aux e precedente per cominciare da una nuova testa
                            precedente=testa;
                            // non incremento aux visto che è stata creata una nuova testa
                            rimosso=true;
                        }else { // non ci riferiamo alla testa
                            if (aux==coda) { // se l'elemento in questione è l'ultimo della lista
                                precedente->succ=NULL; // rimuovo l'ultimo elemento
                                coda->prec=NULL; // impostato a null per evitare che venga recuperato
                                coda=precedente;

                                rimosso= true;
                            }else { // se non è ne primo ne ultimo
                                precedente->succ=aux->succ; // rimozione di un nodo
                                aux->prec=NULL; // per non farlo recuperare neanche provando
                                aux=aux->succ; // incremento
                                aux->prec=precedente; // collegato al nodo precedente
                                rimosso= true;
                            }
                        }
                        if (aux->succ==NULL) break; // per uscire dal ciclo quando viene analizzato l'ultimo nodo


                    }else {
                        if (aux->succ==NULL) { // per uscire dal ciclo quando viene analizzato l'ultimo nodo
                        break;
                        }
                        aux=aux->succ; // incremento se non viene riconosciuta la lettera in quella posizione
                    }

                    if (precedente->succ!=aux && precedente->succ!=aux->succ) precedente=precedente->succ; // se non è la prima iterazione devo far andare avanti anche il precedente

                } while (true);


                if (rimosso) return true; // almeno un elemento rimosso
                return false ;  // elemento non appartenente alla lista

            }else { // viene rimosso solo il primo

                precedente=aux;
                do { // do while per permettere di analizzare anche il contenuto dell'ultimo elemento della lista

                    if (aux->nome == c) { // rimuove elemento
                        if (precedente==aux) {
                            // primo ciclo iterativo
                            testa=testa->succ;
                            testa->prec=NULL;

                            precedente->succ=NULL; // rimozione ex testa
                            aux->succ=NULL;
                            return true;
                        }else{ // aux punta già al successivo
                            if (aux==coda) { // se l'elemento in questione è l'ultimo della lista
                                precedente->succ=NULL; // rimuovo l'ultimo elemento
                                coda=precedente;
                                aux->prec=NULL; // non servirebbe ma per far si che non venga riprestinato lo metto a null
                                return true;
                            }else { // se non è ne primo ne ultimo
                                precedente->succ=aux->succ; // rimozione di un nodo
                                aux->prec=NULL; // per non farlo recuperare
                                aux=aux->succ; // possibile causa errore
                                aux->prec=precedente; // linkato al precedente
                                return true;
                            }

                        }

                    }// passa alla prossima iterazione
                    if (aux->succ==NULL) { // per uscire dal ciclo quando viene analizzato l'ultimo nodo
                        break;
                    }
                    aux=aux->succ;
                    if (precedente->succ!=aux&&precedente->succ!=aux->succ) precedente=precedente->succ;// incremento solo se siamo alla seconda iterazione , per lasciare andare avanti aux

                } while (true);


                return false ;  // elemento non appartenente alla lista
            }

        }else { // se la lista è vuota
            return false;
        }
    }

    /* stampa lista
     *
     */
    void stampaLista() {
        cout<<"stampo la lista : ...."<<endl;
        Nodo* aux;
        aux=testa;
        if (testa!=NULL) {
            if (testa->succ!=NULL) {
                for (int i = 0 ; aux->succ!=NULL; i++) { // non stampa l'elemento con coda verso null
                    cout<<aux->nome<<" -> ";
                    aux = aux->succ;

                }
                cout<<aux->nome<<" -> @"<<endl;

            }else {
                cout<<aux->nome<<" -> @"<<endl;

            }

        }else {
            cout<<"-> @"<<endl;
        }

    }


    /*stampa lunghezza della lista
     *
     *
     */
    int lunghezza() {
        if (testa!=NULL) {
            if (testa->succ!=NULL) {
                int i=1; // parte da uno per contare elementi lista
                Nodo* aux=testa;
                for (i;aux->succ!=NULL; i++ ) {
                    aux=aux->succ;
                }
                if (aux==coda) {
                    return i;
                }
            }
            return 1;
        }
        return 0;
    }

    bool controllaPalindroma() {
        if (testa!=NULL) {
            if (testa->succ!=NULL) {
                Nodo* Taux=testa;
                Nodo* Caux=coda;
                for (int i=0; i<int(lunghezza()/2); i++) {
                    if (Taux->nome!=Caux->nome) {
                        return false;
                    } // altrimenti va avanti finche non ne trova due diversi
                    Caux=Caux->prec; // si mandano avanti i contatori
                    Taux=Taux->succ;
                } return true; // se esce dal ciclo significa che sono uguali/ speculati / palindromi
            }return true; // un solo elemento
        }return false; // lista vuota
    }




    /*sovraccarico dell'operatore << per permettere la stampa della lista
     *
     *
     */
    friend ostream& operator<<(ostream& os, ListaCaratteri& lc) {
        Nodo* aux;
        if (lc.testa!=NULL) {
            aux=lc.testa;

            if (lc.testa->succ!=NULL) {
                for (int i = 0 ; aux->succ!=NULL; i++) { // non stampa l'elemento con coda verso null
                    os<<aux->nome<<" -> ";
                    aux = aux->succ;

                }
                os<<aux->nome<<" -> @"<<endl;

            }else {
                os<<aux->nome<<" -> @"<<endl;

            }

        }else {
            os<<"-> @"<<endl;
        }
        return os;
    }


    /*sovrccarico dell'operatore per invertire la llista
     *
     *
     */
    friend void operator~(ListaCaratteri& lc) {
        if (lc.testa!=NULL) {
            if (lc.testa->succ!=NULL) {
                // faccio partire due indici, uno che parte dlla coda uno che parte dalla testa
                Nodo* precTesta=lc.testa;
                Nodo* succCoda=lc.coda;


                char appoggio;
                for (int i=0; i<int(lc.lunghezza()/2) ; i++) {

                    appoggio=precTesta->nome;       // scambio i
                    precTesta->nome=succCoda->nome; // nomi dei
                    succCoda->nome=appoggio;        // due puntatori
                    precTesta=precTesta->succ;     // mando avanti il contatore che parte dalla testa
                    succCoda=succCoda->prec;       // mando avanti il contatore che parte dalla coda
                }
            }
        }
    }



    /* sovracarico dell'operatore ==
     *confronto tra due liste
     * ritorna true se sono della stessa lunghezza e nello stesso ordine
     *
     */
    friend bool operator ==(ListaCaratteri lc, ListaCaratteri& lc1) {
        if (lc.lunghezza()==lc1.lunghezza()) { // se le lunghezze sono uguali
            if (lc.testa!=NULL && lc1.testa!=NULL) { // se le liste sono vuote
                if (lc.testa->succ!=NULL && lc1.testa->succ!=NULL) {// se le teste non sono l'unico elemento
                    int i=1;;
                    Nodo* aux=lc.testa;
                    Nodo* aux1=lc1.testa;
                    for (i; aux->succ!=NULL; i++ ) {
                        if (aux->nome!=aux1->nome) return false;
                        aux=aux->succ;
                        aux1=aux1->succ;
                    }
                    // se esce dal cilo allora sono tutti uguali
                    return true;

                }// se le teste sono l'unico elemento verifico che siano uguali
                if (lc.testa->nome==lc1.testa->nome) return true;
                return false;            }
        } // se le lunghezze sono diverse
        return false;
    }
};