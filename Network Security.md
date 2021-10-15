# Einleitung
## Was ist eine Bedrohung in einem Kommunikationsnetz?
- Abstrakte Definition
    - Eine Bedrohung in einem Kommunikationsnetz ist ein mögliches Ereignis oder eine Folge von Aktionen, die zu einer Verletzung eines oder mehrerer Sicherheitsziele führen können.
    - Die tatsächliche Realisierung einer Bedrohung wird als Angriff bezeichnet.
- Beispiele
    - Ein Hacker bricht in einen Firmencomputer ein
    - Offenlegung von E-Mails während der Übertragung
    - Jemand ändert Finanzbuchhaltungsdaten
    - Ein Hacker, der eine Website vorübergehend außer Betrieb setzt
    - Jemand, der Dienstleistungen in Anspruch nimmt oder Waren im Namen anderer bestellt
- Was sind Sicherheitsziele?
    - Sicherheitsziele können definiert werden
    - in Abhängigkeit von der Anwendungsumgebung oder
    - auf eine allgemeinere, technische Weise

## Sicherheitsziele in Abhängigkeit von der Anwendungsumgebung
- Bankwesen
    - Schutz vor betrügerischen oder versehentlichen Änderungen von Transaktionen
    - Identifizierung von Kunden bei Privatkundentransaktionen
    - Schutz von PINs vor Offenlegung
    - Sicherstellung der Privatsphäre der Kunden
- Elektronischer Handel
    - Sicherstellung der Herkunft und Integrität von Transaktionen
    - Schutz der Privatsphäre von Unternehmen
    - Rechtsverbindliche elektronische Signaturen für Transaktionen bereitstellen
- Regierung
    - Schutz vor Offenlegung sensibler Informationen
    - Bereitstellung elektronischer Signaturen für Regierungsdokumente
- Öffentliche Telekommunikationsanbieter
    - Beschränken Sie den Zugang zu Verwaltungsfunktionen auf autorisiertes Personal
    - Schutz vor Dienstunterbrechungen
    - Schutz der Privatsphäre der Teilnehmer
- Firmen-/Privatnetzwerke
    - Schutz der Privatsphäre von Unternehmen/Personen
    - Sicherstellung der Authentizität von Nachrichten
- Alle Netzwerke
    - Verhinderung des Eindringens von außen (wer will schon Hacker?)
- Manchmal werden Sicherheitsziele auch als Sicherheitsvorgaben bezeichnet

## Sicherheitsziele technisch definiert
- **Vertraulichkeit (Confidentiality)**
    - Übertragene oder gespeicherte Daten sollten nur einem bestimmten Personenkreis zugänglich gemacht werden.
    - Die Vertraulichkeit von Entitäten wird auch als Anonymität bezeichnet.
- **Integrität der Daten (Data Integrity)**
    - Es sollte möglich sein, jede Veränderung von Daten zu erkennen.
    - Dies setzt voraus, dass der Ersteller bestimmter Daten identifiziert werden kann.
- **Rechenschaftspflicht (Accountability)**
    - Es sollte möglich sein, die für ein Kommunikationsereignis verantwortliche Stelle zu identifizieren.
- **Verfügbarkeit (Availability)**
    - Die Dienste sollten verfügbar sein und korrekt funktionieren.
- **Kontrollierter Zugang (Controlled Access)**
    - Nur autorisierte Stellen sollten auf bestimmte Dienste oder Informationen zugreifen können.

## Technisch definierte Bedrohungen
- **Maskerade (oder Man-in-the-Middle-Angriff, Masquerade)**
    - Eine Entität gibt sich als eine andere Entität aus
- **Lauschangriff (Eavesdropping)**
    - Eine Entität liest Informationen, die sie nicht lesen soll
- **Verletzung der Berechtigung (Authorization Violation)**
    - Eine Entität nutzt einen Dienst oder Ressourcen, für die sie nicht vorgesehen ist
- **Verlust oder Veränderung** von (übertragenen) Informationen (Loss or Modification of (transmitted) Information)
    - Daten werden verändert oder zerstört
- **Verweigerung von Kommunikationsakten (Denial of Communication Acts, Repudiation)**
    - Ein Unternehmen leugnet fälschlicherweise seine Teilnahme an einer Kommunikationshandlung
- **Fälschung von Informationen (Forgery of Information)**
    - Ein Unternehmen erstellt neue Informationen im Namen eines anderen Unternehmens
- **Sabotage (oder Denial-of-Service-Angriffe)**
    - Jede Aktion, die darauf abzielt, die Verfügbarkeit und/oder das ordnungsgemäße Funktionieren von Diensten oder Systemen zu beeinträchtigen.

## Bedrohungen und technische Sicherheitsziele
Diese Bedrohungen werden oft kombiniert, um einen Angriff durchzuführen!

| Technische Sicherheitsziele | Maskerade | Abhören | Autorisierungsverletzung | Verlust oder Modifikation von (übertragenen) Informationen | Denial of Communication-Aktionen | Fälschung von Informationen | Sabotage (z.B. durch Überlastung) |
| --------------------------- | --------- | ------- | ------------------------ | ---------------------------------------------------------- | -------------------------------- | --------------------------- | --------------------------------- |
| Vertraulichkeit             | x         | x       | x                        |
| Datenintegrität             | x         |         | x                        | x                                                          | x                                | x                           |
| Rechenschaftspflicht        | x         |         | x                        |                                                            | x                                | x                           |                                   |
| Verfügbarkeit               | x         |         | x                        | x                                                          |                                  |                             | x                                 |  |
| Kontrollierter Zugriff      | x         |         | x                        |                                                            |                                  | x                           |                                   |



## Analyse der Netzwerksicherheit
- Um geeignete Gegenmaßnahmen gegen Bedrohungen ergreifen zu können, müssen diese für eine gegebene Netzkonfiguration angemessen bewertet werden.
- Daher ist eine detaillierte Netzsicherheitsanalyse erforderlich, die
    - das Risikopotenzial der allgemeinen Bedrohungen für die ein Netz nutzenden Einheiten bewertet und
    - den Aufwand (Ressourcen, Zeit usw.) abschätzt, der zur Durchführung bekannter Angriffe erforderlich ist.
    - Achtung! Es ist im Allgemeinen unmöglich, unbekannte Angriffe zu bewerten!
- Eine detaillierte Sicherheitsanalyse einer bestimmten Netzkonfiguration / spezifischen Protokollarchitektur
    - kann auch erforderlich sein, um die Finanzkontrolleure eines Unternehmens davon zu überzeugen, Mittel für Sicherheitsverbesserungen bereitzustellen, und
    - kann besser nach den feinkörnigeren Angriffen auf der Nachrichtenebene strukturiert werden.

## Angriffe auf die Kommunikation auf der Nachrichtenebene
- Passive Angriffe
    - Lauschangriff
- Aktive Angriffe
    - Verzögerung von PDUs (Protocol Data Units)
    - Wiederholung von PDUs
    - Löschung von PDUs
    - Modifikation von PDUs
    - Einfügung von PDUs
- Die erfolgreiche Durchführung eines der oben genannten Angriffe erfordert
    - Es gibt keine erkennbaren Nebeneffekte auf andere Kommunikationen (Verbindungen/verbindungslose Übertragungen)
    - Es gibt keine Nebenwirkungen auf andere PDUs der gleichen Verbindung/verbindungslosen Datenübertragung zwischen den gleichen Entitäten
- Eine Sicherheitsanalyse einer Protokollarchitektur muss diese Angriffe entsprechend den Schichten der Architektur analysieren

## Schutzmaßnahmen gegen Bedrohungen der Informationssicherheit
- Physische Sicherheit
    - Schlösser oder andere physische Zugangskontrollen
    - Manipulationssicherung empfindlicher Geräte
    - Umweltkontrollen
- Personelle Sicherheit
    - Identifizierung von sensiblen Positionen
    - Verfahren zur Überprüfung der Mitarbeiter
    - Sicherheitsschulung und -bewusstsein
- Administrative Sicherheit
    - Kontrolle des Imports von Fremdsoftware
    - Verfahren zur Untersuchung von Sicherheitsverstößen
    - Überprüfung von Prüfpfaden
    - Überprüfung von Kontrollen der Rechenschaftspflicht
- Strahlungssicherheit
    - Kontrolle von Funkfrequenzen und anderen elektromagnetischen Abstrahlungen
    - Bezeichnet als TEMPEST-Schutz
- Mediensicherheit
    - Absicherung der Speicherung von Informationen
    - Kontrolle der Kennzeichnung, Vervielfältigung und Vernichtung von sensiblen Informationen
    - Sicherstellen, dass Medien mit sensiblen Informationen sicher vernichtet werden
    - Scannen von Medien auf Viren
- Lebenszyklus-Kontrollen
    - Vertrauenswürdiger Systementwurf, -implementierung, -bewertung und -übernahme
    - Programmierstandards und -kontrollen
    - Kontrollen der Dokumentation
- Computer-Sicherheit
    - Schutz von Informationen während der Speicherung/Verarbeitung in einem Computersystem
    - Schutz der Datenverarbeitungsgeräte selbst
- Sicherheit der Kommunikation
    - Schutz von Informationen während des Transports von einem System zu einem anderen
    - Schutz der Kommunikationsinfrastruktur selbst

## Kommunikationssicherheit: Einige Terminologie
- Sicherheitsdienst
    - Ein abstrakter Dienst, der eine bestimmte Sicherheitseigenschaft gewährleisten soll.
    - Ein Sicherheitsdienst kann sowohl mit Hilfe von kryptografischen Algorithmen und Protokollen als auch mit herkömmlichen Mitteln realisiert werden
        - Man kann ein elektronisches Dokument auf einem USB-Stick vertraulich halten, indem man es in einem verschlüsselten Format auf dem Datenträger speichert und den Datenträger in einem Tresor wegschließt.
        - In der Regel ist eine Kombination aus kryptografischen und anderen Mitteln am effektivsten
- Kryptographischer Algorithmus
    - Eine mathematische Umwandlung von Eingabedaten (z. B. Daten, Schlüssel) in Ausgabedaten
    - Kryptografische Algorithmen werden in kryptografischen Protokollen verwendet.
- Kryptografisches Protokoll
    - Eine Reihe von Schritten und der Austausch von Nachrichten zwischen mehreren Einheiten, um ein bestimmtes Sicherheitsziel zu erreichen

## Sicherheitsdienste - Überblick
- **Authentifizierung (Authentication)**
    - Der grundlegendste Sicherheitsdienst, der sicherstellt, dass eine Entität tatsächlich die Identität besitzt, die sie vorgibt zu haben
- **Integrität (Integrity)**
    - In gewisser Weise der "kleine Bruder" des Authentifizierungsdienstes, da er sicherstellt, dass Daten, die von bestimmten Entitäten erstellt wurden, nicht unentdeckt verändert werden können
- **Vertraulichkeit (Confidentiality)**
    - Der beliebteste Sicherheitsdienst, der die Geheimhaltung der geschützten Daten gewährleistet
- **Zugriffskontrolle (Access Control)**
    - Kontrolliert, dass jede Identität nur auf die Dienste und Informationen zugreift, zu denen sie berechtigt ist
- **Nicht-Abstreitbarkeit (Non Repudiation)**
    - Schützt davor, dass an einem Kommunikationsaustausch beteiligte Entitäten später fälschlicherweise abstreiten können, dass der Austausch stattgefunden hat


## Sicherheitsunterstützende Mechanismen
- Allgemeine Mechanismen
    - Schlüsselverwaltung: Alle Aspekte des Lebenszyklus von kryptografischen Schlüsseln
    - Zufallszahlengenerierung: Generierung von kryptographisch sicheren Zufallszahlen
    - Ereigniserkennung / Sicherheitsprüfpfad: Erkennung und Aufzeichnung von Ereignissen, die zur Erkennung von Angriffen oder Bedingungen, die von Angriffen ausgenutzt werden könnten, verwendet werden können
    - Erkennung von Eindringlingen: Analyse der aufgezeichneten Sicherheitsdaten, um erfolgreiche Einbrüche oder Angriffe zu erkennen
    - Beglaubigung: Registrierung von Daten durch eine vertrauenswürdige dritte Partei, die später bestimmte Eigenschaften (Inhalt, Ersteller, Erstellungszeitpunkt) der Daten bestätigen kann
- Kommunikationsspezifische Mechanismen
    - Traffic Padding & Cover Traffic: Erzeugung von gefälschtem Verkehr, um die Analyse des Verkehrsflusses zu verhindern
    - Routing-Kontrolle: Beeinflussung des Routings von PDUs in einem Netzwerk

## Kryptologie - Definition und Terminologie
- Kryptologie
    - Wissenschaft, die sich mit sicherer und meist geheimer Kommunikation beschäftigt
    - Der Begriff leitet sich von den griechischen Wörtern kryptós (verborgen) und lógos (Wort) ab.
    - Kryptologie umfasst
        - Kryptographie ( gráphein = schreiben): die Lehre von den Prinzipien und Techniken, mit denen Informationen in verschlüsseltem Text verborgen und später von legitimen Nutzern mit Hilfe eines geheimen Schlüssels offengelegt werden können
        - Kryptoanalyse ( analýein = lýsen, losbinden): die Wissenschaft (und Kunst) der Wiedergewinnung von Informationen aus Chiffren ohne Kenntnis des Schlýssels
- Chiffre (Quelle Encyclopaedia Britannica)
    - Methode zur Umwandlung einer Nachricht (Klartext), um ihre Bedeutung zu verschleiern
    - Wird auch als Synonym für den verborgenen Chiffretext verwendet.
    - Chiffren sind eine Klasse von kryptografischen Algorithmen
    - Die Umwandlung erfolgt in der Regel mit der Nachricht und einem (geheimen) Schlüssel als Eingabe

## Kryptologie - einige historische Anmerkungen
- 400 v. Chr.: Die Spartaner verwenden ein Chiffriergerät namens Scytale für die Kommunikation zwischen militärischen Befehlshabern.
    - Die Scytale bestand aus einem spitz zulaufenden Stab, um den spiralförmig ein Streifen Pergament oder Leder gewickelt war, auf den die Nachricht geschrieben wurde
    - Beim Aufwickeln wurden die Buchstaben der Reihe nach durcheinander gewürfelt und bildeten die Chiffre.
    - Wurde der Streifen um einen anderen Stab mit den gleichen Proportionen wie das Original gewickelt, kam der Klartext wieder zum Vorschein
- Im 4. Jahrhundert v. Chr:
    - Aeneas Tacticus (Grieche) schreibt "Über die Verteidigung von Festungen", wobei ein Kapitel der Kryptographie gewidmet ist
    - Polybius (Grieche) erfindet eine Methode zur Kodierung von Buchstaben in Symbolpaaren mit Hilfe eines Geräts namens Polybius-Schachbrett, das eine bi-literale Substitution ermöglicht und viele Elemente späterer Kryptosysteme vorwegnimmt
- Die Römer verwendeten eine monoalphabetische Substitution mit einfacher zyklischer Verschiebung des Alphabets:
    - Julius Caesar verwendete eine Verschiebung von drei Buchstaben (A ergibt D, ..., Z ergibt C)
    - Augustus Caesar verwendete eine einzige Verschiebung (A ergibt B, ...)
- Die Araber waren die ersten, die die Prinzipien der Kryptographie verstanden und die Anfänge der Kryptoanalyse entdeckten:
    - Entwurf und Verwendung von Substitutions- und Transpositions-Chiffren
    - Entdeckung der Verwendung von Buchstabenhäufigkeitsverteilungen und wahrscheinlichen Klartexten in der Kryptoanalyse
    - Bis 1412 n. Chr. enthält Al-Kalka-Shandi in seiner Enzyklopädie Subh al-a'sha eine elementare und respektable Behandlung mehrerer kryptographischer Systeme und ihrer Kryptoanalyse
- Europäische Kryptographie:
    - Die Entwicklung begann im Kirchenstaat und in den italienischen Stadtstaaten im Mittelalter
    - Die ersten Chiffren verwendeten nur Vokalsubstitutionen
    - 1397: Gabriele de Lavinde von Parma verfasst das erste europäische Handbuch zur Kryptographie, das eine Zusammenstellung von Chiffren sowie eine Reihe von Schlüsseln für 24 Korrespondenten enthält und Symbole für Buchstaben, Zahlen und mehrere zweistellige Codeäquivalente für Wörter und Namen umfasst
    - Code-Vokabulare, Nomenklatoren genannt, wurden für mehrere Jahrhunderte zur Hauptstütze der diplomatischen Kommunikation der meisten europäischen Regierungen
    - 1470: Leon Battista Alberti veröffentlicht Trattati In Cifra, in denen er die erste Chiffrierscheibe beschreibt und bereits vorschreibt, die Scheibe regelmäßig neu einzustellen, wobei er den Begriff der Polyalphabetizität entwickelt
    - 1563: Giambattista della Porta liefert eine abgewandelte Form einer quadratischen Tabelle und das früheste Beispiel einer digraphischen Chiffre (2-Buchstaben-Substitution)
    - 1586: Blaise de Vigenère veröffentlicht Traicté des chiffres, das die ihm zugeschriebene quadratische Tabelle enthält
    - Bis 1860 wurden große Codes für die diplomatische Kommunikation verwendet, und Chiffren wurden nur in der militärischen Kommunikation eingesetzt (außer auf hoher Kommandoebene), da es schwierig war, Codebücher im Feld zu schützen.
- Entwicklungen während der Weltkriege 1 und 2:
    - Während des 1. Weltkriegs: Chiffriersysteme wurden hauptsächlich für die taktische Kommunikation verwendet und die Kommunikation auf hoher Ebene wurde durch Codes geschützt.
    - 1920: Die Kommunikationsbedürfnisse der Telekommunikation und die Weiterentwicklung der elektromechanischen Technik führen zu einer wahren Revolution bei den Verschlüsselungsgeräten - der Entwicklung von Rotor-Chiffriermaschinen:
      - Das Rotorprinzip wird unabhängig voneinander von E. E. Hebern (USA), H. A. Koch (Niederlande) und A. Scherbius (Deutschland) entdeckt
      - Rotor-Chiffriermaschinen kaskadieren eine Sammlung von Chiffrierscheiben, um eine polyalphabetische Substitution von hoher Komplexität zu realisieren
      - Die Kryptoanalyse der taktischen Kommunikation spielt während des Zweiten Weltkriegs eine sehr wichtige Rolle. Die größten Erfolge sind die britische und polnische Lösung der deutschen Enigma- und der beiden Fernschreiber-Chiffren sowie die amerikanische Kryptoanalyse der japanischen Chiffren.
- Entwicklungen nach dem 2. Weltkrieg:
    - Die moderne Elektronik ermöglicht noch komplexere Chiffren, die zunächst den Rotorprinzipien folgen (und deren Schwächen einbeziehen)
    - Die meisten Informationen über elektronische Chiffriermaschinen, die von verschiedenen nationalen Kryptodiensten verwendet wurden, sind nicht öffentlich zugänglich.
    - Ende der 1960er Jahre war die kommerziell verfügbare Kryptographie kaum bekannt, und starke Kryptographie war den nationalen Behörden vorbehalten
    - 1973-1977: Entwicklung des Data Encryption Standard (DES)
    - 1976-1978: Entdeckung der Public-Key-Kryptografie
    - 1976: W. Diffie und M. Hellman veröffentlichen "New Directions in Cryptography" (Neue Wege in der Kryptographie), in dem sie die Konzepte der Public-Key-Kryptographie einführen und ein Verfahren zum Austausch von Schlüsseln über unsichere Kanäle beschreiben.
    - R. Merkle entdeckt unabhängig das Prinzip des öffentlichen Schlüssels, seine ersten Veröffentlichungen erscheinen jedoch erst 1978, da der Veröffentlichungsprozess langsam ist
    - 1978: R. L. Rivest, A. Shamir und A. M. Adleman veröffentlichen "A Method for Obtaining Digital Signatures and Public Key Cryptosystems", das den ersten funktionierenden und sicheren Public-Key-Algorithmus RSA enthält
 
# Grundlagen der Kryptographie
- Überblick über kryptografische Algorithmen
- Angriffe auf die Kryptographie
- Eigenschaften von Verschlüsselungsalgorithmen
- Klassifizierung von Verschlüsselungsalgorithmen

## Kryptographische Algorithmen: Überblick
- In diesem Kurs stehen zwei Hauptanwendungen kryptographischer Algorithmen im Mittelpunkt des Interesses
    - Verschlüsselung von Daten: Umwandlung von Klartextdaten in Chiffretext, um deren Bedeutung zu verbergen
    - Signierung von Daten: Berechnung eines Prüfwerts oder einer digitalen Signatur für einen gegebenen Klartext oder Geheimtext, der von einigen oder allen Stellen, die auf die signierten Daten zugreifen können, überprüft werden kann
- Einige kryptografische Algorithmen können für beide Zwecke verwendet werden, andere sind nur für einen der beiden Zwecke sicher und/oder effizient.
- Hauptkategorien von kryptografischen Algorithmen
    - Symmetrische Kryptografie, die 1 Schlüssel für die Ver-/Entschlüsselung oder die Signierung/Prüfung verwendet
    - Asymmetrische Kryptografie mit 2 verschiedenen Schlüsseln für die Ver-/Entschlüsselung oder die Unterzeichnung/Prüfung
    - Kryptografische Hash-Funktionen mit 0 Schlüsseln (der "Schlüssel" ist keine separate Eingabe, sondern wird an die Daten "angehängt" oder mit ihnen "vermischt").

## Angriff auf die Kryptographie
## Kryptoanalyse
- Kryptoanalyse ist der Versuch, den Klartext und/oder den Schlüssel herauszufinden.
- Arten der Kryptoanalyse
    - Nur Chiffretext: bestimmte Muster des Klartextes können im Chiffretext erhalten bleiben (Häufigkeit von Buchstaben, Digraphen usw.)
    - Bekannte Chiffretext-Klartext-Paare
    - Gewählter Klartext oder gewählter Chiffretext
    - Differentielle Kryptoanalyse und lineare Kryptoanalyse
    - Neuere Entwicklung: verwandte Schlüsselanalyse
- Kryptoanalyse der Public-Key-Kryptographie
    - Die Tatsache, dass ein Schlüssel öffentlich zugänglich ist, kann ausgenutzt werden
    - Die Kryptoanalyse öffentlicher Schlüssel zielt eher darauf ab, das Kryptosystem selbst zu knacken und ist näher an der reinen mathematischen Forschung als an der klassischen Kryptoanalyse.
    - Wichtige Richtungen
        - Berechnung von diskreten Logarithmen
        - Faktorisierung von großen ganzen Zahlen

### Brute-Force-Angriff
- Der Brute-Force-Angriff probiert alle möglichen Schlüssel aus, bis er einen verständlichen Klartext findet
    - Jeder kryptographische Algorithmus kann theoretisch mit Brute Force angegriffen werden
    - Im Durchschnitt muss die Hälfte aller möglichen Schlüssel ausprobiert werden

Durchschnittlich benötigte Zeit für erschöpfende Schlüsselsuche

| Schlüsselgröße [bit] | Anzahl der Schlüssel         | Benötigte Zeit bei 1 $Verschlüsselung/\mu$s | Zeitbedarf bei 10^6 Verschlüsselung /$\mu$s |
| -------------------- | ---------------------------- | ------------------------------------------- | ------------------------------------------- |
| 56                   | $2^{56} = 7,2\times 10^{16}$ | $2^{55}\mu s = 1142$ Jahre                  | $10,01$ Stunden                             |
| 128                  | $2^{128} = 3,4 x 10^{38}$    | $2^{127}\mu s = 5,4 x 10^{24}$ Jahre        | $5,4 x 10^{18}$ Jahre                       |
| 256                  | $2^{256} = 1.2 x 10^{77}     | $2^{255}\mu s = 3,7 x 10^{63}$ Jahre        | $3,7 x 10^{57}$ Jahre                       |

### Wie groß ist groß?
Referenzzahlen zum Vergleich relativer Größenordnungen
| Referenz                                       | Größe                         |
| ---------------------------------------------- | ----------------------------- |
| Sekunden in einem Jahr                         | ca. $3 x 10^7$                |
| Sekunden seit der Entstehung des Sonnensystems | ca. $2 x 10^{17}$             |
| Taktzyklen pro Jahr (50 MHz Computer)          | ca. $1,6 x 10^{15}$           |
| Binäre Zeichenketten der Länge 64              | $2^{64}$ ca. $1,8 x 10^{19}$  |
| Binäre Zeichenfolgen der Länge 128             | $2^{128}$ ca. $3,4 x 10^{38}$ |
| Binäre Zeichenfolgen der Länge 256             | $2^{256}$ ca. $1,2 x 10^{77}$ |
| Anzahl der 75-stelligen Primzahlen             | $5,2 x 10^{72}$               |
| Elektronen im Universum                        | $8,37 x 10^{77}$              |

### Wichtige Eigenschaften von Verschlüsselungsalgorithmen
Nehmen wir an, ein Absender verschlüsselt Klartextnachrichten $P_1, P_2, ...$ zu Chiffretextnachrichten $C_1, C_2, ...$

Dann sind die folgenden Eigenschaften des Verschlüsselungsalgorithmus von besonderem Interesse
- Die Fehlerfortpflanzung charakterisiert die Auswirkungen von Bit-Fehlern bei der Übertragung von Chiffretext zu rekonstruiertem Klartext $P_1', P_2', ...$
    - Je nach Verschlüsselungsalgorithmus können pro fehlerhaftem Chiffretext-Bit ein oder mehrere fehlerhafte Bits im rekonstruierten Klartext vorhanden sein
- Die Synchronisierung charakterisiert die Auswirkungen verlorener Chiffretext-Dateneinheiten auf den rekonstruierten Klartext
    - Einige Verschlüsselungsalgorithmen können sich nicht von verlorenem Chiffretext erholen und benötigen daher eine explizite Neusynchronisierung im Falle verlorener Nachrichten
    - Andere Algorithmen führen eine automatische Neusynchronisierung nach 0 bis n (n je nach Algorithmus) Chiffretextbits durch.

## Klassifizierung von Verschlüsselungsalgorithmen: Drei Dimensionen
- Die Art der Operationen, die zur Umwandlung von Klartext in Chiffretext verwendet werden
    - Substitution, die jedes Element des Klartextes (Bit, Buchstabe, Gruppe von Bits oder Buchstaben) in ein anderes Element umwandelt
    - Transposition, die die Elemente des Klartextes neu anordnet
- Die Anzahl der verwendeten Schlüssel
    - Symmetrische Chiffren, die denselben Schlüssel für die Ver- und Entschlüsselung verwenden
    - Asymmetrische Chiffren, bei denen unterschiedliche Schlüssel für die Ver- und Entschlüsselung verwendet werden
- Die Art und Weise, in der der Klartext verarbeitet wird
    - Stromchiffren arbeiten mit Bitströmen und verschlüsseln ein Bit nach dem anderen
        - Viele Stromchiffren basieren auf der Idee der linearen rückgekoppelten Schieberegister, und bei vielen Algorithmen dieser Klasse wurden Schwachstellen entdeckt, da es eine tiefgreifende mathematische Theorie zu diesem Thema gibt.
        - Die meisten Stromchiffren verbreiten keine Fehler, sind aber anfällig für den Verlust der Synchronisation.
    - Blockchiffren arbeiten mit Blöcken der Breite b, wobei b vom jeweiligen Algorithmus abhängt.

## Kryptographische Algorithmen - Überblick
Kryptografische Algorithmen
- Überblick
    - Eigenschaften
    - Kryptoanalyse
- Symmetrische Ver-/Entschlüsselung
    - Funktionsweisen
    - DES
    - AES
    - RC4
    - KASUMI
- Asymmetrische Ver-/Entschlüsselung
    - Hintergrund
    - RSA
    - Diffie-Hellman
    - ElGamal
    - ECC
- Kryptographische Hash-Funktionen
    - MDCs/MACs
    - MD
    - SHA-1/2/
    - CBC-MAC
    - GCM-MAC

# Symmetrische Kryptographie
- Modi der Verschlüsselung
- Datenverschlüsselungsstandard (DES)
- Erweiterter Verschlüsselungsstandard (AES)
- Die Blockchiffre RC
- KASUMI

## Symmetrische Verschlüsselung
- Allgemeine Beschreibung
    - Derselbe Schlüssel KA,B wird für die Verschlüsselung und Entschlüsselung von Nachrichten verwendet
- Schreibweise
    - Wenn P die Klartextnachricht bezeichnet, bezeichnet $E(K_{A,B}, P)$ den Chiffretext und es gilt $D(K_{A,B}, E(K_{A,B}, P)) = P$
    - Alternativ schreibt man manchmal $\{P\}_{K_{A,B}}$ oder $E_{K_{A,B}}(P)$ für $E(K_{A,B}, P)$
- Beispiele: DES, 3DES, AES, ...

## Symmetrische Blockchiffren - Verschlüsselungsarten
Allgemeine Bemerkungen & Notation
- Ein Klartext P wird in Blöcke $P_1, P_2, ...$ der Länge b bzw. j zerlegt, wobei b die Blockgröße des Verschlüsselungsalgorithmus bezeichnet und j < b
- Der Chiffretext C ist die Kombination von $C_1, C_2, ...$, wobei $c_i$ das Ergebnis der Verschlüsselung des i-ten Blocks der Klartextnachricht bezeichnet
- Die Stellen, die eine Nachricht verschlüsseln und entschlüsseln, haben sich auf einen Schlüssel K geeinigt.

Elektronischer Codebuch-Modus (Electronic Code Book Mode: ECB)
- Jeder Block Pi der Länge b wird unabhängig verschlüsselt: $C_i = E(K, p_i)$
- Ein Bitfehler in einem Chiffretextblock $C_i$ führt zu einem völlig falsch wiederhergestellten Klartextblock $P_i'$
- Der Verlust der Synchronisation hat keine Auswirkungen, wenn ganzzahlige Vielfache der Blockgröße b verloren gehen. Geht eine andere Anzahl von Bits verloren, ist eine explizite Neusynchronisation erforderlich.
- Nachteil: identische Klartextblöcke werden zu identischem Chiffretext verschlüsselt!
- ![](Assets/NetworkSecurity-electronic-code-book-mode.png)

Cipher Block Chaining Modus (Cipher Block Chaining Mode: CBC)
- Vor der Verschlüsselung eines Klartextblocks pi wird dieser mit dem vorangegangenen Chiffretextblock $C_{i-1}$ XOR-verknüpft ()
    - $C_i = E(K, C_{i-1} \oplus p_i)$
    - $P_{i'} = C_{i-1} \oplus D(K, C_i)$
    - Um $C_1$ zu berechnen, einigen sich beide Parteien auf einen Anfangswert (IV) für $C_0$
- Eigenschaften
    - Fehlerfortpflanzung: Ein verfälschter Chiffretextblock führt zu zwei verfälschten Klartextblöcken, da $P_i'$ mit $C_{i-1}$ und $C_i$ berechnet wird
    - Synchronisation: Wenn die Anzahl der verlorenen Bits ein ganzzahliges Vielfaches von b ist, wird ein zusätzlicher Block $P_{i+1}$ verzerrt, bevor die Synchronisation wiederhergestellt wird. Wenn eine andere Anzahl von Bits verloren geht, ist eine explizite Neusynchronisation erforderlich.
    - Vorteil: identische Klartextblöcke werden zu nicht-identischem Chiffretext verschlüsselt.
- ![](Assets/NetworkSecurity-cipher-block-chaining-mode.png)

Chiffretext-Feedback-Modus (Ciphertext Feedback Mode: CFB)
- Ein Blockverschlüsselungsalgorithmus, der mit Blöcken der Größe b arbeitet, kann in einen Algorithmus umgewandelt werden, der mit Blöcken der Größe $j (j<b)$ arbeitet.
  - $S(j, x)$ bezeichnen die $j$ höherwertigen Bits von $x$
  - $P_i$, $C_i$ den $i$-ten Block von Klartext und Geheimtext der Länge $j$ bezeichnen
  - IV ist ein Anfangswert, auf den sich beide Parteien geeinigt haben
  - $R_1 = IV$
  - $R_n = (R_{n-1}*2^j\ mod\ 2^b)\oplus C_{n-1}$
  - $C_n = S(j,E_K(R_n))\oplus P_n$
  - $S(j,E_K(R_n))\oplus C_n = S(j,E_K(R_n))\oplus S(j,E_K(R_n))\oplus P_n$
  - $S(j,E_K(R_n))\oplus C_n = P_n$
- Ein gängiger Wert für j ist 8 für die Verschlüsselung von einem Zeichen pro Schritt
- Eigenschaften von CFB
    - Fehlerfortpflanzung: Da die Chiffretextblöcke schrittweise durch das Register geschoben werden, verfälscht ein fehlerhafter Block $C_i$ den wiederhergestellten Klartextblock $P_i'$ sowie die folgenden $\lceil b / j\rceil$-Blöcke
    - Synchronisation: Wenn die Anzahl der verlorenen Bits ein ganzzahliges Vielfaches von j ist, werden $\lceil b / j\rceil$ zusätzliche Blöcke verfälscht, bevor die Synchronisation wiederhergestellt ist. Wenn eine beliebige andere Anzahl von Bits verloren geht, ist eine explizite Neusynchronisierung erforderlich.
    - Nachteil: Die Verschlüsselungsfunktion E muss häufiger berechnet werden, da eine Verschlüsselung von b Bit durchgeführt werden muss, um j Bit des Klartextes zu verbergen. Beispiel: Bei Verwendung von DES mit Verschlüsselung von jeweils einem Zeichen $\Rightarrow$ muss die Verschlüsselung 8-mal häufiger durchgeführt werden

Output-Feedback-Modus (OFB)
- Der Blockverschlüsselungsalgorithmus wird zur Erzeugung einer Pseudozufallsfolge $R_i$ verwendet, die nur von $K$ und $IV$ abhängt.
    - $S(j, x)$ bezeichnen die $j$ höherwertigen Bits von $x$
    - $P_i$, $C_i$ bezeichnen den $i$-ten Block von Klartext und Chiffretext der Länge $j$
    - $IV$ sei ein Anfangswert, auf den sich beide Parteien geeinigt haben
    - $R_1 = IV$
    - $R_n = (R_{n-1}* 2^j\ mod\ 2^b )\oplus S(j,E_K(R_{n-1}))$ // j-bit Linksverschiebung + verschlüsselter alter Wert
    - $C_n = S(j,E_K(R_n))\oplus P_n$
    - $S(j,E_K(R_n))\oplus C_n = S(j,E_K(R_n))\oplus S(j,E_K(R_n))\oplus P_n$
    - $S(j,E_K(R_n))\oplus C_n = P_n$
- Der Klartext wird mit der Pseudo-Zufallssequenz XOR-verknüpft, um den Chiffretext zu erhalten und umgekehrt
- Eigenschaften von OFB
    - Fehlerfortpflanzung: Einzelbitfehler führen nur zu Einzelbitfehlern $\rightarrow$ keine Fehlermultiplikation
    - Synchronisierung: Wenn einige Bits verloren gehen, ist eine explizite Re-Synchronisation erforderlich.
    - Vorteil: Die Pseudo-Zufallsfolge kann vorberechnet werden, um die Auswirkungen der Verschlüsselung auf die Ende-zu-Ende-Verzögerung gering zu halten
    - Nachteile
      - Wie bei CFB muss die Verschlüsselungsfunktion E häufiger berechnet werden, da eine Verschlüsselung von b Bit durchgeführt werden muss, um j Bit des Klartextes zu verbergen
      - Es ist für einen Angreifer möglich, bestimmte Bits des Klartextes zu manipulieren
- ![](Assets/NetworkSecurity-output-feedback-mode.png)


Algorithmus-Übersicht
- Datenverschlüsselungsstandard (DES)
  - Alter amerikanischer Standard aus den 70er Jahren
  - Unsicher wegen der Schlüssel- und Blocklänge
  - Grundlegender Aufbau
  - Dreifache Verschlüsselung mit einer Blockchiffre, z.B. Triple-DES
- Erweiterter Verschlüsselungsstandard (AES)
  - Offener Standardisierungsprozess mit internationaler Beteiligung
  - Im Oktober 2000 wurde ein Algorithmus namens Rijndael für AES vorgeschlagen
  - Ankündigung des AES-Standards im November 2001
  - Siehe auch http://www.nist.gov/aes/
- Andere populäre Algorithmen
    - RC
    - KASUMI

## Der Datenverschlüsselungsstandard (DES)
Geschichte
- 1973 veröffentlichte das National Bureau of Standards (NBS, heute National Institute of Standards and Technology, NIST) eine Aufforderung zur Einreichung von Vorschlägen für einen nationalen Verschlüsselungsstandard und forderte von dem Algorithmus, dass er
  - ein hohes Maß an Sicherheit bieten,
  - vollständig spezifiziert und leicht zu verstehen sein,
  - Sicherheit nur durch seinen Schlüssel und nicht durch seine eigene Geheimhaltung bieten,
  - für alle Benutzer verfügbar sein,
  - für den Einsatz in verschiedenen Anwendungen anpassbar sein,
  - wirtschaftlich in elektronischen Geräten implementierbar sein,
  - effizient in der Anwendung sein,
  - validiert werden können und
  - exportierbar sein.
- Keine der Einreichungen auf diese erste Aufforderung erfüllte diese Kriterien auch nur annähernd.
- Auf eine zweite Aufforderung hin reichte IBM seinen Algorithmus LUCIFER ein, eine symmetrische Blockchiffre, die mit Blöcken der Länge 128 Bit unter Verwendung von Schlüsseln der Länge 128 Bit arbeitet; dies war der einzige vielversprechende Kandidat.
- Die NBS bat die National Security Agency (NSA) um Hilfe bei der Bewertung der Sicherheit des Algorithmus
  - Die NSA reduzierte die Blockgröße auf 64 Bit, die Größe des Schlüssels auf 56 Bit und änderte Details in den Substitutionsfeldern des Algorithmus.
  - Viele der Gründe der NSA für diese Änderungen wurden erst in den frühen 1990er Jahren deutlich, lösten aber in den späten 1970er Jahren große Besorgnis aus.
- Trotz aller Kritik wurde der Algorithmus 1977 als ,,Data Encryption Standard'' in die Reihe der Federal Information Processing Standards (FIPS PUB 46) aufgenommen und für die Verwendung in der gesamten nicht klassifizierten Regierungskommunikation zugelassen.
- DES hat sich in den folgenden Jahren weithin durchgesetzt

![](Assets/NetworkSecurity-des-algorithm.png)

![](Assets/NetworkSecurity-des-single-iteration.png)

### DES - Einzelne Iteration
- Die rechten 32 Bit der zu verschlüsselnden Daten werden mit Hilfe einer Expansions-/Permutationstabelle auf 48 Bit erweitert.
- Sowohl die linken als auch die rechten 28 Bit des Schlüssels (auch Subkeys genannt) werden zirkulär nach links verschoben und der resultierende Wert wird mit Hilfe einer Permutations-/Kontraktionstabelle auf 48 Bit verkürzt.
- Die beiden oben genannten Werte werden XOR-verknüpft und in eine Auswahl- und Ersetzungsbox eingegeben
  - Intern wird diese Operation durch 8 so genannte s-Boxen realisiert, von denen jede einen Sechs-Bit-Wert auf einen Vier-Bit-Wert gemäß einer boxspezifischen Tabelle abbildet, was insgesamt zu einem 32-Bit-Ausgang führt
  - Das Design dieser s-boxes wurde von der NSA verstärkt, was in den 1970er Jahren zu intensiven Diskussionen führte und in den 1990er Jahren nach der Entdeckung der differentiellen Kryptoanalyse verstanden wurde
- Der Ausgang des obigen Schritts wird erneut permutiert und mit den linken 32 Bit der Daten XOR-verknüpft, was zu den neuen rechten 32 Bit der Daten führt
- Die neuen linken 32 Bit der Daten sind der rechte Wert der vorherigen Iteration

### DES - Entschlüsselung
- Unter Verwendung der Abkürzung f(R, K) kann der Verschlüsselungsprozess wie folgt geschrieben werden
    - $L_i = R_{i-1}$
    - $R_i = L_{i-1}\oplus f(R_{i-1}, K_i)$
    - Dieses Konzept (Aufteilung der Daten in zwei Hälften und Organisation der Verschlüsselung gemäß den obigen Gleichungen) wird in vielen Blockchiffren verwendet und wird als Feistel-Netzwerk bezeichnet (nach seinem Erfinder H. Feistel)
- Der DES-Entschlüsselungsprozess ist im Wesentlichen derselbe wie die Verschlüsselung. Er verwendet den Chiffretext als Eingabe für den Verschlüsselungsalgorithmus, wendet aber die Unterschlüssel in umgekehrter Reihenfolge an
- Die Ausgangswerte sind also
    - $L_0' || R_0' =$ InitialPermutation (Chiffretext)
    - chiffretext = InverseInitialPermutation ($R_{16} || L_{16}$)
    - $L_0' || R_0' =$ InitialPermutation (InverseInitialPermutation ($R_{16}||L_{16}))=R_{16}||L_{16}$
- Nach einem Schritt der Entschlüsselung
    - $L_1' = R_0' = L_{16} = R_{15}$
    - $R_1' = L_0' \oplus f(R_0', K_{16})=R_{16}\oplus f(R_{15},K_{16})=[L_{15}\oplus f(R_{15},K_{16})]\oplus f(R_{15},K_{16}) =L_{15}$
- Diese Beziehung gilt für den gesamten Prozess als
    - $R_{i-1} = L_i$
    - $L_{i-1} = R_i\oplus f(R_{i-1}, K_i) = R_i\oplus f(L_i, K_i)$
- Der Ausgang der letzten Runde ist schließlich
    - $L_{16}' || R_{16}' = R_0 || L_0$
- Nach der letzten Runde führt DES einen 32-Bit-Tausch und die inverse Anfangspermutation durch
  - InverseInitialPermutation($L_0||R_0$) = InverseInitialPermutation(InitialPermutation(Klartext)) = Klartext


### DES - Sicherheit
- Schwächen der Schlüssel
    - Schwache Schlüssel: Vier Schlüssel sind schwach, da sie Unterschlüssel erzeugen, die entweder alle 0 oder alle 1 enthalten.
    - Halbschwache Schlüssel: Es gibt sechs Schlüsselpaare, die Klartext zu identischem Chiffriertext verschlüsseln, da sie nur zwei verschiedene Unterschlüssel erzeugen
    - Möglicherweise schwache Schlüssel: Es gibt 48 Schlüssel, die nur vier verschiedene Unterschlüssel erzeugen
    - Insgesamt werden 64 Schlüssel von $72057594037927936$ als schwach angesehen
- Algebraische Struktur
    - Wäre DES geschlossen, dann gäbe es für jedes $K_1,K_2$ ein $K_3$, so dass: $E(K_2,E(K_1,M))=E(K_3,M)$, also wäre die doppelte Verschlüsselung nutzlos
    - Wäre DES rein, dann gäbe es für jedes $K_1,K_2,K_3$ ein $K_4$, so dass $E(K_3,E(K_2,E(K_1,M)))=E(K_4,M)$, also wäre die dreifache Verschlüsselung nutzlos
    - DES ist weder geschlossen noch rein, daher kann ein Mehrfachverschlüsselungsschema verwendet werden, um die Schlüssellänge zu erhöhen
- Differentielle Kryptoanalyse
    - Im Jahr 1990 veröffentlichten E. Biham und A. Shamir diese Analysemethode
    - Sie sucht gezielt nach Unterschieden in Chiffretexten, deren Klartexte bestimmte Unterschiede aufweisen, und versucht, daraus den richtigen Schlüssel zu erraten
    - Der grundlegende Ansatz benötigt einen ausgewählten Klartext zusammen mit seinem Chiffretext
    - DES mit 16 Runden ist gegen diesen Angriff immun, da der Angriff $2^{47}$ gewählte Klartexte oder (bei "Umwandlung" in einen Angriff mit bekannten Klartexten) $2^55$ bekannte Klartexte benötigt.
    - Die Entwickler von DES erklärten in den 1990er Jahren, dass sie in den 1970er Jahren über diese Art von Angriffen Bescheid wussten und dass die s-Boxen entsprechend entworfen wurden
- Schlüssellänge
    - Da ein 56-Bit-Schlüssel in $10,01$ Stunden durchsucht werden kann, wenn man $10^6$ Verschlüsselungen / $\mu s$ durchführen kann (was heute möglich ist), kann DES nicht mehr als ausreichend sicher angesehen werden.

### Erweiterung der Schlüssellänge von DES durch Mehrfachverschlüsselung
- Doppelter DES: Da DES nicht geschlossen ist, führt die doppelte Verschlüsselung zu einer Chiffre, die 112-Bit-Schlüssel verwendet
  - Leider kann sie mit einem Aufwand von $2^{56}$ angegriffen werden.
  - Da $C=E(K_2,E(K_1,P))$ haben wir $X:=E(K_1,P)=D(K_2,C)$
  - Wenn ein Angreifer ein bekanntes Klartext/Chiffretext-Paar erhalten kann, kann er zwei Tabellen erstellen (meet-in-the-middle-attack)
    - Tabelle 1 enthält die Werte von $X$, wenn $P$ mit allen möglichen Werten von $K$ verschlüsselt ist
    - Tabelle 2 enthält die Werte von $X$, wenn $C$ mit allen möglichen Werten von $K$ entschlüsselt wird
    - Sortiere die beiden Tabellen und konstruiere Schlüssel $K_{T1}||K_{T2}$ für alle Kombinationen von Einträgen, die den gleichen Wert ergeben.
- Da es für jeden beliebigen Klartext $2^64$ mögliche Chiffretext-Werte gibt, die mit Double-DES erzeugt werden könnten, gibt es beim ersten bekannten Klartext/Chiffretext-Paar durchschnittlich $2^{112}/2^{64}=2^{48}$ Fehlalarme.
- Jedes weitere Klartext/Chiffretext-Paar verringert die Chance, einen falschen Schlüssel zu erhalten, um den Faktor $1/2^{64}$, so dass bei zwei bekannten Blöcken die Chance $2^{-16}$ beträgt.
- Der Aufwand, der erforderlich ist, um Double DES zu knacken, liegt also in der Größenordnung von $2^{56}$, was nur geringfügig besser ist als der Aufwand von $2^{55}$, der erforderlich ist, um Single DES mit einem Angriff mit bekanntem Klartext zu knacken, und weit entfernt von den $2^{111}$, die wir von einer Chiffre mit einer Schlüssellänge von 112 Bit erwarten würden!
- Diese Art von Angriff kann durch die Verwendung eines dreifachen Verschlüsselungsschemas umgangen werden, wie es 1979 von W. Tuchman vorgeschlagen wurde
    - $C=E(K_3,D(K_2,E(K_1,P)))$
    - Die Verwendung der Entschlüsselungsfunktion D in der Mitte ermöglicht die Verwendung von Dreifachverschlüsselungsgeräten mit Gegenstellen, die nur Einfachverschlüsselungsgeräte besitzen, indem $K_1=K_2=K_3$ gesetzt wird.
    - Dreifachverschlüsselung kann mit zwei (Einstellung $K_1=K_3$) oder drei verschiedenen Schlüsseln verwendet werden
    - Bislang sind keine praktischen Angriffe gegen dieses Verfahren bekannt
    - Nachteil: die Leistung beträgt nur $1/3$ der einfachen Verschlüsselung, so dass es besser sein könnte, gleich eine andere Chiffre zu verwenden, die eine größere Schlüssellänge bietet

## Der fortgeschrittene Verschlüsselungsstandard AES
- Jan. 1997: Das National Institute of Standards and Technology (NIST) der USA kündigt die Entwicklung des AES an.
    - Das übergeordnete Ziel ist die Entwicklung eines Federal Information Processing Standard (FIPS), der einen Verschlüsselungsalgorithmus spezifiziert, der in der Lage ist, sensible Regierungsinformationen bis weit ins nächste Jahrhundert hinein zu schützen.
- Sep. 1997: Offizieller Aufruf zur Einreichung von Algorithmen, offen für jeden auf der Welt
    - AES würde einen nicht klassifizierten, öffentlich zugänglichen Verschlüsselungsalgorithmus bzw. -algorithmen spezifizieren, der weltweit lizenzgebührenfrei erhältlich ist.
- Aug. 1998: Erste AES-Kandidatenkonferenz
    - NIST gibt die Auswahl von 15 Kandidatenalgorithmen bekannt
    - Aufforderung zu öffentlichen Kommentaren
- April 1999:
    - Anhand der eingegangenen Analysen und Kommentare wählt das NIST fünf Algorithmen als Kandidaten für die Endauswahl aus: MARS, RC6, Rijndael, Serpent und Twofish
- Oktober 2000: Rijndael wird als Vorschlag des NIST für AES bekannt gegeben
    - 26. November 2001: offizielle Ankündigung des AES-Standards

- Rundenbasierte symmetrische Chiffre
- Keine Feistel-Struktur (unterschiedliche Verschlüsselungs- und Entschlüsselungsfunktionen)
- Schlüssel- und Blocklängen
    - Schlüssellänge: 128, 192, oder 256 Bit
    - Blocklänge: 128, 192 oder 256 Bit (nur 128-Bit-Version standardisiert)
    - Anzahl der Runden: 10, 12, 14

Standardisierte AES-Konfigurationen
| Schlüsselgröße [bit] | Blocklänge [bit] | # Runden |
| -------------------- | ---------------- | -------- |
| 128                  | 128              | 10       |
| 192                  | 128              | 12       |
| 256                  | 128              | 14       |

- Der Algorithmus arbeitet mit
  - $state[4, 4]$: ein Byte-Array mit 4 Zeilen und 4 Spalten (für 128-Bit-Blockgröße)
  - $key[4, 4]$: ein Array mit 4 Zeilen und 4 Spalten (für 128-Bit-Schlüsselgröße)
- Verschlüsselung: (für eine Block- und Schlüsselgröße von 128 Bit) in den Runden $1-9$ werden vier verschiedene Operationen verwendet
    - ByteSub: eine nicht-lineare Byte-Substitution durch eine feste Tabelle (im Grunde eine s-Box)
    - ShiftRow: die Zeilen des Zustands werden zyklisch um verschiedene Offsets verschoben
    - MixColumn: die Spalten von $state[]$ werden als Polynome über $GF(2^8)$ betrachtet und modulo $x^4+1$ mit einer festen Matrix multipliziert: $\begin{pmatrix} 02&03&01&01\\01&02&03&01\\\ 01&01&02&03\\\ 03&01&01&02\end{pmatrix}$
    - RoundKey: ein Round-Key wird mit dem Status XORiert
- Round 10 macht keinen Gebrauch von der Operation MixColumn

![](Assets/NetworkSecurity-rijndael-one-round.png)

- Entschlüsselung
  - Rundenschlüssel und Operationen werden in umgekehrter Reihenfolge angewendet
  - Der MixColumn-Schritt kann nur durch Multiplikation mit der inversen Matrix (auch über $GF(2^8)$) invertiert werden
  - $\begin{pmatrix} 0e&0b&0d&09\\ 09&0e&0b&0d\\ 0d&09&0e&0b\\ 0b&0d&09&0e \end{pmatrix}$
  - Oft werden tabellarische vorberechnete Lösungen verwendet, die aber mehr Platz benötigen

### AES - Sicherheit
- Die einfache mathematische Struktur von AES ist der Hauptgrund für seine Geschwindigkeit, führte aber auch zu Kritik
- Nur die ByteSub-Funktion ist wirklich nichtlinear und verhindert eine effektive Analyse
- AES kann als eine große Matrix-Operation beschrieben werden
- Bereits während der Standardisierung wurden Angriffe für reduzierte Versionen entwickelt
    - Ein Angriff mit $2^{32}$ gewähltem Klartext gegen eine 7-Runden-Version von AES [GM00]
    - Signifikante Reduktion der Komplexität auch für eine 9-Runden-Version von AES mit 256-Schlüsselgröße mit einem zugehörigen Schlüsselangriff
- 2011 wurde der erste Angriff gegen einen vollständigen AES bekannt [BKR11]
    - Schlüsselwiederherstellung in $2^{126.1}$ für AES mit 128 Bit, $2^{189.7}$ für AES mit 192 Bit, $2^{254.4}$ für AES mit 256 Bit
    - "Praktischer" Angriff (geht nicht von verwandten Schlüsseln aus), aber
    - nur ein kleiner Kratzer in Anbetracht von 10 Jahren kryptographischer Forschung

## Der Stromchiffre-Algorithmus RC4
- RC4 ist eine Stromchiffre, die 1987 von Ron Rivest erfunden wurde.
- Sie war bis 1994 urheberrechtlich geschützt, als jemand sie anonym in eine Mailingliste einstellte.
- RC4 wird im Output-Feedback-Modus (OFB) betrieben
  - Der Verschlüsselungsalgorithmus erzeugt eine Pseudozufallsfolge $RC4(IV,K)$, die nur vom Schlüssel K und einem Initialisierungsvektor IV abhängt
  - Der Klartext $P_i$ wird dann mit der Pseudozufallssequenz XOR-verknüpft, um den Chiffretext zu erhalten und umgekehrt
    - $C_1 = P_1\oplus RC4 (IV_1,K)$
    - $P_1 = C_1\oplus RC4 (IV_1,K)$
  - Die Pseudo-Zufallsfolge wird oft auch als Keystream bezeichnet
  - Entscheidend für die Sicherheit ist, dass der Keystream niemals wiederverwendet wird!!!
    - Wenn der Keystream wiederverwendet wird (d.h. $IV_1=IV_2$ mit demselben $K$), dann kann das XOR zweier Klartexte erhalten werden: $C_1\oplus C_2= P_1\oplus RC4(IV, K)\oplus P_2\oplus RC4(IV,K) = P_1\oplus P_2$
- RC4 verwendet einen Schlüssel variabler Länge bis zu 2048 Bit
    - Eigentlich dient der Schlüssel als Seed für einen Pseudo-Zufallsgenerator
- RC4 arbeitet mit zwei 256-Byte-Arrays: $S[0,255], K[0,255]$
    - Schritt 1: Initialisierung der Arrays
        ```cpp
        for (i = 0; i < 256; i++){
            S[i] = i; // Array S[] mit 0 bis 255 füllen
        }
        // Füllen des Arrays K[] mit dem Schlüssel und IV durch Wiederholung, bis K[] gefüllt ist
        n = 0;
        for (i =0; i < 256; i++) {
            n = (n + S[i] + K[i]) MOD 256; swap(S[i], S[n]); 
        }
        ```
    - Schritt 2: Erzeugen des Schlüsselstroms (nach Initialisierung $i = 0; n = 0;$)
        ```cpp
        i = (i + 1) MOD 256; n = (n + S[i]) MOD 256;
        swap(S[i], S[n]);
        t = (S[i] + S[n]) MOD 256;
        Z = S[t]; // Z enthält 8 Bit des durch eine Iteration erzeugten Schlüsselstroms
        ```
    - Schritt 3: XOR-Verknüpfung des Schlüsselstroms mit dem Klartext oder Chiffretext
- Sicherheit von RC4
  - Sicherheit gegen Brute-Force-Angriffe (Ausprobieren aller möglichen Schlüssel)
    - Die variable Schlüssellänge von bis zu 2048 Bit erlaubt es, sie unpraktisch zu machen (zumindest mit den in unserem Universum verfügbaren Ressourcen)
    - Allerdings kann RC4 durch Verringerung der Schlüssellänge auch beliebig unsicher gemacht werden!
  - RSA Data Security, Inc. behauptet, RC4 sei immun gegen differentielle und lineare Kryptoanalyse, und es seien keine kleinen Zyklen bekannt
- RC4 mit 40-Bit-Schlüsseln hatte einen besonderen Exportstatus, selbst als andere Chiffren nicht aus den USA exportiert werden durften
  - Secure Socket Layer (SSL) verwendet RC4 mit 40-Bit-Schlüsseln als Standardalgorithmus
  - Die Schlüssellänge von 40 Bit ist nicht immun gegen Brute-Force-Angriffe.
- Je nach Schlüsselplanungsmethode kann RC4 jedoch stark verwundbar sein! [FMS01a, Riv01a, SIR01a]
- Es wird empfohlen, mindestens die ersten 3072 Bytes des Schlüsselstroms zu verwerfen [Mir02, Kle08]
- Sollte eigentlich nicht mehr verwendet werden, auch nicht bei längeren Schlüsseln

## KASUMI
- Verwendet zur Verschlüsselung von Anrufen in GSM und UMTS, implementiert f(8) und f(9) (auch A5/3, UEA1, UIA1 genannt)
- Ursprünglich standardisiert durch 3GPP im Jahr 2000 [ETS12] und basierend auf MISTY1 von Mitsubishi
- Entwickelt für Hardware-Implementierung
  - Schnelle Implementierung möglich
  - $<10k$ Gatter
- 64-Bit-Blockgröße
- 128-Bit-Schlüssellänge
- 8 Runden Feistel-Netzwerk
- Sicherheitsspanne nicht sehr groß

![](Assets/NetworkSecurity-kasumi-singe-iteration.png)
- Die linken 32 Bit der zu verschlüsselnden Daten werden durch zwei nichtlineare Funktionen FO und FL verändert, die beide Schlüsselmaterial verwenden
- Die Reihenfolge, in der FO und FL angewendet werden, hängt von der Rundenzahl ab
- FL teilt die Daten in 16-Bit-Wörter auf, die mit Schlüsselmaterial kombiniert, permutiert und mit den Originalwerten XOR-verknüpft werden
- FO ist ein 3-Runden-Feistel-Netzwerk mit einer Modifizierungsfunktion FI, die selbst ein Feistel-ähnliches Netzwerk ist, das zwei s-Boxen verwendet.
- Der Ausgang des obigen Schritts wird mit den rechten 32 Bit der Daten XOR-verknüpft, was zu den neuen rechten 32 Bit der Daten führt
- Das neue linke 32-Bit der Daten ist der rechte Wert der vorherigen Iteration

### KASUMI - Sicherheitsdiskussion
- Eine reduzierte Version von KASUMI (6 Runden) kann durch sogenannte unmögliche differentielle Kryptoanalyse angegriffen werden, bei der unmögliche Zustände der Chiffre aus Chiffretext/Klartext-Paaren abgeleitet werden
  - Erste Veröffentlichung bereits ein Jahr nach der Standardisierung
  - Zeitkomplexität von $2^{100}$ [Kue01]
- Für eine Vollversion von KASUMI sind verwandte Schlüsselangriffe möglich
  - Ausgewählter Klartextangriff, bei dem der Angreifer dieselben Daten mit mehreren "verwandten" Schlüsseln verschlüsseln kann
  - Zeitkomplexität von $2^{76.1}$ [BDN05] und $2^{32}$ im besten Fall [DKS10]
  - Allerdings sind die Bedingungen, unter denen Angreifer Zugang zu verwandten Schlüsseln in 3G-Netzen haben, sehr selten
  - Interessanterweise ist MISTY von diesen Angriffen nicht betroffen!
- ETSI hat jedoch SNOW 3G (UEA2 und UIA2) [ETS06] eingeführt, um auf eine vollständige Verletzung von KASUMI vorbereitet zu sein
  - Stromchiffre basierend auf LFSR, kann in 7.500 ASIC-Gattern implementiert werden
  - Aber auch anfällig für verwandte Schlüsselangriffe [KY11].

# Grundlagen der Kryptographie
# Symmetrische Kryptographie
# Asymmetrische Kryptographie
# Modifikationsprüfwerte
# Zufallszahlengenerierung
# Kryptographische Protokolle
# Sichere Gruppenkommunikation
# Zugriffskontrolle
# Integration von Sicherheitsdiensten in Kommunikationsarchitekturen
# Sicherheitsprotokolle der Datenübertragungsschicht
# Die IPsec-Architektur für das Internet-Protokoll
# Security protocols of the transport layer
# Sicherheitsaspekte der mobilen Kommunikation
# Sicherheit von drahtlosen lokalen Netzen
# Sicherheit von GSM- und UMTS-Netzen

# References
- [AES01a] National Institute of Standards and Technology - Specification for the Advanced Encryption Standard (AES)
- [DR97a] J. Daemen, V. Rijmen - AES Proposal: Rijndael http://csrc.nist.gov/encryption/aes/rijndael/Rijndael.pdf
- [FMS01a] S. Fluhrer, I. Mantin, A. Shamir - Weaknesses in the Key Scheduling Algorithm of RC4. Eighth Annual Workshop on Selected Areas in Cryptography
- [Riv01a] R. Rivest. - RSA Security Response to Weaknesses in Key Scheduling Algorithm of RC4. http://www.rsa.com/rsalabs/node.asp
- [SIR01a] A. Stubblefield, J. Ioannidis, A. D. Rubin. - Using the Fluhrer, Mantin, and Shamir Attack to Break WEP. AT&T Labs Technical Report TD-4ZCPZZ
- [FKLS00] N. Ferguson, J. Kelsey, S. Lucks, B. Schneier, M. Stay, D.Wagner, D. Whiting - Improved cryptanalysis of Rijndael. In FSE’00, volume 1978 of Lecture Notes in Computer Science. Springer, 2000.
- [GM00] H. Gilbert and M. Minier - A Collision Attack on 7 Rounds of Rijndael. In AES Candidate Conference, 2000.
- [BKR11] A. Bogdanov, D. Khovratovich, C. Rechberger - Biclique cryptanalysis of the full AES. In ASIACRYPT’11, 2001.
- [Mir02] I. Mironov - (Not so) random shuffles of RC4. In Advances in Cryptology - CRYPTO 2002
- [Kle08] A.Klein. - Attacks on the RC4 stream cipher. In Designs, Codes and Cryptography
- [ETS12] ETSI/SAGE - Specification of the 3GPP confidentiality and integrity algorithms; Document 2: Kasumi specification
- [Kue01] U. Kühn. - Cryptanalysis of Reduced-Round MISTY. In Advances in Cryptology - EUROCRYPT 2001
- [BDN05] E. Biham, O. Dunkelman, N. Keller - A Related-Key Rectangle Attack on the Full KASUMI , In ASIACRYPT 2005
- [DKS10] O. Dunkelman, N. Keller, A. Shamir - A practical-time related-key attack on the KASUMI cryptosystem used in GSM and 3G telephony. In CRYPTO'10
- [ETS06] ETSI/SAGE - Specification of the 3GPP Confidentiality and Integrity Algorithms UEA2 & UIA2. Document 2: SNOW 3G Specification
- [KY11] A. Kircanski A.M. Youssef. - On the Sliding Property of SNOW 3G and SNOW 2.0 IET Inf. Secur.
- [Amo94] E. G. Amorosi. - Fundamentals of Computer Security Technology
- [Cha95] Brent Chapman and Elizabeth Zwicky - Building Internet Firewalls
- [For94b] Warwick Ford. - Computer Communications Security - Principles, Standard Protocols and Techniques.
- [Gar96] Simson Garfinkel and Gene Spafford - Practical Internet & Unix Security
- [Men97a] A. J. Menezes, P. C. Van Oorschot, S. A. Vanstone - Handbook of Applied Cryptography. CRC Press Series on Discrete Mathematics and Its Applications
- [SR14] G. Schäfer, M. Rossberg - Netzsicherheit
- [Sch96] B. Schneier - Applied Cryptography Second Edition: Protocols, Algorithms and Source Code in C
- [Sta13] W. Stallings - Cryptography and Network Security: Principles and Practice
- [Sti05] D. R. Stinson - Cryptography: Theory and Practice (Discrete Mathematics and Its Applications)