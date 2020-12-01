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

