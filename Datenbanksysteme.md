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
- abhängiger Entity-Typ: Identifikation über funktionale Beziehungen (Bsp x "gehört zu" y)
- Spezialisierungs-/Generalisierungsbeziehung oder auch *IST*-Beziehung
  - E1 *IST* E2
  - entspricht semantisch einer injektiven funktionalen Beziehung
  - Attribute des Entity-Typs E2 treffen auch auf E1 zu: "vererbte" Attribute
  - nicht nur Atrributsdeklarationen vererben sich, sondern auch jeweils die aktuellen Werte für eine Instanz
  - Kardinalitätsangabe immer: $IST(E_1[1,1], E_2[0,1])$
  - Jede Instanz von E1 nimmt genau einmal an der Ist-Beziehung teil, während Instanzen des Obertyps E2 nicht teilnehmen müssen

Die Konzepte im Überblick:
| **Begriff** | **Informale Bedeutung** |
| -- | -- |
| Entity | zu repräsentierende Informationseinheit |
| Entity Typ | Gruppierung von Entitys mit gleichen Eigenschaften |
| Beziehungstyp | Gruppierung von Beziehungen zwischen Entitys |
| Attribut | datenwertige Eigenschaft eines Entitys oder einer Beziehung |
| Schlüssel | identifizierende Eigenschaft von Entitys |
| Kardinalitäten | Einschränkung von Beziehungstypen bezüglich der mehrfachen Teilnahme von Entitys an der Beziehung |
| Stelligkeit | Anzahl der an einem Beziehungstyp beteiligten Entity Typen |
| funktionale Beziehungen | Beziehungstyp mit Funktionseigenschaften |
| abhängige Entitys | Entitys, die nur abhängig von anderen Entitys existieren können |
| IST Beziehung | Spezialisierung von Entity Typen |
| Optionalität | Attribute oder Funktionale Beziehungen als partielle Funktionen |


# Datenbankentwurf
## Phasen des Datenbankentwurfs
- Datenerhaltung für mehrere Anwendungssysteme und mehrere Jahre
- Anforderungen an Entwurf:
  - Anwendungsdaten jeder Anwendung sollen aus Daten der Datenbank ableitbar sein (mögl effizient)
  - nur "vernünftige" Daten sollen gespeichert werden
  - nicht-redundante Speicherung

### Phasenmodell
Anforderungsanalyse $\leftrightarrow$ Konzeptioneller Entwurf  $\leftrightarrow$ Verteilungsentwurf $\leftrightarrow$ Logischer Entwurf $\leftrightarrow$ Datendefinition $\leftrightarrow$ Physischer Entwurf $\leftrightarrow$ Implementierung & Wartung

### Anforderungsanalyse
- Vorgehensweise: Sammeln des Informationsbedarfs in den Fachabteilungen
- Ergebnis: 
  - informale Beschreibung des Fachproblems (Texte, Tabellen, Formblätter,...)
  - Trennen der Informationen über Daten (Datenanalyse) von den Informationen über Funktionen (Funktionsanalyse)
- "Klassischer" Entwurf: nur Datenanalyse und Folgeschritte
- Funktionsentwurf: siehe Methoden des Software Engineering

### Konzeptioneller Entwurf
- erste Formale Beschreibung des Fachproblems
- Sprachmittel: semantisches Datenmodell
- Vorgehensweise:
  - Modellierung von Sichen z.B. für verschiedene Fachabteilungen
  - Analyse der vorliegenden Sichten in Bezug auf Konflikte
  - Integration der Sichten in ein Gesamtschema
- Phasen:
  - Sichtentwurf
  - Sichtanalyse
  - Sichtintegration
- Ergebnis: konzeptionelles Gesamtschema (z.B. ER Schema)

#### weiteres Vorgehen beim Entwurf
- ER-Modellierung von verschiedenen Sichten auf Gesamtinformation, z.B. für verschiedene Fachabteilungen eines Unternehmens -> konzeptueller Entwurf
- Verteilungsentwurf bei verteilter Speicherung
- Abbildung auf konkretes Implementierungsmodell -> logischer Entwurf
- Datendefinition, Implementierung und Wartung -> physischer Entwurf

#### Sichtintegration
- Analyse der vorliegenden Sichten in Bezug auf Konflikte
- Integration der Sichten in ein Gesamtschema

#### Integrationskonflikte
- Namenskonflikte: Homonyme/Synonyme
- Typkonflikte: verschiedene Strukturen für das gleiche Element
- Wertebereichskonflikte: verschiedene Wertebereiche für ein Element
- Bedingungskonflikte: z.B. verschiedene Schlüssel für ein Element
- Strukturkonflikte: gleicher Sachverhalt durch unterschiedliche Konstrukte ausgedrückt

### Verteilungsentwurf
- sollen Daten auf mehreren Rechnern verteilt vorliegen, muss Art und Weise der verteilten Speicherung festgelegt werden
  - horizontale Verteilung z.B. Kunden 1-1000 und Kunden 10001-20000
  - vertikale Verteilung z.B. Adresse in DB1, Konto in DB2

### Logischer Entwurf
- Sprachmittel: Datenmodell des ausgewählten "Realisierungs"DBMS
- Vorgehensweise
    1. (automatische) Transformation des konzeptionellen Schemas z.B. ER -> relationales Modell
    2. Verbesserung des relationalen Schemas anhand von Gütekriterien
- Ergebnis: logisches Schema

### Datendefinition
- Umsetzung des logischen Schemas in ein konkretes Schema
- Sprachmittel: DDL und DML eines DBMS
  - Datenbankdeklaration in der DDL des DBMS
  - Realisierung der Integritätssicherung
  - Definition der Benutzersichten

### Physischer Entwurf
- Ergänzen des physischen Entwurfs um Zugriffsunterstützung bzgl Effizienzverbesserung, z.B. Definition von Indexen
- Index:
  - Zugriffspfad: Datenstruktur für zusätzlichen, schlüsselbasierten Zugriff auf Tupel
  - meist als B*-Baum realisiert
- Sprachmittel: Speicherstruktursprache SSL

Indexe in SQL, z.B.: ```create index WeinIdx on WEINE (Name)```

Notwendigkeit für Zugriffspfade:
- Beispiel: Tabelle mit 100GB Daten, Festplattentransferrate ca 50MB/s
- Operation: Suchen eines Tupels (Selektion)
- Implementierung: sequentielles Durchsuchen
- Aufwand: 102.500/50 = 2048 sec ~ 34 Minuten

### Implementierung & Wartung
- Wartung
- weitere Optimierung der physischen Ebene
- Anpassung an neue Anforderungen und Systemplattformen
- Portierung auf neue Datenbankmanagementsysteme
- etc


## Kapazitätserhaltende Abbildungen
Umsetzung des konzeptionellen Schemas
- Umsetzung auf logisches Schema
- Erhaltung der Informationskapazität
- Kapazitäts**erhöhende** Abbildung: Abbildung auf R mit genau einem Schlüssel K ( K={{A},{B}} )
- Kapazitäts**vermindernde** Abbildung: Relationsschema mit einem Schlüssel
- Kapazitäts**erhaltende** Abbildung: kapazitätserhaltend mit Schlüssel beider Entity Typen im Relationsschema als neuer Schlüssel

## ER-auf-RM Abbildung
### ER Abbildung auf Relationen
- Entity-Typen und Beziehungstypen: jeweils auf Relationenschemata
- Attribute: Attribute des Relationenschemas, Schlüssel werden übernommen
- Kardinalitäten der Beziehungen: durch Wahl der Schlüssel bei den zugehörigen Relationenschemata ausgedrückt
- in einigen Fällen: Verschmelzen der Relationenschemata von Entity- und Beziehungstypen
- zwischen den verbleibenden Relationenschemata diverse Fremdschlüsselbedingungen einführen

### Abbildung von Beziehungstypen
- neues Relationenschema mit allen Attributen des Beziehungstyps, zusätzlich Übernahme aller Primärschlüssel der beteiligten Entity-Typen
- Festlegung der Schlüssel:
  - m:n-Beziehung: beide Primärschlüssel zusammen werden Schlüssel im neuen Relationenschema
  - 1:n-Beziehung: Primärschlüssel der n-Seite (bei der funktionalen Notation die Seite ohne Pfeilspitze) wird Schlüssel im neuen Relationenschema
  - 1:1-Beziehung: beide Primärschlüssel werden je ein Schlüssel im neuen Relationenschema, der Primärschlüssel wird dann aus diesen Schlüsseln gewählt
- optionale Beziehungen ([0,1] oder [0,n]) werden nicht verschmolzen
- bei Kardinalitäten [1,1] oder [1,n] (zwingende Beziehungen) Verschmelzung möglich:
  - 1:n-Beziehung: das Entity-Relationenschema der n-Seite kann in das Relationenschema der Beziehung integriert werden
  - 1:1-Beziehung: beide Entity-Relationenschemata können in das Relationenschema der Beziehung integriert werden

## Übersicht über Transformationen
| ER Konzept | wird abgebildet auf relationales Konzept |
| -- | -- |
| Entity Typ $E_i$      | Relationsenschema $R_i$ |
| Attribute von $E_i$   | Attribute von $R_i$     |
| Primärschlüssel $P_i$ | Primärschlüssel $P_i$   |
| Beziehungstyp         | Relationenschema, Attribute $P_1,P_2$ |
| dessen Attribute      | weitere Attribute       |
| 1:n                   | $P_2$ wird Primärschlüssel der Beziehung |
| 1:1                   | $P_1$ und $P_2$ werden Schlüssel der Beziehung |
| m:n                   | $P_1 \cup P_2$ wird Primärschlüssel der Beziehung |
| IST Beziehung         | $R_1$ erhält zusätzlichen Schlüssel $P_2$ |

# Relationaler Entwurf
## Zielmodell des logischen Entwurfs

Begriffe des Relationenmodells
| Begriff | Informale Bedeutung |
| -- | -- |
| Attribut | Spalte einer Tabelle |
| Wertebereich | mögliche Werte eines Attributs (auch Domäne) |
| Attributwert | Element eines Wertebereichs |
| Relationenschema | Menge von Attributen | 
| Relation | Menge von Zeilen einer Tabelle |
| Tupel | Zeile einer Tabelle |
| Datenbankschema | Menge von Relationenschemata |
| Datenbank | Menge von Relationen (Basisrelationen) |
| Schlüssel | minimale Menge von Attributen, deren Werte ein Tupel einer Tabelle eindeutig identifizieren |
| Primärschlüssel | ein beim Datenbankentwurf ausgezeichneter Schlüssel |
| Fremdschlüssel | Attributmenge, die in einer anderen Relation Schlüssel ist |
| Fremdschlüsselbedingung | alle Attributwerte des Fremdschlüssels tauchen in der anderen Relation als Werte des Schlüssels auf |

Formalisierung Relationenmodell
- Attribute und Domänen
  - $U$ nichtleere, endliche Menge: Universum
  - $A\in U$: Attribut
  - $D = {D_1,..., D_m}$ Menge endlicher, nichtleerer Mengen: jedes $D_i$: Wertebereich oder Domäne
  - total definierte Funktion $dom:U \rightarrow D$
  - $dom(A)$: Domäne von A
  - $w \in dom(A)$: Attributwert für A
- Relationenschemata und Relationen
  - $R\subseteq U$: Relationenschema
  - Relation $r$ über $R = {A_1,..., A_n}$ (kurz: $r(R)$) ist endliche Menge von Abbildungen $t:R \rightarrow \bigcup_{i=1}^{m} D_i$, Tupel genannt
  - Es gilt $t(A) \in dom(A)$ ($t(A)$ Restriktion von $t$ auf $A \in R$)
  - für $X\subseteq R$ analog $t(X)$ X-Wert von $t$
  - Menge aller Relationen über $R: REL(R) := {r | r(R)}$
- Datenbankschema und Datenbank
  - Menge von Relationenschemata $S := {R_1,..., R_p }:$ Datenbankschema
  - Datenbank über $S$: Menge von Relationen $d:={r_1,..., r_p}$, wobei $r_i (R_i)$
  - Datenbank $d$ über $S: d(S)$
  - Relation $r\in d$: Basisrelation

Integritätsbedingung
- Identifizierende Attributmenge $K:= {B_1,..., B_k } \subseteq R: \forall t_1, t_2 \in r [t_1 \not = t_2 \Rightarrow \exists B \in K: t_1(B) \not = t_2(B)]$
- Schlüssel: ist minimale identifizierende Attributmenge
- Primattribut: Element eines Schlüssels
- Primärschlüssel: ausgezeichneter Schlüssel
- Oberschlüssel oder Superkey: jede Obermenge eines Schlüssels (= identifizierende Attributmenge)
- Fremdschlüssel: $X(R_1)\rightarrow Y(R_2)$


## Relationaler DB-Entwurf
**Redundanzen** in Basisrelationen sind aus mehreren Gründen unerwünscht:
- Redundante Informationen belegen unnötigen Speicherplatz
- Änderungsoperationen auf Basisrelationen mit Redundanzen nur schwer korrekt umsetzbar: 
  - wenn eine Information redundant vorkommt, muss eine Änderung diese Information in allen ihren Vorkommen verändern
  - mit normalen relationalen Änderungsoperationen und den in
    - relationalen Systemen vorkommenden lokalen
    - Integritätsbedingungen (Schlüsseln) nur schwer realisierbar

Funktionale Abhängigkeit zwischen Attributemengen X und Y
> Wenn in jedem Tupel der Relation der Attributwert unter den X-Komponenten den Attributwert unter den Y-Komponenten festlegt.
- Unterscheiden sich zwei Tupel in den X-Attributen nicht, so haben sie auch gleiche Werte für alle Y-Attribute
- Notation für funktionale Abhängigkeit (FD, von functional dependency): X → Y

> Ziel des Datenbankentwurfs: alle gegebenen funktionalen Abhängigkeiten in Schlüsselabhängigkeiten umformen, ohne dabei semantische Information zu verlieren

## Normalformen
Schemaeigenschaften
- Relationenschemata, Schlüssel und Fremdschlüssel so wählen, dass
    1. alle Anwendungsdaten aus den Basisrelationen hergeleitet werden können,
    2. nur semantisch sinnvolle und konsistente Anwendungsdaten dargestellt werden können und
    3. die Anwendungsdaten möglichst nicht-redundant dargestellt werden.
- Hier: Forderung 3
  - Redundanzen innerhalb einer Relation: Normalformen
  - globale Redundanzen: Minimalität

Normalformen
- legen Eigenschaften von Relationenschemata fest
- verbieten bestimmte Kombinationen von funktionalen Abhängigkeiten in Relationen
- sollen Redundanzen und Anomalien vermeiden

1. Erste Normalform
    - erlaubt nur atomare Attribute in den Relationenschemata, d.h. als Attributwerte sind Elemente von Standard-Datentypen wie integer oder string erlaubt, aber keine Konstruktoren wie array oder set
2. Zweite Normalform
    - Zweite Normalform eliminiert derartige partielle Abhängigkeiten bei Nichtschlüsselattributen
    - partielle Abhängigkeit liegt vor, wenn ein Attribut funktional schon von einem Teil des Schlüssels abhängt
    - Beispielrelation in 2 NF
        - R1(Name, Weingut, Preis)
        - R2(Name, Farbe)
        - R3(Weingut, Anbaugebiet, Region)
3. Dritte Normalform
    - eliminiert (zusätzlich) transitive Abhängigkeiten
    - etwa Weingut $\rightarrow$ Anbaugebiet und Anbaugebiet $\rightarrow$ Region in Relation
    - man beachte: 3 NF betrachtet nur Nicht-Schlüsselattribute als Endpunkt transitiver Abhängigkeiten
    - Beispielrelation in 3NF, transitive Abhängigkeit in R3, d.h. R3 verletzt 3NF
      - R3_1(Weingut, Anbaugebiet)
      - R3_2(Anbaugebiet, Region)

> Dritte Normalform: 
> - $A \in R$ heißt transitiv abhängig von X bezüglich F genau dann, wenn es ein $Y\subseteq R$ gibt mit $X \rightarrow Y, Y \not\rightarrow X, Y \rightarrow A, A \not\in XY$
> - erweitertes Relationenschema $R=(R, \bf{K})$ ist in 3 NF bezüglich F genau dann, wenn $\not\exists A \in R$:
>   - A ist Nicht-Primattribut in R
>   - $\wedge A$ transitiv abhängig von einem $K\in \bf{K}$ bezüglich $F_i$.
>   - Nicht-Primattribut: A ist in keinem Schlüssel von R enthalten

> Boyce-Kodd-Normalform (Verschärfung der 3NF): Eliminierung transitiver Abhängigkeiten auch zwischen Primattributen
- $\not\exists A \in R$: A transitiv abhängig von einem $K\in\bf{K}$ bezüglich F

Minimalität
- Global Redundanzen vermeiden
- andere Kriterien (wie Normalformen) mit möglichst wenig Schemata erreichen
- Beispiel: Attributmenge ABC, FD-Menge ${A \rightarrow B, B \rightarrow C}$

Übersicht
| Kennung | Schemaeigenschaft | Kurzcharakteristik |
| -- | -- | -- |
| | 1 NF | nur atomare Attribute |
| | 2 NF | keine partielle Abhängigkeit eines Nicht-Primattributes von einem Schlüssel |
| S1 | 3 NF | keine transitive Abhängigkeit eines Nicht-Primattributs von einem Schlüssel |
| | BCNF | keine transitive Abhängigkei eines Attributes von einem Schlüssel |
| S2 | Minimalität | minimale Anzahl von Relationsschemata, die die anderen Eigenschaften erfüllt |

## Transformationseigenschaften
- bei einer Zerlegung einer Relation in mehrere Relationen ist darauf zu achten, dass
    1. nur semantisch sinvolle und konsistente Anwendungsdaten dargestellt (Abhängigkeitstreue) und
    2. alle Anwendungsdaten aus den Basisrelationen hergeleitet werden können (Verbundtreue)
- Abhänggikeitstreue (Kennung T1)
  - alle gegebenen Abhängigkeiten sind durch Schlüssel repräsentiert
  - eine Menge von Abhängigkeiten kann äquivalent in eine zweite Menge von Abhängigkeiten transformiert werden
  - spezieller: in die Menge der Schlüsselabhängigkeiten, da diese vom Datenbanksystem effizient überprüft werden kann
    - die Menge der Abhängigkeiten soll äquivalent zu der Menge der Schlüsselbedingungen im resultierenden Datenbankschema sein
    - Äquivalenz sichert zu, dass mit den Schlüsselabhängigkeiten semantisch genau die gleichen Integritätsbedingungen ausgedrückt werden wie mit den funktionalen oder anderen Abhängigkeiten vorher
  - S charakterisiert vollständig F (oder: ist abhängigkeitstreu bezüglich F) genau dann, wenn $F\equiv \{K\rightarrow R | (R,\bf{K})\in S, K\in\bf{K}\}$
- Verbundtreue (Kennung T2)
  - Originalrelationen können durch den Verbund der Basisrelationen wiedergewonnen werden
  - zur Erfüllung des Kriteriums der Normalformen müssen Relationenschemata teilweise in kleinere Relationenschemata zerlegt werden
  - für Beschränkung auf „sinnvolle“ Zerlegungen gilt Forderung, dass die Originalrelation wieder aus den zerlegten Relationen mit dem natürlichen Verbund zurückgewonnen werden kann
    - Zerlegung des Relationenschemas $R = ABC$ in $R_1 = AB$ und $R_2 = BC$
    - Dekomposition bei Vorliegen der Abhängigkeiten $F = \{A \rightarrow B, C \rightarrow B\}$ ist nicht verbundtreu
    - dagegen bei Vorliegen von $F′ = \{A \rightarrow B, B \rightarrow C\}$ verbundtreu

> Verbundtreue: Die Dekomposition einer Attributmenge $X$ in $X_1,..., X_p$ mit $X = \bigcup_{i=1}^p X_i$ heißt verbundtreu ($\pi \bowtie$-treu, lossless) bezüglich einer Menge von Abhängigkeiten F über X genau dann, wenn $\forall r \in SAT_X(F) : \pi_{X_1}(r) \bowtie ··· \bowtie \pi_{X_p}(r) = r$ gilt.

## Weitere Abhängigkeiten
- Mehrwertige Abhängigkeit (kurz: MVD)
  - innerhalb einer Relation r wird einem Attributwert von X eine Menge von Y-Werten zugeordnet, unabhängig von den Werten der restlichen Attribute $\rightarrow$ Vierte Normalform
  - Folge der 1NF: Mehrwertige Abhängigkeiten erzeugen Redundanz
    - eine (oder mehrere) Gruppe von Attributwerten ist von einem Schlüssel bestimmt, unabhängig von anderen Attributen
    - Resultat: Redundanz durch Bildung aller Kombinationen
  - wünschenswerte Schemaeigenschaft bei Vorliegen von MVDs: vierte Normalform
    - fordert die Beseitigung derartiger Redundanzen: keine zwei MVDs zwischen Attributen einer Relation
    - Elimination der rechten Seite einer der beiden mehrwertigen Abhängigkeiten,
    - linke Seite mit dieser rechten Seite in neue Relation kopiert
- Verbundabhängigkeit (kurz: JD)
  - R kann ohne Informationsverlust in $R_1,..., R_p$ aufgetrennt werden: $\bowtie [R_1,..., R_p]$
- Inklusionsabhängigkeit (kurz: IND)
  - auf der rechten Seite einer Fremdschlüsselabhängigkeit nicht unbedingt der Primärschlüssel einer Relation

> Vierte Normalform: erweitertes Relationenschema $R = (R, \bf{K})$ ist in vierter Normalform (4NF) bezüglich M genau dann, wenn für alle $X\rightarrow\rightarrow Y \in M^+$ gilt: $X\rightarrow\rightarrow Y$ ist trivial oder $X\supseteq K$ für ein $K\in\bf{K}$



# die Datenbanksprache SQL


# Grundlagen von Anfragen: Algebra & Kalkül


# Transaktionen, Integrität und Trigger


# Sichten und Zugriffskontrolle


# NoSQL Datenbanken