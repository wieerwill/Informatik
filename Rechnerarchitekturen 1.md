# Grundprinzipien
- Ein- und Ausgabe
- Programmspeicher
- Datenspeicher

Unterschieden in:
- Harvard Architektur: direkt mit Prozessor verbunden
- Princeton-Architektur (von-Neumann-Architektur): über Systembus verbunden

## Eigenschaften 
Fast alle der heute üblichen Rechner gehen auf folgende Eigenschaften zurück:
1. Die Rechenanlage besteht aus den Funktionseinheiten Speicher, Steuerwerk (engl. controller), dem Rechenwerk (engl. data path) und Ein-/Ausgabe-Einheiten.
2. Die Struktur der Anlage ist unabhängig vom bearbeiteten Problem. Die Anlage ist speicherprogrammierbar.
3. Der Speicher wird in Zellen gleicher Größe geteilt. Die Zellnummern heißen Adressen.
4. Das Programm besteht aus einer Folge von elementaren Befehlen, die in der Reihenfolge der Speicherung bearbeitet werden.
5. Abweichungen von der Reihenfolge sind mit (bedingten oder unbedingten) Sprungbefehlen möglich.
6. Es werden Folgen von Binärzeichen (nachfolgend Bitvektoren genannt) verwendet, um alle Größen darzustellen.
7. Die Bitvektoren erlauben keine explizite Angabe des repräsentierten Typs. Aus dem Kontext heraus muss stets klar sein, wie die Bitvektoren zu interpretieren sind.

# Befehlssatz
Adressierung ohne Speicherzugriff
- Registeradressierung: ausschließlich Operanden aus & Ziele in Registern
- Unmittelbare Adressierung, Direktoperanden, immediate addressing: Operanden sind Teil des Befehlsworts
- Direkte Adressierung, absolute Adressierung: Adresse ist ausschließlich im Befehlswort enthalten
- Register-indirekte Adressierung: Adresse ist ausschließlich im Register enthalten
  - Varianten: pre/post-increment/decrement zur Realisierung von Stapeloperationen
- Relative Adressierung, indizierte Adressierung, Basis-Adressierung: Adresse ergibt sich aus der Addition eines Registerinhalts und einer Konstanten im Befehl

## n-Adressmaschinen
Klassifikation von Befehlssätzen bzw. Befehlen nach der Anzahl der Adressen bei 2-stelligen Arithmetik-Befehlen
- 3-Adressmaschinen: Operanden und Ziel einer Operation werden explizit angegeben
- 2-Adressmaschinen: Überschreiben eines Operanden mit dem Ergebnis
- 1 1⁄2-Adressmaschinen: wie 2-Adressmaschinen, nur unter Verwendung von Registern
- 1-Adressmaschinen: Nutzung von nur 1 Register
- 0-Adressmaschinen: Kellermaschinen

## Programmiermodelle, Instruction Set Architectures (ISAs)
Klassifikation von Befehlssätzen nach der Gestaltung/Ausprägung der
vorhandenen Maschinenbefehle
- CISC – Complex Instruction Set Computers
  - Relativ kompakte Codierung von Programmen
  - Für jeden Befehl wurden mehrere Taktzyklen benötigt. Die Anzahl der Zyklen pro Befehl war groß
  - (Mikro-) Programm zur Interpretation der Befehle nötig
  - Compiler konnten viele Befehle gar nicht nutzen
- RISC – Reduced Instruction Set Computers
  - Wenige, einfache Befehle
  - Hohe Ausführungsgeschwindigkeit
    - durch kleine Anzahl von Taktzyklen pro Befehl
    - durch Fließbandverarbeitung (siehe später)
  - Programmlaufzeit = Anzahl auszuführender Befehle * CPI-Wert * Dauer eines Taktzyklus
  - Eigenschaften
    - feste Befehlswortlänge
    - LOAD/STORE-Architektur
    - einfache Adressierungsarten
    - „semantische Lücke“ zwischen Hochsprachen & Assemblerbefehlen durch Compiler überbrückt
    - statt aufwändiger Hardware zur Beseitigung von Besonderheiten (z.B. 16-Bit Konstanten) wird diese Aufgabe der Software übertragen
    - rein in Hardware realisierbar, keine Mikroprogrammierung

## Technologien zum Speichern von Daten
- Arten
  - **Modifikation von Strukturen**: Lochkarte, Schallplatte
  - **Rückkopplung**: Flip-Flops, SRAM
  - **Elektrische Ladungen**: Kondensator, DRAM
  - **Magnetismus**: Magnetkernspeicher, Magnetband, Diskette, Festplatte
  - **Optik**: Bar-Codes, CD-ROM, DVD
- Vergleichskriterien
  - Kapazität 
  - Energiebedarf
  - Geschwindigkeit
  - Robustheit
  - Speicherdichte 
  - Kosten
- Zugriffsmethoden
  - Sequentieller Zugriff
    - Zugriffszeit ist abhängig vom Speicherort und vom vorherigen Zugriff
    - Beispiele: Magnetbänder, Festplatten, CD-ROM, DVD, BluRay
    - Bei Plattenspeicher schneller Zugriff durch Überspringen von Spuren
  - Wahlfreier Zugriff
    - Zugriffszeit ist unabhängig vom Speicherort und vom vorherigen Zugriff
    - Eindeutige Adresse identifiziert den Speicherort
    - RAM (Random Access Memory)
- Einteilung des Speichers in
  - Flüchtigen Speicher
    - Informationen gehen nach Ausschalten der Versorgungsspannung verloren!
    - Register innerhalb des Prozessors
    - Static RAM (SRAM) für Caches
    - Dynamic RAM (DRAM) für den Arbeitsspeicher
  - Nichtflüchtige Speicher:
    - Informationen bleiben auch ohne Versorgungsspannung über längere Zeit (typischerweise einige Jahre) erhalten!
    - Beispiele: Flash, Magnetspeicher (Festplatte, Disketten, Magnetbänder)
    - Bei einem ROM (Read Only Memory) ist nur lesender Zugriff möglich

Zweierpotenzen
- 1 KibiByte = 1 KiB = 1024 Bytes = 2^10 Bytes
- 1 MebiByte = 1 MiB = 1024 KiB = 2^20 Bytes = 1.048.576 Bytes
- 1 GibiByte = 1 GiB = 1024 MiB = 2^30 Bytes = 1.073.741.824 Bytes
- 1 TebiByte = 1 TiB = 1024 GiB = 2^40 Bytes = 1.099.511.627.776 Bytes


## Blocktransfer (Burst)
Auslesen des kompletten Zeilenpuffers durch automatisches Inkrementieren der Spaltenadresse

## Cache 
= schneller Speicher, der vor einen größeren, langsamen Speicher geschaltet wird
- Im weiteren Sinn: Puffer zur Aufnahme häufig benötigter Daten
- Für Daten die schon mal gelesen wurden oder in der Nähe von diesen liegen
- 90% der Zeit verbringt ein Programm in 10% des Codes
- Im engeren Sinn: Puffer zwischen Hauptspeicher und Prozessor
- Ursprung: cacher (frz.) – verstecken („versteckter Speicher“)

Organisation von Caches
- Prüfung anhand der Adresse, ob benötigte Daten im Cache vorhanden sind („Treffer“; cache hit)
- Falls nicht (cache miss): Zugriff auf den (Haupt-) Speicher, Eintrag in den Cache


# Ein- und Ausgabe
## Übertragungsprotokolle
- Synchrone Busse
  - Keine Rückmeldung bei der Übertragung
  - Unidirektionales Timing
- Asynchrone Busse
  - Rückmeldung der Datenannahme
  - Bidirektionales Timing

| | unidirektional | bidirektional |
| -- | -- | -- |
| Beschreibung | Kommunikationspartner verlassen sich darauf, dass Partner innerhalb festgelegter Zeit reagieren. | Kommunikationspartner bestätigen per Kontrollsignal (senden ein acknowledgment), dass sie in der erwarteten Weise reagiert haben. |
| Vorteile | einfach; bei konstanten Antwortzeiten schnell | passt sich unterschiedlichen Geschwindigkeiten an; hoher Grad an Flusskontrolle möglich |
| Nachteile | Kommunikationspartner muss in bestimmter Zeit | antworten komplexer; Zeitüberwachung notwendig; evtl. langsam |
| Einsatzgebiet | synchrone Busse, Speicherbusse | asynchrone Busse, E/A- und Peripheriebusse |

Programmierbarer Interrupt Controller (PIC)

# Prozessorergänzung
## Prozessor-Leistung
Leistung = (Durchschnitts-)Befehle pro Zeit\
Berechnung: $L=\frac{IPC}{t_{cycle}}$ mit $IPC = \frac{1}{CPI}$ und $CPI = \sum t_i *p_i$
- IPC: Instructions Per Cycle (Anzahl Durchschnittsbefehle pro Taktzyklus)
- CPI: Cycles Per Instruction (Mittlere Anzahl Taktzyklen pro Befehl)
- $t_i$ : Anzahl Taktzyklen des i-ten Befehls
- $p_i$ : Relative Häufigkeit des i-ten Befehls
- $t_cycle$ : Taktzykluszeit [$μs$]

## Befehlspalette
Pipelining: Fließbandverarbeitung (seriell vs parallel)
- IF / ID / EX: Befehl lesen / dekodieren / ausführen
- OF / WB: Operand lesen / schreiben (Register)
- Probleme: Unterschiedliche Phasenlänge, bedingte Sprünge, Datenabhängigkeiten

Superskalare Architektur: \
Befehl lesen -> Befehl dekodieren -> Operand lesen -> Befehl ausführen -> Operand schreiben

dRam: mit Kondensator\
sRam: mit FlipFlop\
RAM: Random Access Memory\
ROM: Read Only Memory\
