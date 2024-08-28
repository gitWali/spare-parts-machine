#include <iostream>
#include <unistd.h>		//Für die Sleep funktion um das Wechselgeld verzögert anzuzeigen.

using namespace std;	//Namensraum

int main() 		//Hauptfunktion
{
	
	cout << "--------------------------------------- Ersatzteileautomat -------------------------------------------------- \n";		//Designelement
	cout <<"\n";	//Sedignelement.
	cout << "Ich kann leider nur 0.2 Euro, 0.5 Euro, 1 Euro und 2 Euro Münzen annehmen! Bitte akzeptieren \n";	//Ausgabe, welche Münzen der Automat annehmen kann.
	cout <<"\n";	//Sedignelement.
	
	int Wahl , Menge;	//Variable deklarieren.
	double wechselgeld;	//Vaiable deklatieren.
	double Preis [6] = { 11 , 9.80 , 15.40 , 7.80 , 2.30 , 5.40 };
	char choice;
	do{
		cout << " \n ------------------------------- verfuegbare Ersatzteile mit Materialkosten in Euro -------------------------------- \n\n";	//Ausgabe, was alles an dem Automaten erwerbbar ist.
		cout << "| ----------------------------------------------------------------------------------------------------------------------  | \n";	//Designelement
		cout << "Nummer zum waehlen: \n";	//Ausgabe, dass die Wahlzahlen folgen.
		cout << "|   1   |       2     |         3        |          4        |        5       |              6                   		   | \n";	//Die Wahlzahlen
		cout << "| ----------------------------------------------------------------------------------------------------------------------- | \n";	//Designelement
		cout << "| ----------------------------------------------------------------------------------------------------------------------- | \n";	//Designelement
		cout << "| Kuehler | Kupplungsseil | 5l Kanister Benzin |Scheibenwichblätter |OIL-Deckel Motor |Schluesselangänger-Werner Edition- | \n";	//Die Gegenstände auflisten, welche zu erwerben sind.
		cout << "| ----------------------------------------------------------------------------------------------------------------------- | \n";	//Designelement
		cout << "|   11    |     9.80      |       15.40        |        7.80        |      2.30       |                5.40               | \n";	//den Preis, für welchen die Gegenstände zu erwerben sind.
		cout << "| ----------------------------------------------------------------------------------------------------------------------- | \n\n";		//Designelement
		
		cout << "Bitte waehlen Sie Ihr gewuenschtes ersatzteil aus ( 1 - 6 ) und bitte keine Buchstabeneingabe Tätigen ! : ";	//Eingabeaufforderung einer Auswahl des gegenstandes mit bemerkung, dass keine Buchstaben eingegeben Werden.
			cin >> Wahl;	//Die gewählte Gegenstandsnummer ( 1 - 6 ) einlesen
			
				while (Wahl < 1 || Wahl > 6 )	//Überprüfen, ob die Wahl in dem Bereich von 1 bis 6 liegt, wenn es nicht der Fall ist dann:
				{
					cout <<" Ihre Eingabe ist ungueltig! Bitte pruefen. Danke \n";	//folgt eine Ausgabe, dass eine ungültige eingabe vorhanden ist.
						cin >> Wahl;	
				}
				
		 
		if (Wahl >= 1 && Wahl <= 6 )	//wenn eine Ersatzteilenummer von 1 - 6 gewählt wurde folgt:
		{
			cout << "Wie viele Ersatzteile der nummer " << Wahl << " Wollen Sie haben? ";	//Die eingegebene Nummer ausgeben und fragen, wie viele Teile er davon haben möchte.
				cin >> Menge;	//Die eingegebene Menge einlesen.
			
			cout << "Bitte werfen Sie den erforderlichen Betrag ein: " << Preis [ Wahl - 1 ] * Menge <<  " Euro \n";	//Aufforderung das Wechselgeld einzuwerfen.
			
			double Geldeinwurf = 0;	//Den Geldeinwurf auf 0€ setzen.
			double eingeworfenesgeld; //Variable für bisher eingeworfenes Geld erstellen.
			
			while ( Geldeinwurf < Preis[Wahl - 1 ] * Menge ) //eine Schleife, solange bis der Preis des Produktes erreicht wurde.
			{
				cout << " Bitte werfen Sie eine Muenze ein ( 0.2 , 0.5 , 1 , 2 ) : ";	//Aufforderung für den Einwurf der Münzen.
					cin >> eingeworfenesgeld;	//Die eingeworfenen Münzen einlesen.
				
				if (eingeworfenesgeld == 0.2 || eingeworfenesgeld == 0.5 || eingeworfenesgeld == 1 || eingeworfenesgeld == 2) 	//if abfrage, wenn das einwurfgeld == 0.2 , 0.5 , 1 , 2 ist dann:
				{
	                	Geldeinwurf += eingeworfenesgeld;	//Auf den aktuell schon eingeworfenen betrag draufrechnen und : 
	                cout << "Aktueller Geldbetrag: " << Geldeinwurf << " Euro \n";	//Ausgabe des aktuell eingeworfenen Betrags.
	            }
	            else //sonst soll eine Ausgabe getaetigt werden, dass eine ungültige Münze eingeworfen wurde:
				{
	                cout << "\n Ungueltige Muenze! Bitte werfen Sie nur 0.2 Euro, 0.5 Euro, 1 Euro oder 2 Euro Münzen ein. \n\n";	//Ausgabe, dass eine Ungültige Münze eingeworfen wurde.
	            }   
			} 
			 
			
			cout << "Ihr Wechselgeld wird derzeit berechnet. Bitte warten. Danke \n";	//Ausgabe, dass das Wechselgeld berechnet wird.
						
		sleep(3);		//Lässt die Ausgabe des Wechselgeldes um 3sec. verzögern und stellt es nicht sofotrt dar.
				wechselgeld = 0;	//Wechselgeldbetrag auf 0 setzen.
			 	wechselgeld = Geldeinwurf - ( Preis [ Wahl - 1 ] * Menge ); 	//Das Wechselgeld berechnen, indem man den Betrag, welcher im Geldeinwurf ist   - den Preis * Stückzahl rechnet.
				cout << "Ihr Wechselgeld betraegt: " << wechselgeld << " Euro. \n";	//Ausgabe des Wechselgeldes.
				
				cout << "Moechten Sie den Rechner erneut verwenden? (j/n): \n ";		//Abfrage, ob das Programm erneut ausgeführt werden soll.
	        	cin >> choice;		//Einlesen der Eingabe.
				
		    	if (choice == 'n' || choice == 'N')		//Wenn die Wahl n oder N ist dann:
		    	{
		    		cout << "Schoenen Tag Ihnen noch! \n"; //Wird das Vorhaben mit der Nachricht: "Schönen Tag ihnen noch! beendet.
		    		return 0;
				}
		}
	}
				
					while(choice != 'j' || choice != 'J' || choice != 'n' || choice != 'N' );
					{
						cout <<" Bitte eine Korrekte eingabe Tätigen. \n";	//Ausgabe, dass etwas bei der eingabe von j , J / n , N  nicht stimmt.
					}
				
			
				return 0;
		
}
	
