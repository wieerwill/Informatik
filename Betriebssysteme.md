---
title: Betriebssysteme
date: Wintersemester 20/21
author: Robert Jeutter
---

# Einführung
worauf es ankommt:
- Korrektheit
- Sicherheit
- Verfügbarkeit
- Skalierbarkeit
- Echtzeitfähigkeit
- Robustheit
- Sparsamkeit

## Extrem breites Anwendungsspektrum
- funktionale Eigenschaften
  - Authentisierung, Verschlüsselung
  - Fahrzeug/Verkehrsmanagement
  - Informationsmanagement
  - Kommunikationsmanagement
- nichtfunktionale Eigenschaften
  - Sicherheit
  - Korrektheit
  - Echtzeitfähigkeit
  - Skalierbarkeit
  - Offenheit
  - Sparsamkeit
  - Verfügbarkeit
  - Robustheit

mit vielen Gemeinsamkeiten
- Architekturprinzipien
- Programmierparadigmen

voller individueller Strategien mit teils konfligierenden Zielen
- Performanz $\leftrightarrow$ Robustheit 
- Echtzeitfähigkeit $\leftrightarrow$ Effizienz

$\Rightarrow$ spezialisierte Betriebssystem-Familien1. Einführung

## Funktionale und nicht-Funktionale Eigenschaften
Beispiel Essen: 
- funktionale Eigenschaft: es soll satt machen
- nichtfunktional: Geschmack, Aussehen,...

### Funktionale Eigenschaften (= Funktionen, Aufgaben)
- Betriebssysteme: sehr komplexe Softwareprodukte
- Ein Grund für diese Komplexität: besitzen Reihe von Aufgaben - also funktionale Eigenschaften
- Hauptaufgaben dabei:
  1. Verwalten der Resourcen des Systems (Hard-u. Software-Ressourcen) 
  2. Transformation der „hässlichen“ Hardwareschnittstellen in angenehme nutzerfreundliche Schnittstelle (Betriebssystem als „Erweiterung“ der Maschine, auch Hardware + BS = „virtuelle Maschine“)
  3. Dabei für beide Aufgaben: Schaffung sinnvoller Abstraktionen(Prozess, Datei,... $\rightarrow$ Softwareressourcen)

### Nichtfunktionale Eigenschaften
Wie - mit welchen speziellen weiteren Eigenschaften sollen die funktionalen Eigenschaften realisiert werden. Z.B. schon genannt:
- Echtzeitfähigkeit: Betriebssystem-Komponenten, -Algorithmen usw. mit solchen Eigenschaften realisieren, dass Betriebssystem insgesamt echtzeitfähig ist
- Robustheit: Betriebssystem-Komponenten, -Algorithmen usw. mit solchen Eigenschaften realisieren, dass Betriebssystem insgesamt robust ist
- usw

## Blick in Betriebssystem-Zoo
- Mainframe Betriebssystem
  - performante E/A
  - Massendatenverarbeitung
- Server Betriebssystem
  - viele Klienten, permanente Kommunikation
  - Web Server, Fileshare
- Parallelrechner Betriebssystem
  - Number Crunching, parallele Algorithmen mit hohem Rechenbedarf
  - schnelle IPC
- Desktop/Laptop Betriebssystem
  - Interaktivität/Responsivität
- Echtzeit Betriebssystem
  - Einhaltung zeitlicher Garantien, Safety
  - Fahrzeug-, Anlagensteuerung
- Eingebettete Systeme
  - in Fahrzeugen, Kaffeemaschinen, Telefonen...
  - z.T. Spezialaufgaben

## Grundbegriffe 
- Wo sind Betriebssysteme zu finden?
- Welches Spektrum decken sie ab?
- Welche Arten von Betriebssystemen gibt es?
- Welche funktionalen und nichtfunktionalen Eigenschaften spielen dabei eine Rolle?

# Prozessormanagement: Prozesse und Threads
## Grundsätzliches
1. Computer bearbeiten Aufgaben in wohldefinierten Arbeitsabläufen (beschrieben durch Programme/Algorithmen)
2. bei abarbeitung von Programmen entstehen oft Wartesituationen
3. Wartezeiten sind ~ relativ zur Prozessorgeschwindigkeit ~ gigantisch (1 Sek ~ 10 Milliarden Prozessorzyklen)
4. statt zu warten, lässt sich besseres tun (parallele Ausführung mehrerer Aufgaben)
5. Parallelität geht nicht immer (vorraussetzung Nebenläufigkeit)

Begriffe
1. Aktivitäten heißen nebenläufig, wenn zwischen ihnen keine kausalen abhängigkeiten bestehen
2. Aktivitäten heißen parallel, wenn sie zeitlich überlappend druchgeführt werden


> Definition Prozess: Ein Prozess ist eine Abstraktion zur vollständigen Beschreibung einer sequenziell ablaufenden Aktivität

parallele Aktivitäten werden repräsentiert durch parallele Prozesse

> Prozess = betriebssystem-Abstraktion zur Ausführung von programmen

> Prozessmodelle: definieren konkrete Prozesseigenschaften

> Prozessmanagement: Komponente eines Betriebssystems, die Prozessmodell dieses Betriebssystems implementiert

> Aufgabe: präzise Definition der Betriebssystem-Abstraktion "Prozess"
(definiert durch Semantik und nichtfunktionale Eigenschaften; implementiert durch Datenstrukturen/Algorithmen)

> Prozesserzeugung: Erzeugen einer Programmablaufumgebung

## Prozesserzeugung
### Was geschieht bei der Prozesserzeugung
1. Prüfen notwendiger Vorraussetzungen (Rechte, Ressoucenverfügbarkeit,...)
2. Namensvergabe und "Stammbaumpflege"
3. Allokation von Ressourcen (Arbeitsspeicher, Prozessorzeit)
4. Anlegen von Managementstrukturen (belegte Ressourcen, Laufzetmanagement)

### Prozesserzeugung: notwenige Vorraussetzungen
1. Rechte: zur Prozesserzeugung und Ressourcenallokation (Kontingente)
2. Ressourcenverfügbarkeit (Arbeitsspeicher, Rechenzeit, Kommunikation)
3. Sicherheit (Authentizität und Integrität des auszuführenden Programms)
4. bei Echtzeitbetriebssystem
    - Erfüllung von Ressourcenanforderung
    - Einhaltung gegebener Garantien
5. Fairness (Quoten)
6. robustheit/Überlastvermeidung (Lastsituation)

### Prozesserzeugung: Namensvergabe
Identifikation ist positive ganze Zahl durch Vergabe Algorithmus. Kann nach Terminierung eines Prozesses erneut vergeben werden
- eindeutig: zu einem Zeitpunkt bzgl aller existierenden Prozesse
- nicht unbedingt eindeutig: für zeitlich nicht überlappende Prozesse
- erst recht nicht eindeutig: über Systemgrenze hinweg

### Prozesserzeugung: Stammbaumpflege
Abstammungsbeziehung: definieren Eltern/Kind Hierarchie
1. Prozess erzeugt weitere Prozesse: Kinder
2. diese wiederum erzeugen weitere Prozesse usw
-> baumartige Abstammungshierarchie
Nutzung: Rechte und Verantwortlichkeiten

Verwaiste Prozesse -> Adoption (durch Urprozess)

### Prozesserzeugung: Allokation (Zuordnung) von Ressourcen
1. Arbeitsspeicher
   1. Größe: Wie viel Arbeitsspeicher benötigt der Prozess?
   2. Zeitpunkt: zu welchem Zeitpunkt? Echtzeiteigenschaften (Planbarkeit) oder Performanz (proaktivität)?
   3. Isolation: wie ist er geschützt? (Robustheit, Sicherheit, Korrektheit)
2. Prozessorzeit
   1. in Prozessmodellen echtzeitfähiger Systeme: Größe und Zeitpunkt
   2. in Prozessmodellen ohne diese Eigenschaften: dynamisches ad-hoc-Scheduling

für richtige Initialisierung: präzise Formatvereinbarung zwischen
- Linker (Programmdatei-Produzent)
- Prozessmanagement des BS (Programmdatei Nutzer)

1. das a.out-Format (veraltet; ursprünglich Unix Format)
2. das Mach Object File Format (Mach-O; heutiger Standard für OS X, iOS)
3. das Executable and Link(age/able) Format (ELF; heutiger Linux standard)

### Prozesserzeugung: Management Datenstrukturen
Buchführung über sämtliche zum management notwendigen Informationen
- Prozessidentifikation
- Rechtemanagement
- Speichermanagement
- Prozessormanagement
- Kommunikationsmanagement

a. Prozessdeskriptor (process control block ~ PCB)
b. Prozessdeskriptortabelle: Deskriptioren sämtlicher Prozesse

| Prozessormanagement (Prozessdeskriptor) | |
| Identifikation | eindeutige Prozessbezeichnung; einordnung in Abstammungshierarchie |
| Scheduling | Informationen für Schedulingalgorithmen |
| Prozessorkontext | gesichert bei Verdrängung des Prozesses, restauriert bei Reaktivierung |
| Ereignismanagement | what if... |
| Accounting (Kontoführung) | zur Prioritätsbestimmung, Statisik, kostenberechnung |
| Virtueller Adressraum | Beschreibung des Speicherlayouts | 
| Kernel Stack | Prozedurmanagement innerhalb des BS | 
| Rechtemanagement | |
| Allgemeines Ressourcenmanagement | Filedeskriptoren, Socketdeskriptoren,... |

### Aktionen des Prozessmanagements
- Prüfen notweniger Vorraussetzungen
- Namensvergabe und Stammbaum
- Allokation von Ressourcen
- Anlegen von Managementdatenstrukturen (Prozessdeskriptor)

### Prozessterminierung
durch
- Aufgabe erledigt
- Fehler aufgetreten
- durch Nutzer/Eigentümer geschlossen
- ...

1. Freigabe der Ressourcen
2. Benachrichtigung der "Eltern"
3. Adoption der "Kinder"

## Threads
Naive Lösung: für jede nebenläufige Aktivität einen Prozess erstellen. Jedoch hat ein Prozess:
- Kosten des Managements
- kosten der isolation
- Kosten der Kommunikation

$\rightarrow$ Parallelität mittels Prozessen ist teuer (revidiertes Prozessmodell)

Daher suche nach kostengünstigerem Modell zur Parallelisierung nebenläufiger Aktivitäten

> Definition Prozess: Ein (Multithread-) Prozess ist eine vollständige Beschreibung einer ablaufenden Aktivität. Dazu gehört insbesondere 
> 1. Das ablaufende Programm
> 2. zugeordnete Betriebsmittel
> 3. Rechte
> 4. prozessinterne parallele Aktivitäten (Threads) und ihre Bearbeitungszustände

> Definition Thread: ist eine sequenzielle Aktivität im Betriebsmittelkontext (d.h. innerhalb) eines Prozesses

parallele Aktivitäten innerhalb eines Prozesses werden durch parallele Threads repräsentiert.

Anmerkung:
1. **Eigentümer von Ressourcen und Rechten** sind immer noch prozesse
2. das **Programm eines Prozesses** kann nun Code für mehr als eine sequenzielle Aktivität enthalten
3. **Gegenstand der Prozesszuteilung** sind nun Threads
4. das **ursprüngliche Prozessmodell** ist eine Spezialisierung dieses Modells (ein Prozess mit genau einem Thread)
5. ein **Prozessdescriptor** (PCB) eines Multithread-Prozessmodells enhält alle Informationen des PCBs eines Single-Thread-Prozessmodells plus Informationen über alle seine Threads
6. ein **TCB** enthält lediglich den Threadszustand und den Ablaufkontext

Threads werden daher oft als *Leichtgewichtprozesse* bezeichnet


Threads treten in verschiedenen Varianten auf
1. komfortabel (integriert in Programmiersprache)
2. "zu Fuß" (durch Bibiliotheken oder API)

Implementierungsebenen
1. Prozessmodell des Betriebssystems ist Multithread Modell
   - Thread Implementierung im Betriebssystem
   - das Betriebssystem hat Kenntnis über Threads
   - Kernel Level Threads (KLTs)
2. Prozessmodell des Betriebssystems ist Single-Thread-Modell
   - Thread Implementierung auf Anwendungsebene
   - nur auf Endbenutzer-Ebene ist Kenntnis über Threads
   - User Level Thread (ULTs)

| Pro KLT | Pro ULT |
| Performanz durch Parallelität | Performanz durch geringen Overhead |
| Nutzung von Mehrprozessor/Mehrkernarchitektur | Thread Management ohne Systemaufrufe | 
| ein blockierender Systemaufruf in einem Thread blockiert nicht auch gleichzeitig alle anderen Threads des gleichen Prozesses | Thread Umschaltung ohne Mitwirkung des Betriebssystems |
| | Individualität: anwendungsindividuelle Thread Schedulingstrategien möglich | 
| | Portabilität | 

es gibt Work-Arounds: alle gefährlichen Systemaufrufe einpacken (in Pakete)

Wahl zwischen ULT- und KLT hängt ab von:
1. Vorraussetzung: Prozessmodell des Betriebssystems Multithread Modell?
2. Anwendungsprofil: E/A-Profil, Parallelität, Portabilität, Individualität

# Scheduling
## Das Problem
Anzahl der Aktivitäten >> Anzahl der Prozessoren
- nicht alle können gleichzeitig arbeiten
- eine Auswahl muss getroffen werden
- Auswahlstrategie: Schedunling-Strategie/Algorithmus
- die Betriebssystem Komponente Scheduler
- Ziel: Effizientes Ressourcenmanagement

Threads können
- aktiv sein (besitzt einen Prozessor)
- rechenbereit sein (Bsp. hätte gerne einen Prozessor)
- kurzfristig warten (Bsp. benötigt keinen Prozesoor aber Arbeitsspeicher)
- langfristig warten (Bsp. benötigt länger keinen Prozessor/Arbeitsspeicher)

Threadzustände im 3/5-Zustandsmodell
- bereit: kann aktiv werden, sobald Prozessor frei wird
- aktiv: besitzt einen Prozessor, arbeitet
- blockiert: wartet auf Ereignis (Timer Ablauf,...)
- frisch: erzeugt, Betriebsmittel/Rechte zum Ablauf fehlen noch
- beendet: Betriebsmittel in der Freigabephase

Folge: effizientes Ressourcenmanagement benötigt präzise Informationen über Threadzustände.

## Aufgabe der Zustandsmodelle
Beschreibung:
- des Ablaufzustands von Threads (aktiv/bereit/wartend)
- der mögliche Zustandsübergänge (z.B. bereit->aktiv)

Nutzung
- jeder Thread ist zu jedem Zeitpunkt in genau einem dieser Zustände
- jeder Thread wechselt seinen Zustand gemäß der im Modell definierten Zustandsübergänge, hervorgerufen durch z.B. Zuteilung eines Prozessors
- Ressourcenmanagement: nutz Zustand als Informationsquelle für Entscheidungen

Beschreibungsmittel: endliche deterministische Automaten
- Menge der annehmbaren Zustände ist endlich
- Folgezustand ist immer eindeutig bestimmt

## Scheduleraktivierung
Wann wird die letzte Scheduling-Entscheidung überprüft?
1. Prozess/Thread erzeugung (neuer, rechenbereiter Thread)
2. Threadterminierung, Threadblockierung (ein Prozessor wird frei)
3. Ereigniseintritt (Thread wird rechenbereit)
4. Wechsel von Prioritäten (in prioritätenbastierten Schedulingalgorithmen)
5. periodisch (in zeitscheibenbasierten Schedulingalgorithmen)

Ein Kontextwechsel umfasst:
- bei Wechsel zwischen Threads desselben Prozesses
  - Stackkontext
  - Prozessorregister
  - floating point unit (hohe Kosten) (FPU)
- zusätzlicher Wechsel zwischen Threads verschiedener Prozesse
  - Speicherlayout (sehr hohe Kosten)
- starke Auswirkungen auf
  - Gesamtperformanz
  - Reaktivität
  - Echtzeiteigenschaften

Kostenfaktor FPU
- Kopieren des FPU-Kontexts: sehr viele Register (sofortkosten)
  - Realisierung: "faul"
  - Hardware hilft: FPU Protextion
- Auswirkung
  - nur ein THread benutzt FPU: tatsächliches Sichern erfolgt nie
  - wenige Threads benutzen FPU: tatsächliches Sichern minimiert

## Scheduling Strategien
Strategische Ziele
- abhängig vom Einsatzfeld eines Betriebssystems
  - Echtzeitsysteme: Einhaltung von Fristen
  - interaktive Systeme: Reaktivität
  - Serversysteme: Reaktivität, E/A-Performanz
  - Batch-Verarbeitungssysteme: Durchsatz
- ergänzt durch allgemeine Ziele
  - Fairness: Threads bekommen einen fairen Anteil an Rechenzeit
  - Lastbalancierung: alle Systemkomponenten (CPUs, Speicher, E/A-Peripherie) sind gleichmäßig ausgelastet
  - Overhead: z.B. wenig Prozesswechsel
- Ausbalancierung mehrerer Ziele
  - multikriterielle Optimierungsaufgabe, i.d.R. NP-vollständig
  - heuristische Scheduling-Algorithmen

Typische Muster aktiver Threadphasen:
- CPU lastig (mathematische Berechnung, Verschlüsselung,...)
- E/A lastig (interaktiver Prozess, ...)
- periodische Last (Echtzeitvideoverarbeitung, ...)
- chaotische Last (server mit inhomogenen Diensten)

Differenzierte Scheduling-Strategien
- nutzen Wissen über Lastmuster zur Optimierung, z.B.
  1. Einhaltung von Fristen
  2. Minimierung der Thread/Prozesswechsel

### Batch-System („Stapelverarbeitungs“-System)
- Aufträge: in Gruppen („Stapel“) eingeteilt u. so verarbeitet
- Abarbeitung: ohne aktive Mitwirkung eines Benutzers (Gegensatz: interaktiv)
- ursprünglich: frühe Entwicklungsstufe von Betriebssystemen

Ziele hier
1. Auslastung teurer Betriebsmittel (i.d.R. Maximierung der CPU-Auslastung)
2. Minimierung der Scheduling-Kosten (wenig Prozesswechsel, kurze Laufzeit des Scheduling-Algorithmus)
3. Maximierung des Durchsatzes (erledigte Arbeit / Zeit)

zwei der bekannteren:
1. First Come, First Served (FCFS)
   - in Reihenfolge, in der Threads rechenbereit werden
   - extrem einfache Strategie, guter Durchsatz
   - nicht immer sehr klug
2. Shortest Remaining Time Next (SRTN)
   - Prozessor erhält Thread mit voraussichtlich kürzester Restrechenzeit
   - preemptiv* ) , d.h. Threads können von konkurrierenden Threads verdrängt werden
   - (Schätzwert über) Restlaufzeit muss vorliegen

### Interaktives System
- Benutzer: kann bei Programmabarbeitung in Aktivitäten des Computers eingreifen
- Abarbeitung: mit aktiver Mitwirkung eines Benutzers (Gegensatz: batch processing)
- fortgeschrittenere Betriebssystem-Technik

Ziele hier
1. Minimierung von Reaktionszeiten (subjektiver Eindruck von Performanz)
2. Fairness (mehrere Benutzer/Klienten)

Algorithmen: Round Robin Varianten
  - jeder Thread: bekommt ein gleich großes Teil „des Kuchens“: die Zeitscheibe
  - einfach zu implementieren (1 Warteschlange, Uhr)
  - geringe Algorithmuskosten (O(1): FIFO-Warteschlange, Ring)
  - schnelle Entscheidungen (O(1): Nr. 1 aus Warteschlange)
  - notwendiges Wissen gering (CPU-Nutzungsdauer des aktiven Threads)

#### Einbeziehung von Prioritäten
Ziel: Ausdrucksmöglichkeit der Wichtigkeit von Threads
1. niedrig: z.B.
  - Dämonen (die z.B. im Hintergrund Emails abrufen)
  - Putzarbeiten (z.B. Defragmentierung)
2. hoch: z.B.
  - auf Aufträge reagierende Threads (z.B. in Servern)
  - auf Benutzereingaben reagierende Threads (z.B. aktives Fenster einer GUI)
  - unter Echtzeitbedingungen arbeitende Threads (z.B. Motormanagement, DVD-Spieler)

Idee(n)
1. jeder Thread: erhält individuelle Priorität
2. Threads der höchsten Prioritäten: erhalten einen Prozessor
3. zwischen Threads gleicher Priorität: Round-Robin

viele Varianten dieses Schemas
- statische Prioritäten, z.B. in
  - planbaren Echtzeitsystemen (Autoradio: Reaktion auf Stationswechseltaste hat Vorrang vor Senderfeldstärkenüberwachung)
  - kommerziellen Rechenzentren (wer mehr zahlt, ist eher an der Reihe)
- dynamische Prioritäten, abhängig z.B. von
  - verbrauchter CPU-Zeit (Verhinderung der Dominanz)
  - E/A-Intensität
  - Wartegrund

### Schedulingziele in Echtzeitsystemen
Finden einer Bearbeitungsreihenfolge (ein „Schedule“),
- die Fristen einhält
- deren Berechnung ökonomisch ist (Kosten des Scheduling-Algorithmus)
- die selbst ökonomisch ist (Minimierung der Threadwechsel)
- die sich (evtl.) an wechselnde Lastmuster anpasst

Verbreitete Algorithmen
- EDF: früheste Frist zuerst (earliest deadline first)
  - für dynamische Lasten
  - wird ein Thread rechenbereit, so „nennt“ er seine nächste Deadline (Frist)
  - von allen bereiten Threads ist immer derjenige mit der frühesten Deadline aktiv (dringend=wichtig)
  - Folglich
    - arbeitet der Algorithmus mit dynamischen Prioritäten → adaptiv
    - ist die Thread-Priorität um so höher, je näher dessen Frist liegt
    - ist er preemptiv
  - Voraussetzung: kausale und zeitliche Unabhängigkeit der Threads (keine wechselseitige Blockierung)
- RMS: Raten-monotones Scheduling (rate-monotonic scheduling)
  - für periodische Lasten (z.B. Mischpult, DVD-Spieler, technische Prozesse)
  - wird ein Thread rechenbereit, so „nennt“ er seine Periodendauer
  - von allen bereiten Threads ist immer derjenige mit der kürzesten Periodendauer aktiv
  - Folglich:
    - arbeitet der Algorithmus mit statischen Prioritäten
    - ist die Thread-Priorität um so höher, je kürzer die Periodendauer ist
    - ist er preemptiv
  - Voraussetzung: periodische Threads; kausale und zeitliche Unabhängigkeit der Threads

## Zusammenfassung
Anzahl der Threads >> Anzahl der Prozessoren
- nicht alle können gleichzeitig rechnen
- eine Auswahl muss getroffen werden
- → Auswahlstrategie: Schedulingalgorithmen

# Privilegierungsebenen
Problematik: Anwendungsprozesse und Betriebssystem nutzen gemeinsame (Hardware-)Ressourcen

Schutz vor fehlerbedingten oder bösartigen räumlichen/zeitlichen Wechselwirkungen

2 Konzepte
1. private Adressräume
2. Zugriffsschutz auf Arbeitsspeicherbereiche

Verhinderung zeitlicher Wechselwirkungen
- Ursache: Prozesse geben freiwillig keine Prozessoren auf
- Umgang damit
  - periodische Aktivierungen preemptiver Scheduler (Uhr)
  - Scheduler-Aktivierungen durch asynchrone Ereignisse
- kritisch also: Operationen zum Abschalten von
  1. Uhr
  2. Ereignismanagement (s. Kap. 5.4)
- weitere kritische Operationen
  1. Veränderung des Speicherlayouts
  2. Veränderung kritischer Prozessorkontrollregister
  3. Zugriff auf E/A-Geräte
- notwendig: Schutz kritischer Operationen des Instruktionssatzes

Lösungskonzept: Privilegierungsebenen ablaufender Aktivitäten, z.B.
  - „kernel mode“ (≈ Betriebssystem-Modus)
  - „user mode“ (Nutzer-Modus)
- ermöglichen: Durchsetzung von Regeln:
  - „Nur eine im „kernel mode“ ablaufende Aktivität hat Zugriff auf ...“
- Privilegierungsebenen steuern Rechte ...
  1. zur Ausführung privilegierter Prozessorinstruktionen
  2. zur Konfiguration des Arbeitsspeicher-Layouts
  3. zum Zugriff auf Arbeitsspeicherbereiche
  4. zum Zugriff auf E/A-Geräte

Realisierung: abhängig von Prozessorarchitektur
- in Ringen 0 (höchste Priorität) bis 3 (niedrigste Priorität)

Implementierung: Hardware-Unterstützung
- aktuelle Privilegierungsebene ist
  - Teil des Prozessor-Statusregisters: „Current Privilege Level“ (CPL)
  - Grundlage der Hardware-Schutzmechanismen; permanente Überwachung
    - der ausgeführten Instruktionen
    - der Arbeitsspeicherzugriffe
    - der E/A-Peripheriezugriffe
- Modifikation des CPLs nur
  1. durch privilegierte Instruktionen
  2. bei Beginn und Abschluss
    - des Aufrufs von Systemdiensten
    - einer Ereignisbehandlung

Botschaften
- jede auf Privilegierungsebene < 3 ablaufende Aktivität hat Zugriff auf kritische Ressourcen
- jede auf Privilegierungsebene 0 ablaufende Aktivität hat Zugriff auf
  1. sämtliche Ressourcen eines Prozessors
    - sämtliche Instruktionen (z.B. HALT)
    - sämtliche Prozessorregister (z.B. Prozessor-Status-Register (PSR) )
  2. MMU-Register zur Arbeitsspeicherkonfiguration 
  3. sämtliche Register der E/A-Peripherie

Sämtliche Schutz- und Sicherheitsmechanismen von
- Anwendungsprozessen
- Betriebssystem
beruhen elementar auf 2 Bits: „Current Privilege Level“ (CPL) im Prozessor-Status-Register (PSR)


# Kommunikation und Synchronisation
## Elementare Konzepte
Beispiele:
- Aufträge an Geräte und (Dienstleistungs-)Prozesse, z.B.
- Kooperative Arbeit von Betriebssystem-Komponenten
- Arbeit verschiedener Betriebssystemkomponenten mit (gemeinsamen) Management-Datenstrukturen
- Interaktionen zwischen Anwendungsprozessen

Die Auftragstabelle ist eine (Software-)Ressource.
- Problem: ein Fehler entsteht dadurch, dass zwei (oder mehr) Prozesse oder Threads „durcheinander“ auf der Ressource arbeiten
- Lösung: Unkoordiniertes Arbeiten mit der Ressource muss verhindert werden!
Erst wenn ein Prozess (oder Thread) seine Arbeit mit der Ressource vollständig abgeschlossen hat, darf der nächste aktiv werden.
Die Befehlsfolge innerhalb der Prozesse, während deren Abarbeitung auf die Ressource zugegriffen wird, ist ein kritischer Abschnitt. 
- Außerdem: genauere Betrachtung eines einzelnen Auftrags; kann aus mehreren Komponenten bestehen
- Problem: durch „unkoordiniertes“ Arbeiten mehrerer Threads kann es auch bei den Auftrags-Einträgen zu Inkonsistenzen kommen

Fazit:
- Gesamte Arbeit an Auftragstabelle ist kritischer Abschnitt.
- Nur 1 Thread darf zu einem Zeitpunkt mit Auftragstabelle arbeiten.
- Erst wenn dieser Arbeit beendet hat, darf ein neuer Thread mit der Auftragstabelle arbeiten.

Definitionen:\\
Es gibt Ressourcen, die als ganzes oder bzgl. einzelner Operationen nur exklusiv, d.h. zu einem Zeitpunkt nur durch einen einzigen Thread nutzbar sind.
1. Eine Phase, in der ein Thread eine exklusive Operation auf einer Ressource ausführt, heißt kritischer Abschnitt.
2. Kritische Abschnitte erfordern den wechselseitigen Ausschluss (die Isolation) konkurrierender Threads bzw. Prozesse.

Beispiel 2: Kommunikation von 2 Prozessen über gemeinsamen Speicherbereich („Erzeuger-Verbraucher-Problem“)
- Problembeschreibung:
  - Ein Prozess schreibt Daten in den Speicherbereich ...
  - Der zweite Prozess liest diese Daten ...
  - Die Datenmenge ist so umfangreich, dass dieser Vorgang mehrmals (abstrahiert: unendlich oft) wiederholt werden muss.
- 1. Problem (Puffer voll, Puffer leer); unterschiedliche Geschwindigkeiten von Erzeuger und Verbraucher
- 2. Problem (Puffer wird gerade benutzt); gleichzeitiges Lesen und Schreiben des selben Pufferelements

## Algorithmen zum wechselseitigen Ausschluss
Genauere Definition des Problems (Annahmen)
1. konkurrierende Threads arbeiten asynchron, z.B. in einer unendlichen Schleife
2. dabei betreten und verlassen sie irgendwann einen kritischen Abschnitt
3. Betreten und Verlassen dieses Abschnitts: wird durch Algorithmen organisiert, die den kritischen Abschnitt umgeben (Entry/Exit-Code)

Grundsätzliche Anforderungen
1. Korrektheit: In einem kritischen Abschnitt befindet sich zu jedem Zeitpunkt höchstens ein Thread (**wechselseitiger Ausschluss**).
2. Lebendigkeit: Falls ein Thread einen kritischen Abschnitt betreten möchte, dann betritt (irgendwann) (irgend) ein Thread diesen Abschnitt. [Folglich kann **irgendwann** auch der erstgenannte Thread **den kritischen Abschnitt betreten**.]
3. Verhungerungsfreiheit: **Kein Thread wartet für immer** vor einem kritischen Abschnitt.

Wechselseitiger Ausschluss: ein erster (naiver) Versuch
- Ideen
  1. während Benutzung des Puffers: wird dieser als „busy“ markiert
  2. bei Vorfinden eines so markierten Puffers: wird gewartet
- Verhungern: z.B. bei Pseudoparallelität (fortwährende Unterbrechung des Writers im kritischen Abschnitt)

## Synchronisations- & Kommunikationsmechanismen
- Austausch von Daten zwischen Prozessen $\rightarrow$ Kommunikation (Inter-Prozess-Kommunikation, IPC)
- Abweichende Geschwindigkeiten von Sender und Empfänger $\rightarrow$ Synchronisation

Betrachtete Mechanismen:
- Semaphore
- Hoare ́sche Monitore
- Transaktionalen Speicher
- Botschaften
- Fernaufrufe

### (binäre) Semaphore
Idee: Flagge
- mit 2 Zuständen
    1. frei
    2. belegt
- mit 2 atomaren Operationen
    1. belegen: P( Semaphorname ) („Passeren“)
    2. freigeben: V (Semaphorname) („Vriegeven“)
- Sämtliche Nutzer dieses kritischen Abschnitts müssen diese semaphore verwenden (Entry-/Exit-Code, Türwächter)
- besser: kein aktives Warten

```cpp
// pic ← codePicFromCamStream();
if bufferBusy.zustand = frei then
bufferBusy.zustand ← belegt
else
bufferBusy.warteliste ← aufrufer
fi
//write(buffer, pic);
if bufferBusy.warteliste = leer then
bufferBusy.zustand ← frei
else
bufferBusy.warteliste.vorne.continue
fi
```

Implementierung von Semaphoren z.B. als Klasse (Objekt-Orientiert),
- die die Methoden P und V exportiert
- mit einer lokalen Thread-Warteliste
- mit (aus dem Maschinenraum) importierten Operationen atomicBegin und atomicEnd, die Atomarität herstellen
```cpp
P(semaphore s) {
  atomicBegin(s);
  if (s.zustand = frei)
    s.zustand ← belegt;
  else
    s.warteliste ← aufrufer;
      scheduler.suspend(aufrufer);
  fi
  atomicEnd(s);
}

V(semaphore s) {
  atomicBegin(s);
  if (s.warteliste = leer)
    s.zustand ← frei;
  else
    scheduler.continue
      (s.warteliste.vorne)
  fi
  atomicEnd(s);
}
```

Unterstützung durch Hardware: die TSL-Operation
- Atomarität
- Ausschluss paralleler Ausführung
→ TestAndSetLock („TSL“) im Instruktionssatz eines Prozessors
```cpp
atomicBegin(s):
TSL s.state, callingThread.Id // try to get lock
CMP s.state, callingThread.Id // did I get it?
JZE gotIt // yes
CALL scheduler.yield // optional in manycores, mandatory
// in monocores: yield processor
JMP atomicBegin // try again
gotIt: RET // got it, may enter critical region
```

Nutzung von Semaphoren:
- Multi-Thread-Anwendungen (Webserver, PowerPoint, etc.)
- auf Betriebssystem Ebene von allen nebenläufigen Aktivitäten

Implementierung
- im Ressourcenmanagement des Betriebssystems
- mit Hilfe des „Maschinenraums“: atomicBegin(s), atomicEnd(s)

!ungelöst: Geschwindigkeitsdifferenz
```cpp
//Writer-Thread:
forever do { 
  codePicFromCamStream(pic);
  P(bufferEmpty);
  P(bufferBusy);
  write(buffer,pic);
  V(bufferBusy);
  V(bufferFull);
}
```
- bufferBusy: verhindert gleichzeitigen Zugriff
- bufferEmpty: gibt Weg frei, wenn der Puffer leer ist
- bufferFull: gibt Weg frei, wenn er gefüllt ist

Mehrwertiger Semaphor (oder Zählsemaphor) mit mehreren Semaphoren; maximaler Sem-Wert = n, bestimmt maximale Anzahl von Threads, die gleichzeitig aktiv sein können

Zusammenfassend:
| bei Eintritt in kritischen Abschnitt | Bei Verlassen eines kritischen Abschnitts |
| -- | -- |
| P(Sem) - binärer Semaphor | V(Sem) - binärer Semaphor |
| Down(Sem) - Zählsemaphor | Up(Sem) - Zählsemaphor |
| Wait(Sem) - allgemein |  Signal(Sem) - allgemein |
| Haben die gleiche Wirkung auf den Wert des Semaphors: | Haben die gleiche Wirkung auf den Wert des Semaphors: |
| - Dekrementieren, bis Wert „Null“ erreicht | - Inkrementieren des Semaphorwertes |
| - Trifft ein Thread auf den Wert „Null“, wird dieser blockiert (und in eine Warteliste eingefügt) | |
| - Nimmt der Semaphor wieder einen Wert > 0 an, setzt (normalerweise) erster Thread in Warteliste fort | |

### Hoare'sche Monitore
- Problem bei Anwendung von Semaphoren: Softwarequalität
- Problematisch in größeren Systemen:
  - Synchronisationsoperationen (P und V)
    - umgeben kritische Operationen (z.B. read/write)
    - müssen explizit gesetzt werden

Korrektheitsproblem. Die unabdingbare
  - Vollständigkeit
  - Symmetrie
der P- und V-Operationen ist schwierig erreichbar und nachweisbar.

- Die Idee: implizite/automatische Synchronisation kritischer Operationen
- Der Weg: Nutzung des Prinzips der Datenabstraktion
  - Zusammenfassung von Daten, darauf definierten Operationen und der Zugriffssynchronisation zu einem abstrakten Datentyp, dessen Operationen wechselseitigen Ausschluss garantieren
  - Zugriff auf Daten: über implizit synchronisierende Operationen („Inseln der Ruhe“ in turbulenten Multithread-Umgebungen)
  - Die kritischen Abschnitte und die zugehörigen Daten liegen jetzt in einem durch einen Monitor geschütztem Bereich

Aufrufer muss nicht wissen
1. ob Synchronisation nötig ist
2. mit welchen Mechanismen dies erfolgen muss
3. welche Regeln dabei gelten

Ziel der Regeln\\
Wechselseitiger Ausschlusses der Monitoroperationen ⟺ zu jedem Zeitpunkt ist höchstens ein Thread in einem Monitor aktiv
1. Jede Monitoroperation ist am Eingang und an den Ausgängen durch einen Türsteher gesichert
2. Das Betreten des Monitors erfolgt nur mit dessen Zustimmung („Anklopfen“)
3. Falls ein anderer Thread im Monitor aktiv ist, wird die Zustimmung verweigert und der anklopfende Thread suspendiert ( $\approx$ P-Operation)
4. Wenn ein Thread den Monitor verlässt, wird ein wartender Thread eingelassen (fortgesetzt), ( $\approx$ V-Operation)
5. Gerät ein Thread innerhalb einer Monitoroperation in eine Wartesituation (Warten auf Bedingungsvariable), so verlässt er den Monitor
6. Bevor ein auf eine Bedingung wartender Thread fortgesetzt wird, muss er wieder am Türsteher vorbei

Implementierung der Regeln basierend auf Semaphoren
- je Monitor: ein Semaphor
- jede Operation eines Monitors enthält
  - am Eingang: eine P-Operation
  - an jedem (!) Ausgang: eine V-Operation
$\rightarrow$ wechselseitiger Ausschluss

Bedingungsvariable „Puffer nicht voll“, „Puffer nicht leer“ mit 2 Operationen:
1. Warten auf das Vorliegen der Bedingung
2. Signalisieren des Vorliegens der Bedingung
$\rightarrow$ Monitore mit Bedingungsvariablen

Monitore: komfortabler Mantel für Semaphore

Allgemeines Erzeuger/Verbraucher-Problem
Lösung 2er Aspekte der Synchronisation
1. wechselseitiger Ausschluss der Zugriffe auf gemeinsame Daten („buffer“)
    - durch wechselseitigen Ausschluss von Monitoroperationen
    - kurzzeitiges Ausbremsen
2. Anpassung unterschiedlicher Geschwindigkeiten von Erzeuger und Verbraucher
    - durch Warten auf und Signalisieren von Bedingungen (nonFull, nonMt)
    - längerfristiges Ausbremsen

Methoden und Mechanismen verwendbar für
1. Threads und Prozesse innerhalb eines Betriebssysteme
2. Threads innerhalb eines Anwendungsprozesses
3. Anwendungsprozesse untereinander (notwendig: gemeinsamer Speicher!)

## weitere Konzepte
### Transaktionaler Speicher
Problem: Semaphore/ Hoare‘sche Monitore lösen das Problem wechselseitigen Ausschlusses durch Sperren.
damit: Verhinderung paralleler Abläufe (da in einem kritischen Abschnitt jeweils nur ein Thread aktiv sein kann, werden gegebenenfalls weitere Threads blockiert, und somit für bestimmte Zeit von der Bearbeitung ausgeschlossen, d.h. also zeitweilig gestoppt)

Lange Zeit war Performanz sehr bequem/ Wachsende Leistung der Hardware durch:
1. Erhöhung der Taktfrequenz
2. Erhöhung der Transistorzahl
    - Pipelining: Zerlegung und fließbandartige parallele Abarbeitung einzelner Instruktionen
    - Hyperthreading: Lückenfüllung in den Pipelines durch Füttern aus verschiedenen Threads
    - spekulative Ausführung von Instruktionsfolgen
    - Arbeitsspeichercaches
    - TLBs
- für Software weitgehend unsichtbar
- vertraute sequenzielle Programmierparadigmen ausreichend

Diese Ära ist beendet
1. physikalische Aspekte der Energieverteilung/Wärmeableitung auf Chip; Limitierung der Steigerung der Taktfrequenz
2. logische Aspekte der Instruktionsausführung; Limitierung spekulativer Ausführung und Instruktionsparallelität
Weitere Leistungssteigerung
- durch Paradigmenwechsel der Prozessorarchitektur: Multicore-Prozessoren
- dadurch bedingt: Paradigmenwechsel der Software: Parallele (und verteilte) Algorithmen

Parallele Algorithmen
- erfordern:
  - hochparallele, sperrenfreie Synchronisationsmodelle
  - Konzept: transaktionaler Speicher
- Beobachtung:
  - nicht jede konkurrente Benutzung kritischer Abschnitte durch mehr als 1 Thread verursacht Fehler
- Pessimistische Herangehensweise:
  - „Aussperren“ weiterer Threads (z.B. durch Semaphore u. Monitore)
  - Dadurch: ausgesperrte Threads werden am Weiterkommen gehindert (Performanzverluste besonders bei intensiver Parallelarbeit)
- Optimistische Herangehensweise:
  - Kein „Aussperren“ von Threads (z.B. durch Semaphore u. Monitore)
  - Hinterher: Untersuchung auf Fehler und Korrektur, z.B. durch erneuten Versuch
- Geeignete Verfahrensweise:
  - Kombination mit Transaktionen (-> transaktionaler Speicher)
- Transaktionen:
  - stammen aus der Datenbanktechnik
  - ermöglichen u.a.: Zurückfahren fehlerhaft ausgeführter Programmabschnitte (genannt Transaktionen) u. Wiederholung von deren Ausführung auf elegante Weise

### Botschaften
Problem: Semaphore/Hoare‘sche Monitore/Transaktionaler Speicher erfordern zu ihrer Implementierung gemeinsamen Speicher der Beteiligten

Gibt es nicht
1. falls die Beteiligten auf unterschiedlichen Rechnern ablaufen
2. falls die Beteiligten disjunkte Adressräume besitzen
3. in lose gekoppelten Multiprozessor-Architekturen
Hierfür: muss ein anderes Kommunikationsparadigma her

2 elementare Operationen
1. Senden einer Botschaft an einen Empfänger
    `send(IN Empfänger, IN Botschaft)`
2. Empfangen einer Botschaft von einem Absender
    `receive(OUT Absender, OUT Botschaft)`

Anmerkungen
- genutzt: für Kommunikation zwischen
  - Prozessen innerhalb eines (Mikrokern-) Betriebssystems
  - Anwendungsprozesse untereinander (Klienten, Server)
- Betriebssysteme: implementieren send/receive-IPC
- Anwendungsprozesse: nutzen Bibliotheken oder Betriebssystem-Dienste,

### Fernaufrufe (Remote Procedure Calls, RPCs)
- Problem
  - Datenmodell des send/receive-Modells: Zeichenfolge $\rightarrow$ sehr primitiv
  - gewohnte Datenmodelle z.B. aus Programmiersprachen $\rightarrow$ Signaturen (Methodenaufruf, typisierte Parameterlisten)
- Idee: Anpassung eines
  - anwendungsnahen,
  - unkomplizierten und
  - vertrauten
- Kommunikationsmodells an die Eigenschaften verteilter Systeme:
  - Prozedurfernaufruf (Remote Procedure Call, RPC)
  - Methodenfernaufruf (Remote Method Invocation, RMI $\rightarrow$ Objekt-orientiert)

Grundidee dieser Architekturform
1. elementare Betriebssystem-Funktionalität: 
    - in sehr kleinem, hochprivilegiertem Betriebssystemkern (  Kern)
    - typische Aufgaben: Threads, Adressräume, IPC
2. weniger elementare Aufgaben:
    -schwächer privilegiert ( reguläre Anwendungssysteme = „Nutzerprozesse“)
3. Folgen
     - Isolation der Betriebssystem-Komponenten
       - → Robustheit (Fehlerisolation)
       - → IT-Sicherheit [Security] (TCB-Größe) $\rightarrow$ TCB: Trusted Computing Base
       - → Korrektheit (Verifizierbarkeit)
       - → Adaptivität (Auf- und Abskalierung der Systemfunktionalität)
       - → Kommunikationskosten

Kommunikationskosten
- Prozeduraufruf: monolithische Architektur: innerhalb eines Adressraums
- Prozedurfernaufruf: $\mu$-Kern-Architektur: über Adressraumgrenzen hinweg

### Systemaufrufe
Problem: Kommunikation Anwendungsprozess ↔ BS
- BS stellt zahlreiche Dienste bereit (Linux  250, Apple OS X  500); z.B.
  - Prozesserzeugung (fork)
  - Programmausführung (exec∗)
  - Dateimanagement (open, close, read, write)
  - Kommunikation (msg∗, socket, shm∗)
- In diesem Abschnitt: Aufrufmethoden und -mechanismen

1. Wünsche des Anwendungsentwicklers
    - Bequemlichkeit
    - Performanz (hohe Aufruffrequenz, tausende pro Sekunde)
2. Wünsche des Betriebssystem-Entwicklers
    - Sicherheit
    - Robustheit
- reguläre Prozeduraufrufe: erfüllen Kriterien nicht (isolierte Adressräume, Privilegien, Programmiersprachen)
- Prozedurfernaufrufe:
  - bequem, performant, sicher, robust
  - teuer
- gesucht: leichtgewichtiges RPC-Modell

1. Problem: Unterschiedliche Programmiersprachen
    - kein einheitliches Format der Aufrufparameter (Reihenfolge, Format)
    - Lösung: normierte Parameterstruktur und Datentyprepräsentation zwischen Anwendungsprogramm und Betriebssystem
      - definiert durch: API-Spezifikation des Betriebssystems
      - implementiert durch: zwischengeschaltete Bibliothek
      - (z.B. libc; Stellvertreter-Prozeduren, Urform heutiger Middleware-Stubs)
2. Problem: Separate Namensräume
    - „do_sys_write“ liegt nicht im Namensraum des Anwendungsprozesses
    - Lösung: Einigung auf Namenskonventionen („push(write_C)“)
3. Problem: Separate Adressräume/Adressraumbereiche
    - kein direkter Zugriff auf Parameter seitens der aufgerufenen Prozedur
    - Lösung:
      - Parameter-Datenstruktur auf User-Stack
      - performante Alternative: in Registern
4. Problem: Privilegienwechsel User→Kernel→User
    - TRAP/RTT-Mechanismus (ReTurn from Trap)

Kosten: Systemaufruf = Prozeduraufruf+X
X=
1. Standardisierung der Parameterübergabe
    - Kosten gering bei Übergabe in Registern (  reguläre Prozedur)
2. Isolation
    - Privilegienwechsel durch Interrupt ( TRAP/RTT )
    - je  100 Taktzyklen (Kontextsicherung)
    - Verlust der Sprungziel-Vorausberechnungen
    - Verlust spekulativer Ausführungen
    - sehr teuer
    - Optimierung (seit Pentium 2): SysEnter/SysCall-Instruktionen
- Kosten gegenüber regulärem Prozeduraufruf: heute ca. Faktor 2

### Ereignismanagement
Das Problem: Betriebssystemen laufen sehr viele Aktivitäten parallel ab
1. Ausführung von Anwendungsprogrammen
2. Management von Prozessor-, Speicher-, Kommunikations-Ressourcen
3. Bedienung der E/A-Peripherie
dabei: entstehen immer wieder Situationen, in denen auf unterschiedlichste Ereignisse reagiert werden muss, z.B.
- Timerablauf
- Benutzereingaben (Maus, Tastatur)
- Eintreffen von Daten von Netzwerken, Festplatten, ...
- Einlegen/stecken von Datenträgern
- Aufruf von Systemdiensten
- Fehlersituationen

- Qualitativ
  - Windows-System (Laptop), gestartete GUI
  - Jederzeit: können ca. 400 verschiedene Ereignisse eintreten
- Quantitativ
  - MacOS MacBook Pro
  - allein Systemaufruf-Ereignisse („SysEnter“) > 1.000.000/sek
- $\rightarrow$ Umgangsformen mit Ereignissen

Umgangsformen mit Ereignissen
1. „busy waiting“
    - spezialisierte Threads innerhalb des BS prüfen andauernd Ereigniseintritt
    - sehr kurze Reaktionszeit
    - ineffiziente Prozessornutzung
    - hoher Energieverbrauch
    - akzeptabel bei
      - bekannt kurzen Wartezeiten
      - Multiprozessormaschinen, falls
        - ausreichend Prozessoren vorhanden sind
        - ausreichend Energie vorhanden ist
2. „periodic testing“
    - spezialisierte Threads prüfen hin und wieder den Ereigniseintritt
    - je nach Prüfperiode
      - lang: fragliche Reaktionszeit
      - kurz: fragliche Effizienz der Prozessornutzung
    - akzeptabel bei: relaxten Reaktionszeitanforderungen
3. Unterbrechungen („Interrupts“)
    - Benachrichtigung über Ereignis
    - Zur Wirksamkeit dieser Technik
      - Verhältnis Anzahl Festplattenoperationen zu CPU-Operationen
      - Laptop: ca. 1:10.000.000

Ereignisklassen
1. E/A-Gerätemeldung („ich habe fertig“, „ich habe Fehler“)
2. Timer-Ablauf
3. Ausfall der Hardware (Stromausfall, Speicher-Paritätsfehler)
4. Fehlverhalten ablaufender Programme , z.B.
    - Ausführung privilegierter oder illegaler Instruktionen
    - Zugriff auf geschützte Speicheradressen
    - arithmetischer Überlauf (z.B. „$2^{40}* 2^{40}$ “ bei 64-Bit-Arithmetik)
    - Division durch 0
5. Seitenfehler (bei virtueller Speicherverwaltung, s.u.)
6. explizit per Programm ausgelöste Ereignisse („TRAP“)

Ereignisquellen
1. Hardware: E/A-Geräte, Uhren, CPU, MMU, ALU, FPU
2. Software: Instruktionen wie TRAP, SysCall
Technisch: Signalisierung z.B. durch „5 Volt an Prozessorbeinchen“
Programmiermodell: HW/SW-Schnittstelle?

Programmiermodelle zur Unterbrechungsbehandlung
- Idee
  - Verknüpfung von (HW-)Interrupts mit (SW-)Abstraktionen;
  1. Prozeduren (→ inline Prozeduraufrufmodell)
  2. IPC-Operationen (→ IPC-Modell)
  3. Threads (→ pop-up Thread Modell)
- Wirkung
  - Interrupt ↷ Ausführung der assoziierten Abstraktion, z.B.
  1. Interrupt Nr. 42: ↷ rufe Prozedur „InterruptHandler_42()“ auf
  2. Interrupt Nr. 42: ↷ sende Botschaft „Interrupt 42“ an einen Thread
  3. Interrupt Nr. 42: ↷ erzeuge Thread „Interrupt_42_Thread“

Das inline-Prozeduraufrufmodell
- Interruptbehandlungen: besitzen syntaktisches Aussehen einer Prozedur:
  - „Handlerprozeduren“ (interrupt service routines (ISRs))
- Ablauf der Interruptbehandlung: erzwungener Prozeduraufruf
  - kein Threadwechsel, sondern
  1. Unterbrechung des Tuns des momentan ablaufenden Threads
  2. Sicherung seines Ablaufkontexts (Lesezeichen: IP, SP, PSR, ...)
  3. Versetzen des Threads in Ablaufkontext der Unterbrechungsbehandlung (z.B. andere Privilegierungsebene)
  4. Ausführung der Handlerprozedur (untergeschobener (inline-) Prozeduraufruf)
  5. Restauration des Threads in den unterbrochenen Ablaufkontext (beim Lesezeichen)
- Planung der Interruptbehandlung:
  - Prozedurname mit Interruptquelle assoziieren
  - Interruptvektortabelle
  - es gibt: viele unterschiedliche Interruptquellen
  - es gibt: entsprechend viele unterschiedliche Reaktionen auf Interrupts
- Aufruf der zugehörigen Handlerprozedur:
  - wir haben: ein konkretes Interruptsignal: „5 Volt“ und eine Nummer $\rightarrow$ Hardwareebene
  - wir möchten: die Ausführung der zugehörigen Handlerprozedur im Betriebssystem, z.B. im Timer-Management $\rightarrow$ Softwareebene

Problem also: geeignete Hardware/Softwareschnittstelle

Lösung: Die Interruptvektor-Tabelle (IVT): Assoziationen („Interruptvektoren“) der Form
  - Interruptquelle → Handlerprozedur (ISR)
  - Interruptquelle: Nummer
  - Handlerprozedur: Code oder Codeadresse
  - Speicherort: BS und Interrupthardware bekannt; Varianten:
    1. fester Ort: z.B. im Arbeitsspeicher, beginnend bei Adresse 0
    2. variabel: lokalisiert über Adressregister (Interruptvektor Adressregister, IVA)
  - Format: (HW-)architekturspezifisch, dem Betriebssystem bekannt
  - erstellt:
    - in früher Boot-Phase des Systems
    - als Ergebnis einer Analyse möglicher Interrupt-Quellen (z.B. vorhandene E/A-Geräte) (BIOS, UEFI)

Fazit des inline-Prozeduraufrufmodells
1. Unterbrechungsbehandlung: durch Interrupt Service Routinen
2. Planung: in Interruptvektor-Tabelle
3. Ablauf: erzwungener Prozeduraufruf
      1. Sicherung des Ablaufkontexts des momentan aktiven Threads
      2. Auswahl der Handlerprozedur gemäß IVT-Eintrag
      3. Ausführung der Handlerprozedur durch untergeschobenen Prozeduraufruf
      4. Restaurierung des unterbrochenen Tuns des Threads

### IPC Modell
2-stufig
1. Stufe der Interruptbehandlung: erzeugt IPC-Operation
2. Stufe der Interruptbehandlung: Reaktion auf diese IPC-Operation
- Interrupts: abgebildet auf reguläre IPC-Operationen
- Interruptbehandlungen: sind reguläre Reaktionen der IPC-Adressaten
- zeitliche Kalkulierbarkeit und Kürze der primären Interruptbehandlung (Echtzeitsysteme!)

Planung
- IPC-Erzeugung mit Interruptquelle verknüpfen → Interruptvektor
- Beim Interrupt
    1. Stufe:
        - I. Unterbrechung des momentan aktiven Threads
        - II. Erzeugen der IPC-Operation, z.B. Senden einer Botschaft (klein – passt in IVT, sehr schnell)
        - III. Fortsetzung des unterbrochenen Threads
    2. Stufe: IPC-Adressat, z.B. Thread eines Gerätemanagers, reagiert auf IPC

### pop-up-Thread-Modell
2-stufig
1. Stufe der Interruptbehandlung: erzeugt Thread
2. Stufe der Interruptbehandlung: erfolgt in diesem Thread
- Interruptsignale: abgebildet auf Thread-Erzeugungen
- Interruptbehandlungen: sind reguläre Thread-Abläufe
- zeitliche Kalkulierbarkeit und Kürze der primären Interruptbehandlung (Echtzeitsysteme!)

Planung
- Thread-Erzeugung mit Interruptquelle verknüpfen → Interruptvektor
- Beim Interrupt
  1. Stufe:
      - I. Unterbrechung des momentan aktiven Threads
      - II. Erzeugen des Threads (klein – passt in IVT, sehr schnell)
      - III. Fortsetzung des unterbrochenen Threads
  2. Stufe:
      - Thread (z.B. in Gerätemanager) wird (irgendwann) vom Scheduler aktiviert


### Implementierungstechniken 
Ablauf
1. Ereignis entsteht: z.B. auf E/A-Geräteplatine, in MMU, in SW ...
2. Interruptsignal wird (evtl. über Kommunikationsbus) Prozessor zugestellt
3. Prozessor schließt Ausführung der laufenden Instruktion ab (falls möglich)
4. Prozessor sichert Ablaufkontext des aktiven Threads
5. Prozessor stellt Ablaufkontext der Interruptbehandlung her
    - dazu benötigt er minimal: Adresse der Interrupt-Behandlungsroutine
    - dies: setzt vorherige Einplanung in der IVT voraus
6. Fortsetzung des aktiven Threads im neuen Kontext der Interrupt-Behandlung; dabei u.U. Wechsel der Privilegierungsebene
7. der neue Kontext
    - führt Code in der IVT aus
    - dies ist je nach Interrupt-Programmiermodell: Aufruf einer Prozedur, Erzeugung einer IPC-Operation, Erzeugung eines Threads
8. bei Abschluss (RTI):
    - Rückversetzen des aktiven Threads in den gesicherten Ablaufkontext; dabei u.U. Rückkehr zur vorherigen Privilegierungsebene

Was bleibt der Software?
- Definition der Interrupt-Behandlungsalgorithmen (in Form von Prozeduren, IPC-Reaktionen, Threads; oft Teil des BS-E/A-Systems)
- Vorausplanung der Interrupt-Behandlungen in der IVT
  - Bootphase
  - Nachladen von Gerätemanagern

Die Realität ist häufig komplexer
1. Interruptquellen besitzen unterschiedliche Wichtigkeit
    - Priorisierung (Eignung der 3 Modelle?)
2. Echtzeiteigenschaften (zeitlich garantierte Reaktion auf Ereignisse)
    1. Unterbrechbarkeit der Interruptbehandlung durch höherpriore Interrupts
    2. geschachtelte Interruptbehandlung (Eignung der 3 Modelle?)
3. moderne Prozessorarchitekturen (superskalare (intern parallele)
    - Prozessoren) arbeiten mit spekulativer und paralleler Instruktionsausführung
    - viele Instruktionen befinden sich zum Unterbrechungszeitpunkt in unterschiedlichen Bearbeitungszuständen
    - Sicherung/Wiederaufsetzung des unterbrochenen Ablaufkontexts (HW) komplex und zeitaufwändig

Fazit soweit
- 100e von Ereignissen jede Sekunde
  - erfordert: effizientes und ökonomisches Ereignismanagement
- die Hardware hilft
  1. Schnittstelle: IVT
  2. Unterbrechungsmanagement
- Software: 3 alternative Programmiermodelle
  1. eine Prozedur wird aufgerufen
  2. eine Botschaft wird gesendet
  3. ein Thread wird erzeugt
- Wahl abhängig von
  1. Echtzeiteigenschaften
  2. Performanzanforderungen

Asynchrone Signalisierungsmechanismen außerhalb von Betriebssystemen
1. Meldung von Ereignissen (terminierte Kindprozesse, Ausführung illegaler Instruktionen, Speicherschutzverletzungen ...)
2. Stoppen, Fortsetzen, Abbruch von Prozessen

Umgang damit
1. Definition von ESRs (event service routines) in Anwendungssystemen;
deren syntaktische Form z.B. in C: Prozeduren (inline-Modell)
2. Planung der Ereignisreaktion
    1. Reaktionstyp festlegen
        - a) ignorieren
        - b) Prozessabbruch
        - c) ESR-Aufruf
    2. im letzteren Fall: Verknüpfen einer ESR mit einem Ereignis per Systemaufruf (z.B. in Unix: signal( <Ereignisnummer>, <ESR> ) )
    3. Betriebssystem: merkt sich Anbindung im Prozessdeskriptor (Ereignismanagement, „Handler-Vektor“; = Interruptvektortabelle) PD
    4. bei Ereigniseintritt: untergeschobener Prozeduraufruf (durch Modifikation des IP*-Registers (Anfang der ESR-Prozedur))
    5. nach Prozedurende: Fortsetzen an unterbrochener Stelle

Auslösung von Ereignissen durch
1. Hardware (z.B. Speicherzugriffsfehler, arithmetischer Fehler)
2. Betriebssystem (z.B. Prozessmanagement: Terminierung von Kindprozessen)
3. andere Benutzerprozesse (API-Aufruf) (z.B. in Unix: kill( <Prozess-Id>, <Ereignisnummer> ) )

bei Auftreten des Ereignisses; erfolgt gemäß obiger Planung
- a) ignorieren
- b) Prozessabbruch
- c) ESR-Aufruf
    1. inline-Prozeduraufruf der ESR-Prozedur
    2. Rückkehr zum unterbrochen Kontext nach dessen Ende

Zusammenfassung Ereignismanagement/Botschaften
1. Ereignismanagement erlaubt:
    - schnelle
    - effiziente
    - hardwareunterstützte
    - Reaktionen auf synchrone und asynchrone Ereignisse
2. Programmiermodelle: Abbildung von Ereignissen auf
   1. erzwungene Prozeduraufrufe
   2. IPC-Operationen
   3. Threaderzeugung
3. Planung: durch Definition der ISR und Eintrag in IVT
4. analoges Konzept auf Anwendungsebene , z.B.
    - Unix-Signale
    - Apple Events

## Zusammenfassung
IPC: Kommunikation und Synchronisation
  - a) Semaphore und Hoare‘sche Monitore: blockierend, pessimistisch 
  - b) transaktionaler Speicher: neu, optimistisch, transaktional
  - c) Botschaften: kein gemeinsamer Speicher, Datentransport
  - d) Fernaufrufe, Systemaufrufe: „Spezialisierungen“
  - e) Ereignismanagement: Interrupts, Unterbrechungen auf Anwendungsebene
