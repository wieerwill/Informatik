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

| Prozessormanagement | |
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

es gibt Work-Arounds: alle gefählrichen Systemaufrufe einpacken (in Pakete)

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
