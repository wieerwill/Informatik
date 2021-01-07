# Relationenmodell
## Welche der folgenden Aussagen über das Relationenmodell sind korrekt?
- [X] Das Relationenschema beschreibt den "Kopf der Tabelle", d.h. die Attribute, welche alle Tupel miteinander teilen.
- [X] Im Vergleich zu Tabellen sind Relationen duplikatfrei.
- [ ] Ein Attribut ist eine Zeile in der Relation, ein Tupel ist wiederum eine Spalte der Relation.
- [X] Tupel bestehen aus Attributwerten, wobei die zugehörigen Attribute vom Relationenschema vorgegeben sind.
- [ ] Unter dem Relationenschema werden alle Tupel zusammengefasst. Die Attribute werden von der Relation beschrieben.
- [ ] Relationen können Duplikate enthalten, d.h. mehrere völlig gleiche Einträge sind möglich.
- [X] Ein Attribut ist eine Spalte in der Relation, ein Tupel ist wiederum eine Zeile der Relation.

## Welche der folgenden Aussagen über Eigenschaften von Schlüsseln in Relationen sind korrekt?
- [X] Schlüssel dienen dazu, Tupel anhand ihrer Attribute eindeutig zu identifizieren, d.h. zwei Tupel mit gleichem Schlüssel sind nicht erlaubt.
- [X] Attribute können Schlüssel sein, dabei darf immer nur ein einzelnes Attribut als Schlüssel definiert sein.
- [ ] Attribute können Schlüssel sein, dabei sind auch kombinierte Attribute als Schlüssel erlaubt.
- [ ] Tupel können Schlüssel sein, dabei darf immer nur ein einzelnes Tupel als Schlüssel definiert sein.
- [ ] Schlüssel werden bei einer grafischen Darstellung üblicherweise durch Einkreisen gekennzeichnet.
- [ ] Tupel können Schlüssel sein, dabei sind auch kombinierte Tupel als Schlüssel erlaubt.
- [ ] Schlüssel werden verwendet, um Tupel in Relationen eindeutig wiederzufinden, d.h., Anfragen beziehen sich immer auf Schlüssel der Tupel.
- [X] Schlüssel werden bei einer grafischen Darstellung üblicherweise durch Unterstreichung gekennzeichnet.
- [ ] Schlüssel werden bei einer grafischen Darstellung üblicherweise durch ein Schlüsselsymbol gekennzeichnet.

## Welche der folgenden Aussagen über Fremdschlüssel sind korrekt?
- [ ] Fremdschlüssel sind niemals (Primär-)Schlüssel der eigenen Relation.
- [ ] Fremdschlüssel sind in jeder Relation notwendig, da sonst "einsame" Relationen entstehen, die sich mit keiner fremden Relation vereinen lassen.
- [X] Fremdschlüssel verweisen ausschließlich auf Attribute, die (Primär-)Schlüssel sind.
- [ ] Fremdschlüssel sind auch automatisch (Primär-)Schlüssel der eigenen Relation.
- [X] Fremdschlüssel gehören zu den Integritätsbedingungen.
- [ ] Fremdschlüssel verweisen immer auf beliebige Attribute fremder Relationen (d.h. nicht auf Attribute der eigenen Relation).
- [X] Fremdschlüssel können (Primär-)Schlüssel der eigenen Relation sein, dies ist aber nicht zwingend notwendig.
- [X] Fremdschlüssel sind optional, d.h. es kann Relationen ohne Fremdschlüssel geben.

## Welche Fachwörter gehören zum Relationenmodell?
- [X] Attribut
- [X] Wertebereich
- [ ] Wertepaar
- [X] Tupel
- [ ] Datensatz
- [X] Relation
- [ ] Eintrag
- [ ] Zeile

# Datendefinition
## Welche der folgenden Aussagen sind korrekt?
- [x] Um Tabellen zu löschen, wird der Befehl "drop table" genutzt.
- [ ] Beim Erstellen von Tabellen ist der Wertebereich einer Spalte optional anzugeben, ansonsten entscheidet SQL selbst.
- [ ] Beim Löschen einer Tabelle bleibt das Relationenschema in der Datenbank erhalten, da nur die Daten (Tupel) entfernt werden.
- [ ] Mit delete table können bestehende Tabellen gelöscht werden.
- [x] Optionale Anweisungen im create table Befehl (wie z.B. Integritätsbedingungen) werden in eckigen Klammern [ ] angegeben, beispielsweise [foreign key] für Fremdschlüssel.

## Welche der folgenden Aussagen über Datentypen sind korrekt?
- [ ] Der Datentyp `varchar(10)` erlaubt nur einstellige Zahlen von 0 bis 9.
- [ ] Der Datentyp `varchar(5)` erlaubt nur exakt 5 Zeichen, um z.B. bei der Postleitzahl keine Zahl mit nur vier oder sechs Ziffern zu erlauben.
- [x] Der Datentyp `varchar(100)` erlaubt maximal 100 Zeichen.

## Welche der folgenden Aussagen über Nullwerte sind korrekt?
- [x] Ein Tupel, welches nur aus Null-Werten besteht, ist in SQL aufgrund der Primärschlüsseleigenschaft nicht möglich.
- [ ] Null als SQL Datentyp wird als leerer String interpretiert.
- [ ] Mittels not null kann ausgeschlossen werden, dass ein Datentyp auf 0 gesetzt wird (insbesondere wichtig bei Division, da sonst durch 0 geteilt würde).
- [x] Primärschlüssel müssen nicht mit not null gekennzeichnet werden, da sie per Definition immer einen Wert haben.
- [x] Null in SQL bedeutet, dass ein Attributwert nicht eingetragen wurde.

## Welche Schlüsselwörter bzw. Zusätze können in einer Anweisung zum Erstellen einer Tabelle vorkommen?
- [ ] REQUIRED
- [ ] OPTIONAL
- [x] FOREIGN KEY
- [x] UNIQUE
- [ ] UNKNOWN
- [x] PRIMARY KEY
- [x] NOT NULL

## Welche der SQL-Anweisungen definiert eine Tabelle?
- [x] `CREATE  TABLE  Tabellenname  (  Attribut1  Wertebereich1 ,  Attribut2 Wertebereich2 ,  . . . )`
- [ ] `CREATE  Tabellenname  (  Attribut1  Wertebereich1 ,  Attribut2  Wertebereich2 ,  . . . )`
- [ ] `TABLE  Tabellenname  CREATE  WITH  ( Attribut1  Wertebereich1 ,  . . .  )`

# Grundoperationen
## Welche der folgenden Aussagen über die Relationenalgebra sind korrekt?
- [x] Durch Anfrageoperationen können aus vorhandenen Relationen neue Ergebnistabellen erstellt werden.
- [ ] Operationen der Relationenalgebra haben eine feste Ausführungsreihenfolge (wie z.B. in der Mathematik "Punkt vor Strichrechnung" erfolgt). So wird beispielsweise eine Projektion oder Selektion immer vor einem Verbund berechnet, damit der Verbund auf somit reduzierten Relationen schneller ein Ergebnis liefern kann.
- [ ] Operationen der Relationenalgebra beschreiben Inhalte der Datenbank, wie beispielsweise Tupel.
- [x] Anfrageoperationen der Relationenalgebra ermöglichen das "Rechnen mit Tabellen".

## An der Universität gibt es eine Relation mit den relevanten Daten aller Studierenden wie Matrikelnummer, Name, Email, Fakultät, Studiengang usw. Der Dekan der Fakultät IA möchte zum Sommerfest einladen und die Studierenden seiner Fakultät per Mail informieren. Für die Suche der Mail-Adressen benötigt er folgende Operation/en der Relationenalgebra:
- [ ] nur die Projektion
- [x] die Selektion und die Projektion
- [ ] nur die Selektion
- [ ] die Selektion und die Vereinigung

## Welche Operationen der Relationenalgebra verknüpfen zwei Relationen zu einer Ergebnisrelation, deren Schema mehr Attribute als jedes einzelne Schema der Ausgangsrelationen enthält?
- [x] natürlicher Verbund
- [ ] Selektion
- [ ] Vereinigung
- [x] Kreuzprodukt

## Welche Operationen der Relationenalgebra liefern im Allgemeinen eine Ergebnisrelation mit einer geringeren Anzahl von Tupeln als die Ausgangsrelation(en)?
- [x] Selektion
- [x] Differenz
- [ ] Kreuzprodukt
- [x] Durchschnitt

## Welche der folgenden Aussagen über Operatoren sind korrekt?
- [x] Die Selektion wählt Zeilen (Tupel) der Tabelle aus, während man über die Projektion Spalten (bestimmte Attribute) anfragen kann.
- [ ] Der Projektionsoperator entfernt standardmäßig keine doppelten (gleichen) Tupel in der Ergebnisrelation.
- [x] Mit der Umbenennung lassen sich Attribute umbenennen, was gerade für Mengenoperationen sinnvoll ist.
- [x] Der Selektionsoperator liefert niemals doppelte (gleiche) Tupel in der Ergebnisrelation zurück.
- [x] Unäre Operationen erhalten eine Tabelle als Eingabe und liefern eine einzelne Tabelle als Ergebnis zurück.
- [x] Ein natürlicher Verbund über zwei Tabellen verknüpft diese über ihre gemeinsamen Attribute, da diese üblicherweise den gleichen Datentyp teilen.
- [ ] Die Selektion wählt Spalten (bestimmte Attribute) der Tabelle aus, während man über die Projektion einzelne Zeilen (Tupel) anfragen kann.
- [ ] Beim natürlichen Verbund werden Tupel ohne Partner beim Verknüpfen zweier Tabellen mit Nullwerten in den anderen Attributen aufgefüllt, damit keine Daten im Ergebnis verloren gehen.
- [ ] Wird die Umbenennung als Operator angewandt, ist die Namensänderung eines Attributes dauerhaft in der Datenbank gespeichert.
- [x] Die Reihenfolge der Operatoren (Selektion vor Projektion oder umgekehrt) bei einer Kombination hat keinen Einfluss auf die Ergebnisrelation, nur auf die Performance (Geschwindigkeit) der Anfrage (immer vorausgesetzt, es treten keine Konflikte mit dem Schema auf, z.B. wenn ein nötiges Attribut der Selektionsbedingung vorher entfernt wird).

# SQL
## Welche Schlüsselwörter der SQL-Anfragesprache gehören unbedingt (mindestens) zur Formulierung einer Anfrage?
- [ ] `SELECT,  FROM,  NATURAL JOIN`
- [X] `SELECT,  FROM`
- [ ] `SELECT,  FROM,  WHERE`
- [ ] `SELECT,  DISTINCT,  FROM`

## Alle Kunden, die die Reise mit der Nummer 4712 gebucht haben, sollen mit einer Nachricht über Veränderungen im Reiseverlauf informiert werden. Welche der SQL-Anfragen liefert eine korrekte Liste von Mail-Adressen der Kunden?
- [X] `SELECT Mail FROM Kunde, Buchung WHERE Kunde.KdNr = Buchung.KdNr AND ReiseNr = 4712`
- [ ] `SELECT Mail FROM Kunde, Buchung WHERE ReiseNr = 4712`
- [X] `SELECT Mail FROM Kunde NATURAL JOIN Buchung WHERE ReiseNr = 4712`

# Änderungsoperationen
## Ein Geldinstitut hat zur Verwaltung der Kundendaten eine Relation mit dem Schema 
`R( Konto , Kunde , Guthaben , Kreditrahmen )`  
Eine Rechnung soll bezahlt werden. Der Kunde mit dem Konto A soll 150 Euro an die Firma mit dem Konto X überweisen. Welche Aktionen müssen auf der Datenbank des Geldinstituts ausgeführt werden?

- [x] Änderung (UPDATE) des Guthabens von Konto A und Änderung (UPDATE) des Guthabens von Konto X.
- [ ] Änderung (UPDATE) des Guthabens von Konto A und Einfügen (INSERT) auf Konto X.
- [ ] Löschen (DELETE) des Betrages vom Guthaben des Kontos A und Einfügen (INSERT) auf Konto X.

## Angestellte einer Firma sollen eine Gehaltserhöhung von 5 Prozent bekommen. Allerdings soll davon nur die Entwicklungsabteilung profitieren. Welche der folgenden SQL-Anweisungen realisiert genau das?

- [ ] `UPDATE  Angestellte SET Gehalt = Gehalt * 1.05` 
- [ ] `UPDATE  Gehalt SET Gehalt = Gehalt * 1.05`
- [x] `UPDATE  Angestellte SET Gehalt = Gehalt * 1.05 WHERE  Abteilung = ‘Entwicklung‘`
- [ ] `UPDATE  TABLE  Angestellte SET Gehalt = Gehalt * 1.05 WHERE  Abteilung = ‘Entwicklung‘`

## Welche der folgenden SQL-Anweisungen sind korrekte Einfüge-Anweisungen für die Tabelle Angestellte mit dem Schema (Name, Vorname, Qualifikation, Abteilung)?
Hinweis: Neue Mitarbeiter werden in der Tabelle Neueinstellungen mit dem Schema (Name, Vorname, Geburtsdatum, Adresse, Beruf) erfasst und später Abteilungen zugeordnet und bei den Angestellten eingetragen.  

- [x] `INSERT INTO Angestellte (Name, Vorname, Abteilung) VALUES (‘Franke‘, ‘Felix‘, ‘Labor‘)`
- [ ] `INSERT INTO TABLE Angestellte VALUES (‘Franke‘, ‘Felix‘, ‘Chemiker‘, ‘Labor‘)`
- [x] `INSERT INTO Angestellte VALUES (‘Franke‘, ‘Felix‘, ‘Chemiker‘, ‘Labor‘)`
- [ ] `INSERT INTO Angestellte VALUES (‘Franke‘, ‘Felix‘, ‘Labor‘)`
- [x] `INSERT INTO Angestellte (Name, Vorname, Abteilung) (SELECT Name, Vorname, ‘Labor’ FROM Neueinstellungen WHERE Beruf = ‘Chemiker’)`
- [x] `INSERT INTO Angestellte (Name, Vorname, Qualifikation, Abteilung) VALUES (‘Franke‘, ‘Felix‘, ‘Chemiker‘, ‘Labor')`

# Datenbankmodellen
## Welche der folgenden Aussagen über Datenbankmodelle sind korrekt?
- [ ] SQL gehört mit seinen CREATE TABLE, UPDATE und INSERT Operationen zu den klassischen Entwurfsmodellen (wie auch das ER-Diagramm), da Änderungen im Entwurf leicht umsetzbar sind.
- [x] SQL ist wie das Relationenmodell ein sogenanntes Realisierungsmodell, da Anfragen in SQL (SELECT... FROM...) konkrete Ergebnisse aus der Datenbank liefern.
- [ ] Datenbankmodelle sind besonders gut für das Beschreiben großer Datenmengen mit dynamischer Struktur geeignet, da sich häufige Änderungen des Schemas zentral verwalten lassen.
- [x] Das Datenbankmodell beschreibt die Datenbank, bzw. das Schema der Datenbank.
- [ ] Jedes Datenbankmanagementsystem (DBMS) verwendet exakt ein Datenbankmodell, welches sämtliche Details über die Art der Implementierung theoretisch beschreibt.

## Was wird von Datenbankmodellen beschrieben?
- [x] Statische Eigenschaften, wie Objekte (z.B. Relationen)
- [x] Integritätsbedingungen (z.B. Primärschlüssel)
- [ ] Statistische Eigenschaften (z.B. Größe des Datenbestandes)
- [ ] Redundanz, wie Sicherungskopien (z.B. Tabellen)
- [ ] Progressive Eigenschaften (z.B. Tupel)
- [x] Dynamische Eigenschaften, wie Operatoren (z.B. Selektion)

# Entities und Beziehungen
## Welche der folgenden Aussagen über Entities und Entity-Typen sind korrekt?
- [x] Entity-Typen werden graphisch durch Rechtecke gekennzeichnet.
- [ ] Entities werden graphisch durch Kreise gekennzeichnet.
- [ ] Entities beschreiben Objekte einer Datenbank genauer. Beispielsweise könnten bei einer Student-Relation typischerweise die Entities Matrikelnummer, Name oder Adresse entstehen.
- [x] Entity-Typen sind Objekte in der Datenbank und können daher im Allgemeinen mit Relationen des Relationenmodells gleichgesetzt werden.
- [ ] Entities können im Gegensatz zu Werten direkt dargestellt werden, wie z.B. ein Student oder Dozent, welcher direkt als Tupel in der Datenbank eingefügt wurde.
- [ ] Entities werden graphisch durch Rauten gekennzeichnet.
- [x] Entity-Typen verallgemeinern Entities. So könnte ein Entity "Datenbanksysteme" des Entity-Typs "Vorlesung" diese konkretisieren.

## Welche der folgenden Aussagen über Attribute sind korrekt?
- [x] Wie auch im Relationenmodell wird der Primärschlüssel (Attribut) des Entities graphisch durch Unterstreichung gekennzeichnet.
- [x] Attribute modellieren Eigenschaften von Entities, wie die Farbe eines Weines oder das Alter eines Studierendens.
- [x] Im Gegensatz zum Relationenmodell kann beim ER-Modell nur ein einzelnes Attribut eines Entities Schlüssel sein.
- [x] Aus möglichen Schlüsselkandidaten wird der Primärschlüssel eines Entities gebildet.
- [x] Ein Attribut des ER-Modells kann in ein Attribut einer Relation überführt werden.
- [x] Im Gegensatz zum Entity-Typ mit Entities und dem Relationship-Typ mit Relationships gibt es im ER-Modell standardmäßig zu Attributen keinen Attribut-Typ.

## Welche der folgenden Aussagen über Beziehungen und Beziehungstypen sind korrekt?
- [x] Relationships können ebenso wie Entities eigene Attribute haben.
- [ ] Ein Beziehungstyp verbindet mindestens zwei Entitiy-Typen miteinander, niemals jedoch einen Entity-Typ mit sich selbst (n>=2).
- [x] Die Ausprägung einer Beziehung wird als Teilmenge des Kreuzprodukts der teilnehmenden Entities dargestellt.
- [ ] Relationships entstehen immer zwischen einzelnen Attributen (wie z.B. der Matrikelnummer einer Studenten-Relation und Prüfung-Relation) und können somit Fremdschlüssel-Bedingungen umsetzen.

# Beziehungstypen
## Welche der folgenden Aussagen zu/über Beziehungstypen sind korrekt?
- [x] Binäre Beziehungstypen treten häufiger auf als mehrstellige Beziehungstypen.
- [ ] Binäre Beziehungstypen sind einfacher zu modellieren und zu verstehen als mehrstellige Beziehungstypen.
- [x] Angaben zur Kardinalität bei einem Beziehungstyp R( E1 [0,1], E2 [1,*] ) ersetzen die Charakteristik N:1.
- [ ] Mehrstellige Beziehungstypen lassen sich gleichwertig durch mehrere binäre Beziehungstypen darstellen.
- [x] Jede Beziehung eines binären Beziehungstyps stellt einen Zusammenhang zwischen zwei Objekten der beiden beteiligten Entity-Typen dar.
- [ ] Beziehungstypen lassen sich durch Angaben zur Funktionalität, wie 1:1, 1:N oder M:N, vollständig charakterisieren.

## Es gibt einen Beziehungstyp arbeiten zwischen Mitarbeitern und Projekten. Dieser sei wie folgt charakterisiert:
`arbeiten ( Mitarbeiter [0, 1], Projekte [2, 10] )`
Welche Aussagen lassen sich daraus ableiten?
- [ ] Wählen Sie eine oder mehrere Antworten:
- [x] Es gibt Mitarbeiter, die an keinem Projekt arbeiten.
- [x] Ein Projekt hat wenigstens 2 Mitarbeiter.
- [ ] Ein Mitarbeiter arbeitet an genau einem Projekt.
- [ ] Jeder Mitarbeiter arbeitet an mindestens 2 Projekten, aber höchstens an 10 Projekten.
- [ ] Es muss mindestens 2 Projekte geben.
- [x] Ein Projekt hat maximal 10 Mitarbeiter.
- [x] Ein Mitarbeiter arbeitet nur an einem Projekt. Nur so kann man sich voll konzentrieren.

# Weiteren Konzepten
## In einem Unternehmen werden zur Modellierung der Geschäftsabläufe und zur Datensammlung die Entity-Typen Fahrzeuge, LKW, PKW und Baufahrzeuge definiert. Welche Aussagen sind zutreffend?
- [x] Die Entity-Typen sind durch IST-Beziehungen miteinander "verbunden".
- [ ] Die Entity-Typen sind Teile eines mehrstelligen Beziehungstyps.
- [x] Es gibt Objekte (Entitys), die mehr als einer Objektmenge angehören.
- [ ] Zwischen Fahrzeugen und den anderen Entity-Typen besteht jeweils ein 1:N-Beziehungstyp.
- [x] Es kann Fahrzeuge geben, die zu keinem der anderen Entity-Typen eine Beziehung haben.
- [ ] Hat das Unternehmen je 5 LKW, PKW und Baufahrzeuge, dann hat es genau 15 Fahrzeuge.

## Es gibt zwei Entity-Typen: Zeitungen und (Zeitungs-)Ausgaben. Welche Aussagen sind zutreffend?
- [ ] Jede Zeitung hat genau eine Ausgabe.
- [x] Jede Ausgabe gehört zu genau einer Zeitung.
- [ ] Die Zeitungen sind ein abhängiger Entity-Typ, denn ohne Ausgaben kann die Zeitung nicht existieren.
- [x] Die Ausgaben sind abhängig von der Existenz der Zeitung, d.h. die Ausgaben sind ein abhängiger Entity-Typ.
- [x] Eine Zeitung hat mehrere Ausgaben.
- [ ] Eine Ausgabe kann zu einer Zeitung gehören, muss es aber nicht.

# Phasen des Datenbankentwurfs
## Welche der folgenden Aussagen über generelle Anforderungen an den Datenbankentwurf sind richtig?
- [ ] Vernünftigerweise werden Daten so gespeichert, dass sie direkt zugreifbar sind und keine Ableitung aus anderen Daten erfordern.
- [x] Daten sollen möglichst nicht-redundant gespeichert werden, d.h. nicht mehrfach, um Konsistenzprobleme wie das "Vergessen" von Änderungen zu vermeiden.
- [x] Anwendungsdaten sollen sich aus Daten der Datenbank möglichst effizient ableiten lassen, z.B. der Gewinn aus den Bestellungen.
- [ ] Daten sollen möglichst redundant gespeichert werden, d.h. mehrfach, um die Erreichbarkeit und Verfügbarkeit zu verbessern (z.B. wenn bei einer Naturkatastrophe ein Teil der Datenbank nicht mehr erreichbar ist).

## Welche der folgenden Aussagen über das Phasenmodell sind korrekt?
- [x] Das ER-Modell kann in der Phase des konzeptuellen Entwurfs genutzt werden.
- [ ] Die Anforderungsanalyse ist eine optionale erste Phase und wird nur dann eingesetzt, wenn eine völlig neue Datenbank erstellt werden soll.
- [ ] SQL kann als Modell für den konzeptuellen Entwurf eingesetzt werden, dank Befehlen wie CREATE TABLE, UPDATE, INSERT usw.
- [x] In der konzeptuellen Entwurfsphase werden Sichten behandelt, die festlegen, welcher Datenbanknutzer später Zugang zu welchen Daten erhalten soll. Dabei werden auch Konflikte zwischen den Sichten betrachtet.
- [x] Der Verteilungsentwurf ist optional und wird dann eingesetzt, wenn eine Datenbank über mehrere Knoten (Orte, Systeme, etc.) verteilt werden soll.

