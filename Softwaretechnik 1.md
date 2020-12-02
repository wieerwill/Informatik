---
title: Softwaretechnik 1
date: Wintersemester 20/21
author: Robert Jeutter
---

> Software: Menge von Programmen oder Daten zusammen mit begleitenden Dokumenten, die für Ihre Anwendung notwendig oder hilfreich sind [Hesse]

Gute Software ist schwer herzustellen
- Entspricht Kundenwünsche, Vollständigkeit
- Funktioniert Korrekt
- Kosten- und Termintreue bei der Erstellung
- weitere nicht-funktionale Qualitätsforderungen
  - Benutzerfreundlichkeit, Ergonomie
  - Sicherheit
  - Zuverlässigkeit, Fehlertoleranz
  - Performanz
  - Ressourcen-Effizienz, Skalierbarkeit, Übertragbarkeit
  - Wartbarkeit, Änder- und Erweiterbarkeit

Softwaretechnik
- Technische Disziplin der Software Herstellung
- Zielorientierte Bereitstellung uns systematische Verwendung von Prinzipien, Methoden und Werkzeugen für die arbeitsteilige, ingenieurmäßige Entwicklung und Anwendung von umfangreichen Softwaresystemen [Balzert]

Wie kann man Software besser entwickeln?
- Ingenieursmäßige Herangehensweise
  - Verwendung bekannter Prinzipien und Methoden
  - Systematische Vorgehensweise
- Verwendung von: 
  - Abstraktion, Modelle, Notation, Simulation
  - Wiederverwendung:Muster, Komponenten, Framework
- Organisation
  - Arbeitsteilung, Integration, Planung
- Verwendung von Werkzeugen
  - IDE (Integrated Development Environment)
  - Versionierung, Bugtracker, Modellierungswerkzeug

# Modellierungskonzepte
> Modell: ist eine Abstraktion eines Systems mit der Zielsetzung, das Nachdenken über ein System zu vereinfachen, indem irrelevante Details ausgelassen werden [Brügge]
$\rightarrow$ Beschreibung eines Ausschnitts der Realität

- erstellen einer Abstraktion
- abbilden signifikanter Eigenschaften
- Deskriptiv/präskriptiv (real oder geplant)
- Sichtweise auf ein System (Struktur, Verhalten, Zustand,...)
- heißt Weglassen
- setzt Verstehen voraus
- ist nicht automatisierbar

Verschiedene Modelle:
- Analysemodell
- Entwurfsmodell
- Implementierung (-smodell)
- Vorgehensmodell
- Produktmodell
- Dokumentation, Alternativen-Auswahl

Modelle für:
- Sichten
- Funktionen
- Daten
- Algorithmen
- Systemumgebung
- Dynamisches Verhalten
- Objektorientierte Modelle

## Klassische Modelle
- Funktionen: 
  - Funktionsbaum
    - Hierarchische Dekomosition der Fkt
    - nummerieren der Ebenen/Funktionen möglich
    - Bsp: Abonnement Verwaltung
  - Blockschaltbild
    - eingebettetes System, HW/SW
- Daten
  - Data Dictionary
    - Verzeichnis von Daten mit Strukturinformationen
    - Backus-Naur-Form, kontextfreie Grammatik
  - Entity Relationship Diagram
    - Daten und ihre Beziehungen
- Systemumgebung
  - Datenflussdiagramm
    - Fluss und Transformation von Daten zwischen Funktionen, Speichern und Schnittstellen
    - kein Kontrollfluss
- Algorithmen
  - Entscheidungstabelle
    - Regelbasierte Beschreibung
    - Bedingung
    - Aktionen
    - Reduktionsregeln
  - Pseudocode
    - von Programmiersprache abstrahierende, detaillierte Beschreibung eines Algorithmus
  - Programmablaufplan
    - Grafische Beschreibung des Kontrollflusses
    - DIN 66001
    - Unstrukturiert
  - Struktogramm
    - Nassi-Shneidermann-Diagramm
    - keine Sprünge
- Dynamisches Verhalten (diskrete Zustände und atomare zustandübergänge)
  - Zustandsautomat
    - Verhalten mit Zuständen und -übergängen
    - Automatenmodelle und -theorie
    - Ggf zerlegung oder kommunizierende Automaten
  - Flow-Chart
  - Ereignisgesteuerte Prozesskette (EPK)
    - Geschäftsprozesse
    - BPM
  - Petri-Netz (ggf. mit Zeitmodell)
    - Grafische Beschreibung von Nebenläufigkeit und Synchronisation
- Objektorientierte Modelle
  - Klassendiagramme
  - UML


## Objektorientierung
- bessere Strukturierung für komplexe Zusammenhänge
- Abstraktere Sichtweise
- Grundprinzip: Zerlegung; Teile und Herrsche
- ein System besteht aus vielen Objekten
- ein Objekt hat
  - definiertes Verhalten
    - Menge genau definierter Operationen
    - Operation wird beim Empfang einer Nachricht ausgeführt
  - inneren Zustand
    - Zustand des Objekts ist Privatsache
    - Resultat einer Operation hängt vom aktuellen Zustand ab
  - eindeutige Identität
    - Identität ist unabhängig von anderen Eigenschaften
    - Mehrere verschiedene Objekte mit identischem Verhalten und identischem inneren Zustand im gleichen System möglich
- Klasse
  - Gleichartige Objekte mit ggf. verschiedenen Zuständen
  - Verhaltensschema – Operationen
  - Innere Struktur – Attribute

Vorteile der Objektorientierung
- Zuständigkeitsbereiche
  - Daten, Operationen und Zustand: lokal und gekapselt
- Klare Schnittstellen
  - Definiertes Objektverhalten, Nachrichten
- Hierarchie
  - Vererbung und Polymorphie (Spezialisierung), Klassenschachtelung
- Baukastenprinzip
  - Benutzung vorgefertigter Klassenbibliotheken, Anpassung durch Spezialisierung (mittels Vererbung)


## Unified Modeling Language
- Grafisches Beschreibungsmittel für Aspekte des Softwareentwurfs diskreter Systeme
  - Spezifikation, Entwurf, Visualisierung, Konstruktion, Dokumentation von Software
  - Für OO-Softwareentwicklung und -prozess geeignet
  - UML ist weder Methode noch Prozess

Warum UML?
- Objektorientierung ist zur Zeit das vorherrschende Modellierungs-Paradigma, Industrie-Standard
- Kombination von Struktur-, Verhaltens-, Interaktions-, und Verteilungsmodellen
- Für Analyse, Entwurf, Implementierung und Test einsetzbar
- Gute Werkzeugunterstützung für Editieren, Versionierung, Codegenerierung
- Erweiterbarkeit der UML mit Stereotypen und Tags
- Semi-formale Modelle, z.T. verschiedene Interpretationen
- Offenheit: Erweiterung mit stereotypes, tags, constraints

Nachteile UML
- UML ist in vielen Facetten nicht präzise festgelegt
- Werkzeuge für Transformation, Analyse etc. fehlen noch
- UML ist keine „kleine Sprache“: Lernaufwand notwendig
- Komponenten sind nicht adäquat darstellbar
- Sprachen wie die UML werden erlernt durch Übung!
- Aber: LV SWT ist kein kompletter UML-Kurs

### Überblick über Modelle
- 14 Diagrammarten
- Struktur-Diagramme
  - Klassen-, Objekt-, Komponenten-, Kompositions-Struktur-,
  - Paket- und Verteilungsdiagramm
  - Profildiagramm – zur UML-Erweiterung
- Verhaltens-Diagramme
  - Use-Case-, Aktivitäts- und Zustandsdiagramms
  - Interaktionsdiagramme: Sequenz-, Kommunikations-, Timing- und Interaktionsübersichts-Diagramm

#### Use-Case-Diagramm
- Beschreiben Systemfunktion aus Benutzersicht (Was, nicht Wie)
- Erste Anforderungsspezifikation (requirements)
- Planbare Einheiten als Inkremente für die Entwicklung
- Keine Modellierung eines Ablaufs!
- Erstellen von Testfällen (test case generation)
- Grundelemente
  - Anwendungsfall: Use Case
  - Beteiligte: Aktor
- Verfeinerung mittels Use-Case-Realisierung notwendig
  - Textuelle Beschreibung
  - Verhaltensdiagramme

#### Klassendiagramm
- Modellierung der Struktur (Aufbau) eines Systems
- Modellierung von statischen Aspekten
- Modellierung der Struktur von Daten
- Klasse im Mittelpunkt
  - Aufbau: Attribute, Operationen
  - Beziehungen zueinander: Assoziationen, Vererbung
- Verbreitetstes und bekanntestes Diagramm der UML

#### Objektdiagramm
- Struktur des Systems zur Laufzeit zu einem Zeitpunkt
- Tatsächliche Zusammenhänge und Belegungen von Attributen von Objekten zu einem Zeitpunkt
- Eine detaillierte Sicht auf einen Aspekt
  - Keine vollständige Beschreibung (zu komplex)
  - Für kompliziertere Abhängigkeiten (z.B. Rekursion)
- Objektdiagramm für alle Arten von Exemplaren
  - z.B.: Klasse (Objekt), Komponente, Knoten, ...
- Keine Exemplare von Operationen -> Ablauf -> Verhaltensdiagramme / Interaktionsdiagramme
- Kein Verlauf der Wertebelegung über die Zeit

#### Paketdiagramm
- Gliederung (Strukturierung) des Systems in Teile (Pakete)
- Zuordnung von Elementen zu einem Paket
- Bildung von Hierarchien (Enthält-Beziehung)
- Abhängigkeiten zwischen den Paketen
  - "Include" von Quellcode-Dateien (<<import>>)
- Anwendung:
  - Zum Grobentwurf von Systemen
  - Definition von Schichten

#### Komponentendiagramm
- Strukturierung des Systems durch Komponenten
- Komponente: Modulare, austauschbare Einheit (Substitution)
- Modellierung der Abhängigkeiten zwischen Komponenten
- Modellierung der inneren Struktur von Komponenten
- Definition von Schnittstellen

#### Kompositionsstrukturdiagramm
- Teile-Ganzes-Strukturen -> Kompositionsstruktur
- Strukturell statische Kompositionsstrukturen:
  - Kurzschreibweise bei vielen Kompositionen
  - Modellierung des Aufbaus komplexer Systeme
- Strukturell dynamische Kompositionsstrukturen:
  - Notwendige Strukturen zur Realisierung eines Verhaltens
  - Definition von Rollen, zur Lösung wiederkehrender Probleme -> Modellierung von Mustern
- Starke Verwandtschaft mit dem Klassendiagramm
- Spezialisierte Kompositionsbeziehung -> erweiterte Semantik

#### Aktivitätsdiagramm
- Modellierung von
  - Kontrollflüssen
  - Datenflüssen
  - Parallelem Verhalten
  - Verzweigungen, bedingten und gewichteten Abläufen
- Geschäftsprozessmodellierung möglich
- Abstrakte und detaillierte Verhaltensbeschreibung möglich
- Grundlage zur Codegenerierung
- Zur Verfeinerung von
  - Use-Cases
  - Operationen / Interaktionen
  - anderen Aktionen und Aktivitäten

#### Interaktionsdiagramme
- Modellierung von
  - Kommunikation zwischen Kommunikationspartnern (Lebenslinie)
  - Operationen (Modellierung eines Programms)
  - Informationsaustausch / Nachrichten
- Gemeinsames Grundkonzept der Interaktionsdiagramme
- Sehr detaillierte Diagramme
  - Meist nicht zur vollständigen Beschreibung eines Systems
  - Betrachtung eines wichtigen Teilaspekts
- Grundlage zur Codegenerierung

#### Sequenzdiagramm
- Genaue zeitliche Abfolge von Nachrichten
- Umfangreichstes Interaktionsdiagramm
- Kontrollelemente möglich (Schleifen, Verzweigungen)

#### Kommunikationsdiagramm
- Kommunikationsbeziehungen der Kommunikationspartner stehen im Vordergrund
- Welche Komponenten arbeiten wie zusammen, um eine Funktion zu erfüllen

#### Timing-Diagramm
- Genaue zeitliche Darstellung von Zustandsübergängen
- Kommunikation abhängiger Zustandsautomaten
- Modellierung einzelner Interaktion

##### Prinzipieller Aufbau
- Zeitlicher Verlauf senkrecht
- Kommunikationspartner waagerecht (unsortiert)
- Lebenslinie
  - Rechteck mit gestrichelter senkrechter Linie
  - Start, Ende und Dauer der Ausführung einer Operation
  - Rekursive Aufrufe möglich
- Ereignisspezifikation
  - Stelle des Sendens / Empfangens der Nachricht
  - Definition der Reihenfolge des Auftretens
  - Trace: Folge von Sende- und Empfangsereignissen

##### Weitere Elemente des Sequenzdiagramms
- Nachrichten ohne Sender
  - z.B. am Beginn einer Interaktion
- Verlorene Nachrichten (ohne Empfänger)
  - Nachricht ohne dargestellten Empfänger
  - z. B. am Ende einer Interaktion
- Erzeugen von Lebenslinien
  - Gestrichelte Linie mit geöffnetem Pfeil
  - Keine Rückgabenachricht
  - Zeitliche Einrückung des Rechtecks
- Zerstören von Lebenslinien
  - Durchgezogene Linie mit Dreieckende
  - Kann Rückgabenachricht erzeugen

##### Nachrichten in Interaktionsdiagrammen
- Ereignis des Sendens bzw. Empfangens von Nachrichten
- Typen:
  - Operationsaufruf (synchron / asynchron)
  - Antwort Nachricht
  - Signal (asynchron), Create-/ Delete Message
- Operationsaufruf: Parameterliste muss kompatibel sein
- Nachrichtentypen

#### Zustandsdiagramm
- Modellierung des (vollständigen?) Verhaltens
  - Zustände von Klassen / Objekten / Komponenten
  - Übergänge zwischen den Zuständen
  - Ereignisse, die Zustandswechsel auslösen
- Modellierung von endlichen Automaten (Zustandsmaschinen)
  - Deterministische
  - Nichtdeterministische
- Verfeinerung von Zuständen möglich
- Modellierung von verteilten Systemen / parallelem Verhalten
- Grundlage zur Codegenerierung



# Analyse
# Grobentwurf
# Feinentwurf
# Implementierung
# Vorgehensweise
# Projektmanagement