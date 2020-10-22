---
title: Datenbanksysteme
date: Wintersemester 20/21
author: Robert Jeutter
---

# Was sind Datenbanken - Grundlegende Konzepte
## Überblick
- Daten = logisch gruppierte Informationseinheiten
- Bank = Sicherheit vor Verlust, Dienstleistung für mehrere Kunden, (langfristige) Aufbewahrung

Ohne Datenbanken:
- jedes Anwendungssystem verwaltet seine eigenen Daten
- Daten sind (redundant) mehrfach gespeichert
- Probleme
  - Verschwenden von Speicherplatz
  - "vergessen" von Änderungen
  - keine zentrale "genormte" Datenerhaltung
- größere Mengen von Daten nicht effizient verarbeitet
- mehrere Benutzer können nicht parallel auf den gleichen Daten arbeiten, ohne sich zu stören
- Anwendungsprogrammierer/Benutzer können Anwendungen nicht programmieren/benutzen ohne ... zu kennen (keine Datenunabhängigkeit)
  - interne Dartstellung der Daten
  - Speichermedien oder Rechner
- Datenschutz und   Datensicherheit

### Datenintegration durch Datenbanksystem
Anwendungen greifen über Datenbankmanagementsystem auf Datenbank zu.

Datenbankmanagementsystem (DBMS): Software zur Verwaltung von Datenbanken

Datenbank (DB): strukturierter, von DBMS verwalteter Datenbestand

Datenbanksystem (DBS) = DBMS + DB



## Architekturen
die neun Codd'schen Regeln
1. Integration: einheitliche, nichtredundante Datenverwaltung
2. Operationen: Speichern, Suchen, Ändern
3. Katalog: Zugriffe auf Datenbankbeschreibungen im Data Dictionary
4. Benutzersichten
5. Integritätssicherung: Korrektheit des Datenbankinhalts
6. Datenschutz: Ausschluss unauthorisierter Zugriffe
7. Transaktionen: mehrere DB-Operationen als Funktionseinheit
8. Synchronisation: parallele Transaktionen koordinieren
9. Datensicherung: Wiederherstellung von Daten nach Systemfehlern

Ziele:
- Trennung von Modellierungssicht und interner Speicherung
- Portierbarkeit
- Tuning vereinfachen
- standardisierte Schnittstellen

Schemata:
- Konzeptuelles Schema (Ergebnis der Dateidefinition)
- Internes Schema (Festlegung der Dateiorganisation und Zugriffspfade = Index)
- Externes Schema (Ergebnis der Sichtdefinition)
- Anwendungsprogramm (Ergebnis der Anwendungsprogrammierung)

- Trennung Schema-Instanz
  - Schema: Metadaten, Datenbeschreibung
  - Instanz: Anwenderdaten, Datenbankzustand

Datenunabhängigkeit:
- Stabilität der Benutzerschnittstelle gegen Änderungen
- physisch: Änderung der Dateiorganisation und Zugriffspfade haben keinen Einfluss auf das konzeptuelle Schema
- logisch: Änderung am konzeptuellen und gewissen externen Schemata haben keine Auswirkungen auf andere externe Schemata und Anwendungsprogramme

Aufteilung der Funktionalitäten einer Anwendung
- Präsentation und Benutzerinteraktion
- Anwendungslogik („Business“-Logik)
- Datenmanagementfunktionen (Speichern, Anfragen, ...).

Architektur von Datenbankanwendungen typischerweise auf Basis des Client-Server-Modells (Server=Datenbanksystem).

### 3 Schichten Architektur (ANSI-SPARC-Architektur) 
Klassifizierung der Komponenten
- Definitionskomponenten: Datendefinition, Dateiorganisation, Sichtdefinition
- Programmierkomponenten: DB-Programmierung mit eingebetteten DB-Operationen
- Benutzerkomponenten: Anwendungsprogramme, Anfrage und Update interaktiv
- Transformationskomponenten: Optimierer, Auswertung, Plattenzugriffssteuerung
- Data Dictionary (Datenwörterbuch): Aufnahme der Daten aus Definitionskomponenten, Versorgung der anderen Komponenten

### 5 Schichten Architektur
Verfeinerung der Transformation
- Datensystem: Übersetzung, Zugriffspfadwahl
- Zugriffssystem: Logische Zugriffspfade, Schemakatalog, Sortierung, Transaktionsverwaltung
- Speichersystem Speicherungsstrukturen, Zugriffspfadverwaltung, Sperrverwaltung, Logging, Recovery
- Pufferverwaltung: Systempufferverwaltung, Seitenersetzung, Seitenzuordnung
- Betriebssystem: Externspeicherverwaltung, Speicherzuordnung

## Einsatzgebiete
- Klassische Einsatzgebiete:
  - viele Objekte (15000 Bücher, 300 Benutzer, 100 Ausleihvorgänge pro Woche, ...)
  - wenige Objekttypen (BUCH, BENUTZER, AUSLEIHUNG)
  - etwa Buchhaltungssysteme, Auftragserfassungssysteme, Bibliothekssysteme, ...
- Aktuelle Anwendungen: E-Commerce, entscheidungsunterstützende Systeme (Data Warehouses, OLAP), NASA’s Earth Observation System (Petabyte-Datenbanken), Data Mining

Datenbankgrößen:
- eBay Data Warehouse: 10PB
  - Teradata DBMS, 72 Knoten, 10.000 Nutzer,
  - mehrere Millionen Anfragen/Tag
- WalMart Data Warehouse: 2,5PB
  - Teradata DBMS, NCR MPP-Hardware;
  - Produktinfos (Verkäufe etc.) von 2.900 Märkten;
  - 50.000 Anfragen/Woche
- Facebook: 400TB
  - x.000 MySQL-Server
  - Hadoop/Hive, 610 Knoten, 15 TB/Tag
- US Library of Congress 10-20TB
  - nicht digitalisiert

## Historisches
- Wissensbanksysteme
  - Daten in Tabellenstrukturen
  - Stark deklarative DML, integrierte Datenbankprogrammiersprache
- Objektorientierte Datenbanksysteme
  - Daten in komplexeren Objektstrukturen (Trennung Objekt und seine Daten)
  - Deklarative oder navigierende DML
  - Oft integrierte Datenbankprogrammiersprache
  - Oft keine vollständige Ebenentrennung

- Neue Hardwarearchitekturen
  - Multicore-Prozessoren, Hauptspeicher im TB-Bereich: In-Memory-Datenbanksysteme (z.B. SAP HANA)
- Unterstützung für spezielle Anwendungen
  - Cloud-Datenbanken: Hosting von Datenbanken, Skalierbare Datenmanagementlösungen (Amazon RDS, Microsoft Azure)
• Datenstromverarbeitung: Online-Verarbeitung von Live-Daten, z.B. Börseninfos, Sensordaten, RFID-Daten, ...(StreamBase, MS StreamInsight, IBM Infosphere Streams)
  - Big Data: Umgang mit Datenmengen im PB-Bereich durch hochskalierbare, parallele Verarbeitung, Datenanalyse (Hadoop, Hive, Google Spanner & F1, ...)
- NoSQL-Datenbanken („Not only SQL“):
  - nicht-relationale Datenbanken, flexibles Schema (dokumentenzentriert)
  - „leichtgewichtig“ durch Weglassen von SQL-Funktionalitäten wie Transaktionen, mächtige deklarative Anfragesprachen mit Verbunden etc.
  - Beispiele: CouchDB, MongoDB, Cassandra, ...


# Relationale Datenbanken - Daten als Tabellen
## Relationen für tabellarische Daten
Konzeptuell: Datenbank = Menge von Tabellen (= Relationen)

- „Tabellenkopf“: Relationenschema
- Eine Zeile der Tabelle: Tupel; Menge aller Einträge: Relation
- Eine Spaltenüberschrift: Attribut
- Ein Eintrag: Attributwert

Integritätsbedingungen: Schlüssel
- Attribute einer Spalte identifizieren eindeutig gespeicherte Tupel: Schlüsseleigenschaft
- auch Attributkombinationen können Schlüssel sein!
- Schlüssel können durch Unterstreichen gekennzeichnet werden
- Schlüssel einer Tabelle können in einer anderen (oder derselben!) Tabelle als eindeutige Verweise genutzt werden: 
  - Fremdschlüssel, referenzielle Integrität
- ein Fremdschlüssel ist ein Schlüssel in einer „fremden“ Tabelle

## SQL-Datendefinition
### CREATE table
Wirkung dieses Kommandos ist sowohl
- die Ablage des Relationenschemas im Data Dictionary, als auch
- die Vorbereitung einer „leeren Basisrelation“ in der Datenbank

### DROP table
komplettes Löschen einer Tabelle (Inhalt und Eintrag im Data
Dictionary)

### Mögliche Wertebereiche in SQL
- integer (oder auch integer4, int),
- smallint (oder auch integer2),
- float(p) (oder auch kurz float),
- decimal(p,q) und numeric(p,q) mit jeweils q Nachkommastellen,
- character(n) (oder kurz char(n), bei n = 1 auch char) für Zeichenketten (Strings) fester Länge n,
- character varying(n) (oder kurz varchar(n) für Strings variabler Länge bis zur Maximallänge n,
- bit(n) oder bit varying(n) analog für Bitfolgen, und
- date, time bzw. datetime für Datums-, Zeit- und kombinierte Datums-Zeit-Angaben

Beispiel:
```sql
create table WEINE (
  WeinID int,
  Name varchar(20) not null,
  Farbe varchar(10),
  Jahrgang int,
  Weingut varchar(20),
  primary key(WeinID),
  foreign key(Weingut) references ERZEUGER(Weingut))
```
- primary key kennzeichnet Spalte als Schlüsselattribut
- foreign key kennzeichnet Spalte als Fremdschlüssel
- not null schließt in bestimmten Spalten Nullwerte als Attributwerte aus
- null repräsentiert die Bedeutung „Wert unbekannt“, „Wert nicht anwendbar“ oder „Wert existiert nicht“, gehört aber zu keinem Wertebereich
- null kann in allen Spalten auftauchen, außer in Schlüsselattributen und den mit not null gekennzeichneten


## Grundoperationen: Die Relationenalgebra
- Anfrageoperationen auf Tabellen
  - Basisoperationen auf Tabellen, die die Berechnung von neuen Ergebnistabellen aus gespeicherten Datenbanktabellen erlauben
  - Operationen werden zur sogenannten Relationenalgebra zusammengefasst
  - Mathematik: Algebra ist definiert durch Wertebereich sowie darauf definierten Operationen
    - für Datenbankanfragen entsprechen die Inhalte der Datenbank den Werten, Operationen sind dagegen Funktionen zum Berechnen der Anfrageergebnisse
  - Anfrageoperationen sind beliebig kombinierbar und bilden eine Algebra zum „Rechnen mit Tabellen“ – die Relationenalgebra

- Selektion $\sigma$: Auswahl von Zeilen einer Tabelle anhand eines Selektionsprädikats
- Projektion $\pi$: Auswahl von Spalten durch Angabe einer Attributliste
  - Die Projektion entfernt doppelte Tupel
- Verbund $\bowtie$ (engl. join): verknüpft Tabellen über gleichbenannte Spalten, indem er jeweils zwei Tupel verschmilzt, falls sie dort gleiche Werte aufweisen
  - Tupel, die keinen Partner finden (dangling tuples), werden eliminiert
- Umbenennung $\beta$: Anpassung von Attributnamen mittels Umbenennung
- Vereinigung $r_1 \cup r_2$ von zwei Relationen $r_1$ und $r_2$: 
  - Gesamtheit der beiden Tupelmengen
  - Attributmengen beider Relationen müssen identisch sein
- Differenz $r_1 − r_2$ eliminiert die Tupel aus der ersten Relation, die auch in der zweiten Relation vorkommen
- Durchschnitt $r_1 \cap r_2$: ergibt die Tupel, die in beiden Relationen gemeinsam vorkommen


## SQL als Anfragesprache
```sql
SELECT farbe FROM weine WHERE Jahrgang = 2002
```
- SQL hat Multimengensemantik — Duplikate in Tabellen werden in SQL nicht automatisch unterdrückt!
  - Mengensemantik durch distinct
- Verknüpfung von Tabellen
  - Kreuzprodukt: `` select * from Weine, Erzeuger``
  - Verbund: `` select * from Weine natural join Erzeuger``
  - Verbund mit Bedingung: `` select * from Weine, Erzeuger where Weine.Weingut = Erzeuger.Weingut``
- Kombination von Bedingungen
- Vereinigung in SQL explizit mit union

## Änderungsoperationen in SQL
- insert: Einfügen eines oder mehrerer Tupel in eine Basisrelation oder Sicht
  - `` INSERT INTO table (attribut) VALUE (ausdruck) ``
  - optionale Attributliste ermöglicht das Einfügen von unvollständigen Tupeln
  - nicht alle Attribute angegeben ⇝ Wert des fehlenden Attribut Land wird null
- update: Ändern von einem oder mehreren Tupel in einer Basisrelation oder Sicht
  - `` UPDATE relation SET attribut=ausdruck ``
- delete: Löschen eines oder mehrerer Tupel aus einer Basisrelation oder Sicht
  - `` DELETE FROM table WHERE id=123 ``
  - Löschoperationen können zur Verletzung von Integritätsbedingungen führen!

Lokale und globale Integritätsbedingungen müssen bei Änderungsoperationen automatisch vom System überprüft werden


# Datenbankentwurf im ER-Modell
## Datenbankmodelle
> **Datenbankmodell**: Ein Datenbankmodell ist ein System von Konzepten zur Beschreibung von Datenbanken. Es legt Syntax und Semantik von Datenbankbeschreibungen für ein Datenbanksystem fest.

Datenbankbeschreibungen = Datenbankschemata

1. statische Eigenschaften
  1. Objekte
  2. Beziehungen
  - inklusive der Standard-Datentypen, die Daten über die Beziehungen und Objekte darstellen können,
2. dynamische Eigenschaften wie
  1. Operationen
  2. Beziehungen zwischen Operationen,
1. Integritätsbedingungen an
  1. Objekte
  2. Operationen

Datenbankmodelle im Überblick
- HM: hierarchisches Modell, NWM: Netzwerkmodell, RM: Relationenmodell
- NF 2 : Modell der geschachtelten (Non-First-Normal-Form = NF 2 ) Relationen, eNF 2 : erweitertes NF 2 -Modell
- ER: Entity-Relationship-Modell, SDM: semantische Datenmodelle
- OODM / C++: objektorientierte Datenmodelle auf Basis objektorientierter Programmiersprachen wie C++, 
  - OEM: objektorientierte Entwurfsmodelle (etwa UML), 
  - ORDM: objektrelationale Datenmodelle

## ER Modell
- **Entity**: Objekt der realen oder der Vorstellungswelt, über das Informationen zu speichern sind, z.B. Produkte (Wein, Katalog), Winzer oder Kritiker; aber auch Informationen über Ereignisse, wie z.B. Bestellungen 
- **Relationship**: beschreibt eine Beziehung zwischen Entities, z.B. ein Kunde bestellt einen Wein oder ein Wein wird von einem Winzer angeboten
- **Attribut**: repräsentiert eine Eigenschaft von Entities oder Beziehungen, z.B. Name eines Kunden, Farbe eines Weines oder Datum einer Bestellung
  - Attribute modellieren Eigenschaften von Entities oder auch Beziehungen
  - alle Entities eines Entity-Typs haben dieselben Arten von Eigenschaften; Attribute werden somit für Entity-Typen deklariert
- **Werte**: primitive Datenelemente, die direkt darstellbar sind
  - Wertemengen sind beschrieben durch Datentypen, die neben einer Wertemenge auch die Grundoperationen auf diesen Werten charakterisieren
  - ER-Modell: vorgegebene Standard-Datentypen, etwa die ganzen Zahlen int, die Zeichenketten string, Datumswerte date etc.
  - jeder Datentyp stellt Wertebereich mit Operationen und Prädikaten dar
- **Entities** sind die in einer Datenbank zu repräsentierenden Informationseinheiten
  - im Gegensatz zu Werten nicht direkt darstellbar, sondern nur über ihre Eigenschaften beobachtbar
  - Entities sind eingeteilt in Entity-Typen, etwa $E_1 , E_2,...$
- **Schlüsselattribute**: Teilmenge der gesamten Attribute eines Entity-Typs $E(A_1,... , A_m)$
  - in jedem Datenbankzustand identifizieren die aktuellen Werte der Schlüsselattribute eindeutig Instanzen des Entity-Typs E
  - bei mehreren möglichen Schlüsselkandidaten: Auswahl eines Primärschlüssels
- **Beziehungstypen**: Beziehungen zwischen Entities werden zu Beziehungstypen zusammengefasst
  - Beziehungen können ebenfalls Attribute besitzen


Merkmale von Beziehungen
- Stelligkeit oder Grad:
  - Anzahl der beteiligten Entity-Typen
  - häufig: binär
  - Beispiel: Lieferant liefert Produkt
- Kardinalität oder Funktionalität:
  - Anzahl der eingehenden Instanzen eines Entity-Typs
  - Formen: 1:1, 1:n, m:n
  - stellt Integritätsbedingung dar
  - Beispiel: maximal 5 Produkte pro Bestellung

- 1:1 Beziehung
  - jedem Entity $e_1$ vom Entity-Typ $E_1$ ist maximal ein Entity $e_2$ aus $E_2$ zugeordnet und umgekehrt
  - Bsp: Prospekt *beschreibt* Produkt 
- 1:N Beziehung
  - jedem Entity $e_1$ aus $E_1$ sind beliebig viele Entities $E_2$ zugeordnet, aber zu jedem Entity $e_2$ gibt es maximal ein $e_1$ aus $E_1$
  - Bsp: Lieferant *liefert* Produkte, Mutter *hat* Kinder
- N:1 Beziehung
  - invers zu 1:N, auf funktionale Beziehung
- M:N Bezeihung
  - keine Restriktionen
  - Bsp: Bestellung *umfasst* Produkte

[min,max]-Notation
- schränkt die möglichen Teilnahmen von Instanzen der beteiligten Entity-Typen an der Beziehung ein, indem ein minimaler und ein maximaler Wert vorgegeben wird
- Spezielle Wertangabe für $max_i$ ist ∗

Kardinalitätsangaben
- [0, ∗] legt keine Einschränkung fest (default)
- $R(E_1 [0, 1], E_2 )$ entspricht einer (partiellen) funktionalen Beziehung $R : E_1 \rightarrow E_2$ , da jede Instanz aus $E_1$ maximal einer Instanz aus $E_2$ zugeordnet ist
- totale funktionale Beziehung wird durch $R(E_1 [1, 1], E_2 )$ modelliert
- Beispiele:
  - partielle funktionale Beziehung: $lagert_in(Produkt[0,1],Fach[0,3])$
  - totale funktionale Beziehung: $liefert(Lieferant[0,*],Produkt[1,1])$

## Weitere Konzepte im ER Modell


# Relationaler DB-Entwurf


# Relationale Entwurfstheorie


# die Datenbanksprache SQL


# Grundlagen von Anfragen: Algebra & Kalkül


# Transaktionen, Integrität und Trigger


# Sichten und Zugriffskontrolle


# NoSQL Datenbanken