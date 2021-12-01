- [Einleitung](#einleitung)
  - [Was ist eine Bedrohung in einem Kommunikationsnetz?](#was-ist-eine-bedrohung-in-einem-kommunikationsnetz)
  - [Sicherheitsziele in Abhängigkeit von der Anwendungsumgebung](#sicherheitsziele-in-abhängigkeit-von-der-anwendungsumgebung)
  - [Sicherheitsziele technisch definiert](#sicherheitsziele-technisch-definiert)
  - [Technisch definierte Bedrohungen](#technisch-definierte-bedrohungen)
  - [Bedrohungen und technische Sicherheitsziele](#bedrohungen-und-technische-sicherheitsziele)
  - [Analyse der Netzwerksicherheit](#analyse-der-netzwerksicherheit)
  - [Angriffe auf die Kommunikation auf der Nachrichtenebene](#angriffe-auf-die-kommunikation-auf-der-nachrichtenebene)
  - [Schutzmaßnahmen gegen Bedrohungen der Informationssicherheit](#schutzmaßnahmen-gegen-bedrohungen-der-informationssicherheit)
  - [Kommunikationssicherheit: Einige Terminologie](#kommunikationssicherheit-einige-terminologie)
  - [Sicherheitsdienste - Überblick](#sicherheitsdienste---überblick)
  - [Sicherheitsunterstützende Mechanismen](#sicherheitsunterstützende-mechanismen)
  - [Kryptologie - Definition und Terminologie](#kryptologie---definition-und-terminologie)
  - [Kryptologie - einige historische Anmerkungen](#kryptologie---einige-historische-anmerkungen)
- [Grundlagen der Kryptographie](#grundlagen-der-kryptographie)
  - [Kryptographische Algorithmen: Überblick](#kryptographische-algorithmen-überblick)
  - [Angriff auf die Kryptographie](#angriff-auf-die-kryptographie)
  - [Kryptoanalyse](#kryptoanalyse)
    - [Brute-Force-Angriff](#brute-force-angriff)
    - [Wie groß ist groß?](#wie-groß-ist-groß)
    - [Wichtige Eigenschaften von Verschlüsselungsalgorithmen](#wichtige-eigenschaften-von-verschlüsselungsalgorithmen)
  - [Klassifizierung von Verschlüsselungsalgorithmen: Drei Dimensionen](#klassifizierung-von-verschlüsselungsalgorithmen-drei-dimensionen)
  - [Kryptographische Algorithmen - Überblick](#kryptographische-algorithmen---überblick)
- [Symmetrische Kryptographie](#symmetrische-kryptographie)
  - [Symmetrische Verschlüsselung](#symmetrische-verschlüsselung)
  - [Symmetrische Blockchiffren - Verschlüsselungsarten](#symmetrische-blockchiffren---verschlüsselungsarten)
  - [Der Datenverschlüsselungsstandard (DES)](#der-datenverschlüsselungsstandard-des)
    - [DES - Einzelne Iteration](#des---einzelne-iteration)
    - [DES - Entschlüsselung](#des---entschlüsselung)
    - [DES - Sicherheit](#des---sicherheit)
    - [Erweiterung der Schlüssellänge von DES durch Mehrfachverschlüsselung](#erweiterung-der-schlüssellänge-von-des-durch-mehrfachverschlüsselung)
  - [Der fortgeschrittene Verschlüsselungsstandard AES](#der-fortgeschrittene-verschlüsselungsstandard-aes)
    - [AES - Sicherheit](#aes---sicherheit)
  - [Der Stromchiffre-Algorithmus RC4](#der-stromchiffre-algorithmus-rc4)
  - [KASUMI](#kasumi)
    - [KASUMI - Sicherheitsdiskussion](#kasumi---sicherheitsdiskussion)
- [Asymmetrische Kryptographie](#asymmetrische-kryptographie)
  - [Some Mathematical Background](#some-mathematical-background)
  - [The RSA Public Key Algorithm](#the-rsa-public-key-algorithm)
  - [Some More Mathematical Background](#some-more-mathematical-background)
  - [Diffie-Hellman Key Exchange](#diffie-hellman-key-exchange)
  - [The ElGamal Algorithm](#the-elgamal-algorithm)
  - [Elliptic Curve Cryptography](#elliptic-curve-cryptography)
    - [Foundations of ECC - Group Elements](#foundations-of-ecc---group-elements)
    - [Foundations of ECC - Point Addition](#foundations-of-ecc---point-addition)
    - [Foundations of ECC - Algebraic Addition](#foundations-of-ecc---algebraic-addition)
    - [Foundations of ECC - Multiplication](#foundations-of-ecc---multiplication)
    - [Foundations of ECC - Curves over $\mathbb{Z}_p$](#foundations-of-ecc---curves-over-mathbbz_p)
    - [Foundations of ECC - Calculate the y-values in $\mathbb{Z}_p$](#foundations-of-ecc---calculate-the-y-values-in-mathbbz_p)
    - [Foundations of ECC - Addition and Multiplication in $\mathbb{Z}_p$](#foundations-of-ecc---addition-and-multiplication-in-mathbbz_p)
    - [Foundations of ECC - Size of generated groups](#foundations-of-ecc---size-of-generated-groups)
    - [Foundations of ECC - ECDH](#foundations-of-ecc---ecdh)
    - [Foundations of ECC - EC version of ElGamal Algorithm](#foundations-of-ecc---ec-version-of-elgamal-algorithm)
    - [Foundations of ECC - Security](#foundations-of-ecc---security)
    - [Foundations of ECC - Further remarks](#foundations-of-ecc---further-remarks)
  - [Conclusion](#conclusion)
- [Modifikationsprüfwerte](#modifikationsprüfwerte)
- [Zufallszahlengenerierung](#zufallszahlengenerierung)
- [Kryptographische Protokolle](#kryptographische-protokolle)
- [Sichere Gruppenkommunikation](#sichere-gruppenkommunikation)
- [Zugriffskontrolle](#zugriffskontrolle)
- [Integration von Sicherheitsdiensten in Kommunikationsarchitekturen](#integration-von-sicherheitsdiensten-in-kommunikationsarchitekturen)
- [Sicherheitsprotokolle der Datenübertragungsschicht](#sicherheitsprotokolle-der-datenübertragungsschicht)
- [Die IPsec-Architektur für das Internet-Protokoll](#die-ipsec-architektur-für-das-internet-protokoll)
- [Security protocols of the transport layer](#security-protocols-of-the-transport-layer)
- [Sicherheitsaspekte der mobilen Kommunikation](#sicherheitsaspekte-der-mobilen-kommunikation)
- [Sicherheit von drahtlosen lokalen Netzen](#sicherheit-von-drahtlosen-lokalen-netzen)
- [Sicherheit von GSM- und UMTS-Netzen](#sicherheit-von-gsm--und-umts-netzen)
- [References](#references)


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

# Asymmetrische Kryptographie
,,However, prior exposure to discrete mathematics will help the reader to appreciate the concepts presented here.'' E. Amoroso in another context [Amo94]

- General idea:
  - Use two different keys $-K$ and $+K$ for encryption and decryption
  - Given a random ciphertext $c=E(+K, m)$ and $+K$ it should be infeasible to compute $m = D(-K, c) = D(-K, E(+K, m))$
    - This implies that it should be infeasible to compute $-K$ when given $+K$
  - The key $-K$ is only known to one entity A and is called A’s private key $-K_A$
  - The key $+K$ can be publicly announced and is called A’s public key $+K_A$
- Applications:
  - Encryption:
    - If B encrypts a message with A’s public key $+K_A$, he can be sure that only A can decrypt it using $-K_A$
  - Signing:
    - If A encrypts a message with his own private key $-K_A$, everyone can verify this signature by decrypting it with A’s public key $+K_A$
  - Attention: It is crucial, that everyone can verify that he really knows A’s public key and not the key of an adversary!
- Design of asymmetric cryptosystems:
  - Difficulty: Find an algorithm and a method to construct two keys $-K$, $+K$ such that it is not possible to decipher $E(+K, m)$ with the knowledge of $+K$
  - Constraints:
    - The key length should be ,,manageable''
    - Encrypted messages should not be arbitrarily longer than unencrypted messages (we would tolerate a small constant factor)
    - Encryption and decryption should not consume too much resources (time, memory)
  - Basic idea: Take a problem in the area of mathematics / computer science, that is hard to solve when knowing only $+K$, but easy to solve when knowing $-K$
    - Knapsack problems: basis of first working algorithms, which were unfortunately almost all proven to be insecure
    - Factorization problem: basis of the RSA algorithm
    - Discrete logarithm problem: basis of Diffie-Hellman and ElGamal

## Some Mathematical Background
- Let $\mathbb{Z}$ be the number of integers, and $a,b,n\in\mathbb{Z}$
- We say $a$ divides $b(,,a|b'')$ if there exists an integer $k\in\mathbb{Z}$ such that $a\times k=b$
- We say $a$ is prime if it is positive and the only divisors of a are $1$ and $a$
- We say $r$ is the remainder of a divided by $n$ if $r=a-\lfloor a / n \rfloor\times n$ where $\lfloor x\rfloor$ denotes the largest integer less than or equal to $x$
    - Example: 4 is the remainder of 11 divided by 7 as $4=11-\lfloor 11/7\rfloor\times 7$
    - We can write this in another way: $a=q\times n + r$ with $q=\lfloor a/n\rfloor$
- For the remainder $r$ of the division of a by n we write $a\ MOD\ n$
- We say b is congruent $a\ mod\ n$ if it has the same remainder like a when divided by n. So, n divides $(a-b)$, and we write $b\equiv a\ mod\ n$
  - Examples: $4\equiv 11\ mod\ 7$, $25\equiv 11\ mod\ 7$, $11\equiv 25\ mod\ 7$, $11\equiv 4\ mod\ 7$, $-10\equiv 4\ mod\ 7$
- As the remainder r of division by n is always smaller than n , we sometimes represent the set $\{x\ MOD\ n | x\in\mathbb{Z}\}$ by elements of the set $\mathbb{Z}_n=\{0, 1, ..., n-1\}$

| Property                                                                                                            | Expression                                                                             |
| ------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------- |
| Commutative Laws                                                                                                    | $(a + b)\ MOD\ n = (b + a)\ MOD\ n$                                                    |
| $(a \times b)\ MOD\ n = (b \times a)\ MOD\ n$                                                                       |
| Associative Laws                                                                                                    | $[(a + b) + c]\ MOD\ n = [a + (b + c)]\ MOD\ n$                                        |
| $[(a \times b) \times c]\ MOD\ n = [a \times (b \times c)]\ MOD\ n$                                                 |
| Distributive Law                                                                                                    | $[a \times (b + c)]\ MOD\ n = [(a \times b) + (a \times c)]\ MOD\ n$                   |
| Identities                                                                                                          | $(0 + a)\ MOD\ n = a\ MOD\ n$                                                          |
| $(1 \times a)\ MOD\ n = a\ MOD\ n$                                                                                  |
| Inverses                                                                                                            | $\forall  a \in \mathbb{Z}n: \exists (-a) \in \mathbb{Z}n : a + (-a) \equiv 0\ mod\ n$ |
| $p is prime \Rightarrow \forall  a \in \mathbb{Z}p: \exists (a-1) \in \mathbb{Z}p: a \times (a-1) \equiv 1\ mod\ p$ |

Greatest common divisor
- $c = gcd(a, b) :\Leftrightarrow  ( c | a) \wedge ( c | b) \wedge [\forall  d: ( d | a ) \wedge ( d | b) \Rightarrow ( d | c )]$ and $gcd(a, 0 ) : = | a |$
- The gcd recursion theorem :
  - $\forall a, b \in \mathbb{Z}^+: gcd(a, b) = gcd(b, a\ MOD\ b)$
  - Proof:
    - As $gcd(a, b)$ divides both a and b it also divides any linear combination of them, especially $(a- \lfloor a / b \rfloor \times b) = a\ MOD\ b$, so $gcd(a, b) | gcd(b, a\ MOD\ b)$
    - As $gcd(b, a\ MOD\ b)$ divides both b and $a\ MOD\ b$ it also divides any linear combination of them, especially $\lfloor a / b \rfloor \times b + (a\ MOD\ b) = a$, so $gcd(b, a\ MOD\ b) | gcd(a, b)$
- Euclidean Algorithm:
  - The algorithm Euclid given a, b computes $gcd(a, b)$
  ```cpp
  int Euclid(int a, b){
    if (b = 0) { return(a); }
    {return(Euclid(b, a\ MOD\ b);} 
  }
  ```
- Extended Euclidean Algorithm:
  - The algorithm ExtendedEuclid given a, b computes d, m, n such that: $d = gcd(a, b) = m \times a + n \times b$
  ```cpp
  struct{int d, m, n} ExtendedEuclid(int a, b)
  { int d, d’, m, m’, n, n’;
    if (b = 0) {return(a, 1, 0); }
    (d’, m’, n’) = ExtendedEuclid(b, a MOD b);
    (d, m, n) = (d’, n’, m’ - \lfloor a / b \rfloor \times n’);
    return(d, m, n); }
  ```
  - Proof: (by induction)
    - Basic case $(a,0): gcd(a, 0) = a = 1 \times a + 0 \times 0$
    - Induction from $(b, a\ MOD\ b)$ to $(a, b)$:
      - ExtendedEuclid computes $d’, m’, n’$ correctly (induction hypothesis)
      - $d=d’=m’\times b+n’\times (a\ MOD\ b)=m’\times b+n’\times(a-\lfloor a/b\rfloor\times b)=n’\times a+(m’-\lfloor a/b\rfloor\times n’)\times b$
  - The run time of $Euclid(a, b)$ and $ExtendedEuclid(a, b)$ is of $O(log\ b)$
    - Proof: see [Cor90a], section 33.
  - Lemma 1: Let $a,b\in\mathbb{N}$ and $d=gcd(a,b)$. Then there exists $m,n\in\mathbb{N}$ such that: $d=m\times a+n \times b$
- Theorem 1 (Euclid): If a prime divides the product of two integers, then it divides at least one of the integers: $p|(a\times b)\Rightarrow (p|a) \vee (p|b)$
    - Proof: Let $p|(a\times b)$
      - If $p|a$ then we are done.
      - If not then $gcd(p,a) = 1 \Rightarrow\exists m, n\in\mathbb{N}:1=m\times p+n\times a \Leftrightarrow b=m\times p \times b + n \times a \times b$
      - As $p|(a\times b)$, p divides both summands of the equation and so it divides also the sum which is b 
- Theorem 2 (fundamental theorem of arithmetic): Factorization into primes is unique up to order.
    - Proof:
        - We will show that every integer with a non-unique factorization has a proper divisor with a non-unique factorization which leads to a clear contradiction when we finally have reduced to a prime number.
        - Let’s assume that n is an integer with a non-unique factorization: $n=p_1\times p_2\times ...\times p_r=q_1 \times q_2\times ... \times q_s$. The primes are not necessarily distinct, but the second factorization is not simply a reordering of the first one. As $p_1$ divides n it also divides the product $q_1\times q_2\times ... \times q_s$. By repeated application of Theorem 1 we show that there is at least one $q_i$ which is divisible by $p_1$. If necessary reorder the $q_i$’s so that it is $q_1$. As both $p_1$ and $q_1$ are prime they have to be equal. So we can divide by $p_1$ and we have that $n/p_1$ has a non-unique factorization.
  - We will use Theorem 2 to prove the following Corollary 1
    - If $gcd(c,m)=1$ and $(a\times c)\equiv(b\times c)mod\ m$, then $a\equiv b\ mod\ m$
    - Proof: As $(a\times c)\equiv(b\times c)mod\ m\Rightarrow\exists n\in\mathbb{N}:(a\times c)-(b\times c)=n\times m$
    - $\Leftrightarrow ( a - b ) \times c = n \times m$
    - $\Leftrightarrow p_1\times ...\times p_i\times q_1\times ...\times q_j=r_1\times ...\times r_k\times s_1\times ...\times s_l$
    - Please note that the $p$’s, $q$’s, $r$’s and $s$’s are prime and do not need to be distinct, but as $gcd(c,m)=1$, there are no indices g, h such that $q_g = s_h$.
    - So we can continuously divide the equation by all q’s without ever ,,eliminating'' one $s$ and will finally end up with something like $\Leftrightarrow p_1\times ...\times p_i=r_1\times ...\times r_o\times s_1\times ...\times s_l$ (note that there will be fewer r’s)
    - $\Leftrightarrow(a-b)=r_1\times ...\times r_o\times m\Rightarrow a \equiv b\ mod\ m$
  - Let $\phi(n)$ denote the number of positive integers less than n and relatively prime to n
    - Examples: $\phi(4) = 2$, \phi(6)=2$, $\phi(7)=6$, $\phi(15)=8$
    - If p is prime $\Rightarrow\phi(p)=p-1$
- Theorem 3 (Euler): Let n and b be positive and relatively prime integers, i.e. $gcd(n, b) = 1 \Rightarrow b \phi(n) \equiv 1\ mod\ n$
  - Proof:
    - Let $t=\phi(n)$ and $a_1,...a_t$ be the positive integers less than $n$ which are relatively prime to $n$. Define $r_1,...,r_t$ to be the residues of $b\times a_1\ mod\ n , ..., b\times a_t\ mod\ n$ that is to say: $b\times a_i \equiv r_i\ mod\ n$.
    - Note that $i\not= j \Rightarrow r_i\not= r_j$. If this would not hold, we would have $b\times a_i\equiv b\times a_j\ mod\ n$ and as $gcd(b,n)=1$, Corollary 1 would imply $a_i\equiv a_j\ mod\ n$ which can not be as $a_i$ and $a_j$ are by definition distinct integers between 0 and n
    - We also know that each $r_i$ is relatively prime to n because any common divisor k of $r_i$ and $n$ , i.e. $n=k\times m$ and $r_i=p_i\times k$, would also have to divide $a_i$,
    - as $b\times a_i\equiv (p_i\times k)\ mod\ (k\times m)\Rightarrow\exists s\in\mathbb{N}:(b\times a_i)-(p_i\times k)=s\times k\times m \Leftrightarrow (b\times a_i)=s\times k\times m+(p_i\times k)$
    - Because k divides each of the summands on the right-hand side and k does not divide b by assumption (n and b are relatively prime), it would also have to divide $a_i$ which is supposed to be relatively prime to n
    - Thus $r_1, ...,r_t$ is a set of $\phi(n)$ distinct integers which are relatively prime to $n$. This means that they are exactly the same as $a_1,...a_t$, except that they are in a different order. In particular, we know that $r_1\times...\times r_t=a_1\times...\times a_t$
    - We now use the congruence $r_1\times...\times r_t\equiv b\times a_1\times...\times b\times a_t\ mod\ n$
        $\Leftrightarrow r_1\times...\times r_t\equiv b_t\times a_1\times...\times a_t\ mod\ n$
        $\Leftrightarrow r_1\times...\times r_t\equiv b_t\times r_1\times...\times r_t\ mod\ n$
    - As all $r_i$ are relatively prime to $n$ we can use Corollary 1 and divide by their product giving: $1\equiv b_t\ mod\ n \Leftrightarrow  1\equiv b\phi(n)\ mod n$ 
- Theorem 4 (Chinese Remainder Theorem):
  - Let $m_1,...,m_r$ be positive integers that are pairwise relatively prime,
  - i.e. $\forall i\not= j:gcd(m_i, m_j) = 1$. Let $a_1,...,a_r$ be arbitrary integers.
  - Then there exists an integer a such that:
    - $a\equiv a_1\ mod\ m_1$
    - $a\equiv a_2\ mod\ m_2$
    - ...
    - $a\equiv a_r\ mod\ m_r$
  - Furthermore, a is unique modulo $M := m_1\times...\times m_r$
  - Proof:
    - For all $i\in\{1,...,r\}$ we define $M_i:=(M/m_i)\phi(m_i)$
    - As $M_i$ is by definition relatively prime to $m_i$ we can apply Theorem 3 and know that $M_i\equiv 1\ mod\ m_i$
    - Since $M_i$ is divisible by $m_j$ for every $j\not= i$, we have $\forall j\not= i:M_i\equiv 0\ mod\ m_j$
    - We can now construct the solution by defining: $a:= a_1\times M_1+a_2\times M_2+...+a_r\times M_r$
    - The two arguments given above concerning the congruences of the $M_i$ imply that a actually satisfies all of the congruences.
    - To see that a is unique modulo $M$, let b be any other integer satisfying the r congruences. As $a\equiv c\ mod\ n$ and $b\equiv c\ mod\ n \Rightarrow a \equiv b\ mod\ n$ we have $\forall i\in\{1,...,r\}:a\equiv b\ mod\ m_i\Rightarrow\forall i\in\{1,...,r\}:m_i|(a-b) \Rightarrow M|(a-b)$ as the $m_i$ are pairwise relatively prime $\Leftrightarrow a\equiv b\ mod\ M$
- Lemma 2:
  - If $gcd(m,n)=1$, then $\phi(m\times n)=\phi(m)\times\phi(n)$
  - Proof:
    - Let a be a positive integer less than and relatively prime to $m\times n$. In other words, a is one of the integers counted by $\phi(m\times n)$.
    - Consider the correspondence $a\rightarrow(a\ MOD\ m, a\ MOD\ n)$. The integer a is relatively prime to m and relatively prime to n (if not it would divide $m \times n$). So, $(a\ MOD\ m)$ is relatively prime to m and $(a\ MOD\ n)$ is relatively prime to n as: $a=\lfloor a/m\rfloor\times m + (a\ MOD\ m)$, so if there would be a common divisor of $m$ and $(a\ MOD\ m)$, this divisor would also divide a. Thus every number a counted by $\phi(m\times n )$ corresponds to a pair of two integers $(a\ MOD\ m,a\ MOD\ n)$, the first one counted by $\phi(m)$ and the second one counted by $\phi(n)$.
    - Because of the second part of Theorem 4, the uniqueness of the solution $a\ mod\ (m\times n)$ to the simultaneous congruences:
        $a \equiv(a\ MOD\ m)\ mod\ m$
        $a \equiv(a\ MOD\ n)\ mod\ n$
      we can deduce, that distinct integers counted by $\phi(m\times n)$ correspond to distinct pairs:
      - Too see this, suppose that $a\not=b$ counted by $\phi(m\times n)$ does correspond to the same pair $(a\ MOD\ m, a\ MOD\ n)$. This leads to a contradiction as b would also fulfill the congruences:
        $b\equiv (a\ MOD\ m)\ mod\ m$
        $b\equiv (a\ MOD\ n)\ mod\ n$
        but the solution to these congruences is unique modulo $(m \times n)$ 
      - Therefore, $\phi(m\times n)$ is at most the number of such pairs: $\phi(m\times n)\leq \phi(m)\times\phi(n)$
    - Consider now a pair of integers $(b,c)$, one counted by $\phi(m)$ and the other one counted by $\phi(n)$: Using the first part of Theorem 4 we can construct a unique positive integer a less than and relatively prime to $m\times n$: $a\equiv b\ mod\ m$ and $a\equiv c\ mod\ n$. So, the number of such pairs is at most $\phi(m\times n):\phi(m \times n)\leq\phi(m)\times\phi(n)$

## The RSA Public Key Algorithm
- The RSA algorithm was invented in 1977 by R. Rivest, A. Shamir and L. Adleman [RSA78] and is based on Theorem 3.
- Let $p, q$ be distinct large primes and $n=p\times q$. Assume, we have also two integers e and d such that: $d\times e \equiv 1\ mod\ \phi(n)$
- Let M be an integer that represents the message to be encrypted, with M positive, smaller than and relatively prime to n.
  - Example: Encode with <blank> = 99, A = 10, B = 11, ..., Z = 35. So ,,HELLO'' would be encoded as 1714212124. If necessary, break M into blocks of smaller messages: 17142 12124
- To encrypt, compute: $E = M^e\ MOD\ n$
    - This can be done efficiently using the square-and-multiply algorithm
- To decrypt, compute: $M’=E^d\ MOD\ n$
    - As $d\times e\equiv 1\ mod\ \phi(n)\Rightarrow\exists k\in\mathbb{Z}:(d\times e)-1=k\times\phi(n)\Leftrightarrow(d\times e)=k\times\phi(n)+1$
    - we have: $M’\equiv E^d\equiv M^{e\times d}\equiv M^{k\times\phi(n)+1}\equiv 1^k\times M\equiv M\ mod\ n$ 
- As $(d\times e)=(e\times d)$ the operation also works in the opposite direction, that means you can encrypt with d and decrypt with e
  - This property allows to use the same keys d and e for:
  - Receiving messages that have been encrypted with one’s public key
  - Sending messages that have been signed with one’s private key
- To set up a key pair for RSA:
  - Randomly choose two primes $p$ and $q$ (of 100 to 200 digits each)
  - Compute $n=p\times q,\phi(n)=(p-1)\times (q-1)$ (Lemma 2)
  - Randomly choose $e$, so that $gcd(e,\phi(n))=1$
  - With the extended euclidean algorithm compute d and c, such that: $e\times d+\phi(n)\times c = 1$, note that this implies, that $e\times d\equiv 1\ mod\ \phi(n)$
  - The public key is the pair $(e, n)$
  - The private key is the pair $(d, n)$
- The security of the scheme lies in the difficulty of factoring $n=p\times q$ as it is easy to compute $\phi(n)$ and then $d$, when $p$ and $q$ are known
- This class will not teach why it is difficult to factor large n’s, as this would require to dive deep into mathematics
  - If p and q fulfill certain properties, the best known algorithms are exponential in the number of digits of n
  - Please be aware that if you choose p and q in an ,,unfortunate'' way, there might be algorithms that can factor more efficiently and your RSA encryption is not at all secure:
    - Therefore, p and q should be about the same bitlength and sufficiently large
    - $(p-q)$ should not be too small
    - If you want to choose a small encryption exponent, e.g. 3, there might be additional constraints, e.g. $gcd(p-1, 3) = 1$ and $gcd(q-1,3)=1$
  - The security of RSA also depends on the primes generated being truly random (like every key creation method for any algorithm)
  - Moral: If you are to implement RSA by yourself, ask a mathematician or better a cryptographer to check your design

## Some More Mathematical Background
- Definition: finite groups
  - A group ( S , \oplus) is a set S together with a binary operation \oplus for which the
  following properties hold:
      - Closure: For all a, b \in S , we have a \oplus b \in S
      - Identity: There is an element e \in S , such that e \oplus a = a \oplus e = a for all
  a \in S
      - Associativity: For all a, b, c \in S , we have ( a \oplus b ) \oplus c = a \oplus ( b \oplus c )
      - Inverses: For each a \in S , there exists a unique element b \in S , such
  that a \oplus b = b \oplus a = e
  - If a group ( S , \oplus) satisfies the commutative law \forall  a, b \in S : a \oplus b = b \oplus a
  then it is called an Abelian group
  - If a group ( S , \oplus) has only a finite set of elements, i.e. |S| < \infty, then it is
  called a finite group
- Examples:
  - $(\mathbb{Z}_n , +_n)$
    - with $\mathbb{Z}_n:=\{[0]_n,[1]_n,...,[n-1]_n\}$
    - where $[a]_n:=\{b \in \mathbb{Z} | b \equiv a mod n\}$ and
    - $+_n$ is defined such that $[a]_n+_n[b]_n=[a+b]_n$
    - is a finite abelian group. For the proof see the table showing the properties of modular arithmetic
  - $(\mathbb{Z}^*_n , \times_n)$
    - with $\mathbb{Z}^*_n :=\{[a]_n\in \mathbb{Z}_n | gcd(a,n)=1\}$, and
    - $\times_n$ is defined such that $[a]_n\times_n [b]_n=[a\times b]_n$
    - is a finite Abelian group. Please note that $\mathbb{Z}^*_n$ just contains those elements of $\mathbb{Z}_n$ that have a multiplicative inverse modulo n. For the proof see the properties of modular arithmetic
    - Example: $\mathbb{Z}^*_{15}=\{[1]_{15},[2]_{15},[4]_{15},[7]_{15},[8]_{15},[11]_{15},[13]_{15},[14]_{15}\}$, as $1\times 1\equiv 1 mod 15$, $2 \times 8 \equiv 1 mod 15$, $4 \times 4 \equiv 1 mod 15$, $7 \times 13 \equiv 1 mod 15$, $11 \times 11 \equiv 1 mod 15$, $14 \times 14 \equiv 1 mod 15$
- If it is clear that we are talking about $(\mathbb{Z}_n, +_n)$ or $(\mathbb{Z}^*_n, \times_n)$ we often represent equivalence classes $[a]_n$ by their representative elements a and denote $+_n$ and $\times_n$ by $+$ and $\times$, respectively.
  - Definition: finite fields
    - A field $(S,\oplus, \otimes)$ is a set S together with two operations $\oplus$, $\otimes$ such that
      - $(S,\oplus)$ and $(S\backslash\{e_{\oplus}\},\otimes)$ are commutative groups, i.e. only the identity element concerning the operation $\oplus$ does not need to have an inverse regarding the operation $\otimes$
      - For all $a,b,c\in S$, we have a $\otimes(b\oplus c)=(a\otimes b)\oplus(a\otimes c)$
  - If $|S|<\infty$ then $(S,\oplus,\otimes)$ is called a finite field
- Example: $(\mathbb{Z}_p, +_p, \times_p)$ is a finite field for each prime p
- Definition: primitive root, generator
  - Let $(S,\circ)$ be a group, $g\in S$ and $g^a:=g\circ g\circ...\circ g$ (a times with $a\in\mathbb{Z}^+$)
  - Then g is called a primitive root or generator of $(S,\circ):\Leftrightarrow\{g^a|1\leq a\leq |S|\}=S$
  - Examples:
    - 1 is a primitive root of $(\mathbb{Z}_n, +_n)$
    - 3 is a primitive root of $(\mathbb{Z}^*_7, \times_7)$
  - Not all groups do have primitive roots and those who have are called cyclic groups
- Theorem 5:
  - $(\mathbb{Z}^*_n, \times_n)$ does have a primitive root $\Leftrightarrow n\in\{2,4,p,2\times p^e\}$ where p is an odd prime and $e\in\mathbb{Z}^+$
- Theorem 6:
  - If $(S,\circ)$ is a group and $b\in S$ then $(S’,\circ)$ with $S’=\{b^a|a\in\mathbb{Z}^+\}$ is also a group.
  - As $S’\subseteq S,(S’,\circ)$ is called a subgroup of $(S,\circ)$
  - If b is a primitive root of $(S,\circ)$ then $S’=S$
- Definition: order of a group and of an element
  - Let $(S,\circ)$ be a group, $e\in S$ its identity element and $b\in S$ any element of $S$:
    - Then $|S|$ is called the order of $(S,\circ)$
    - Let $c\in\mathbb{Z}^+$ be the smallest element so that $b^c=e$ (if such a c exists, if not set $c=\infty$). Then c is called the order of b.
- Theorem 7 (Lagrange):
  - If G is a finite group and H is a subgroup of G , then $|H|$ divides $|G|$.
  - Hence, if $b\in G$ then the order of b divides $|G|$.
- Theorem 8:
  - If G is a cyclic finite group of order n and d divides n then G has exactly $\phi(d)$ elements of order $d$. In particular, G has $\phi(n)$ elements of order n.
- Theorems 5, 7, and 8 are the basis of the following algorithm that finds a cyclic group $\mathbb{Z}^*_p$ and a primitive root g of it:
  - Choose a large prime q such that $p=2q+1$ is prime.
    - As $p$ is prime, Theorem 5 states that $\mathbb{Z}^*_p$ is cyclic.
    - The order of $\mathbb{Z}^*_p$ is $2\times q$ and $\phi(2\times q)=\phi(2)\times\phi(q)=q-1$ as $q$ is prime.
    - So, the odds of randomly choosing a primitive root are $(q-1)/2q \approx 1/2$
    - In order to efficiently test, if a randomly chosen g is a primitive root, we just have to test if $g^2\equiv 1 mod p$ or $g^q\equiv 1 mod p$. If not, then its order has to be $|\mathbb{Z}^*_p|$, as Theorem 7 states that the order of g has to divide $|\mathbb{Z}^*_p|$
- Definition: discrete logarithm
  - Let p be prime, g be a primitive root of $(\mathbb{Z}^*_p,\times_p)$ and c be any element of $\mathbb{Z}^*_p$. Then there exists z such that: $g^z\equiv c mod p$
  - z is called the discrete logarithm of c modulo p to the base g
  - Example 6 is the discrete logarithm of 1 modulo 7 to the base 3 as $3^6\equiv 1 mod 7$
  - The calculation of the discrete logarithm z when given g, c, and p is a computationally difficult problem and the asymptotical runtime of the best known algorithms for this problem is exponential in the bitlength of p

## Diffie-Hellman Key Exchange
- The Diffie-Hellman key exchange was first published in the landmark paper [DH76], which also introduced the fundamental idea of asymmetric cryptography
- The DH exchange in its basic form enables two parties A and B to agree upon a shared secret using a public channel:
  - Public channel means, that a potential attacker E (E stands for eavesdropper) can read all messages exchanged between A and B
  - It is important, that A and B can be sure, that the attacker is not able to alter messages, as in this case he might launch a man-in-the-middle attack
  - The mathematical basis for the DH exchange is the problem of finding discrete logarithms in finite fields
  - The DH exchange is not an asymmetric encryption algorithm, but is nevertheless introduced here as it goes well with the mathematical flavor of this lecture...
- If Alice (A) and Bob (B) want to agree on a shared secret s and their only means of communication is a public channel, they can proceed as follows:
  - A chooses a prime p, a primitive root g of $\mathbb{Z}^*_p$, and a random number q:
    - A and B can agree upon the values p and g prior to any communication, or A can choose p and g and send them with his first message
    - A computes $v=g^q\ MOD\ p$ and sends to $B:\{p,g,v\}$
  - B chooses a random number r:
    - B computes $w=g^r\ MOD\ p$ and sends to $A:\{p,g,w\}$ (or just $\{w\}$)
  - Both sides compute the common secret:
    - A computes $s=w^q\ MOD\ p$
    - B computes $s’=v^r\ MOD\ p$
    - As $g^{q\times r}\ MOD\ p = g^{r \times q}\ MOD\ p$ it holds: $s=s’$
  - An attacker Eve who is listening to the public channel can only compute the secret s, if she is able to compute either q or r which are the discrete logarithms of v, w modulo p to the base g
- If the attacker Eve is able to alter messages on the public channel, she can launch a man-in-the-middle attack:
  - Eve generates to random numbers $q’$ and $r’$: Eve computes $v’=g^{q’}\ MOD\ p$ and $w’=g^{r’}\ MOD\ p$
  - When A sends $\{p,g,v\}$ she intercepts the message and sends to $B:\{p,g,v’\}$
  - When B sends $\{p,g,w\}$ she intercepts the message and sends to $A:\{p,g,w’\}$
  - When the supposed ,,shared secret'' is computed we get:
    - A computes $s_1=w’^q\ MOD\ p = v^{r’}\ MOD\ p$ the latter computed by E
    - B computes $s_2=v’^r\ MOD\ p = w^{q’}\ MOD\ p$ the latter computed by E
    - So, in fact A and E have agreed upon a shared secret $s_1$ as well as E and B have agreed upon a shared secret $s_2$
  - If the ,,shared secret'' is now used by A and B to encrypt messages to be exchanged over the public channel, E can intercept all the messages and decrypt/re-encrypt them before forwarding them between A and B.
- Two countermeasures against the man-in-the-middle attack:
  - The shared secret is ,,authenticated'' after it has been agreed upon
    - We will treat this in the section on key management
  - A and B use a so-called interlock protocol after agreeing on a shared secret:
    - For this they have to exchange messages that E has to relay before she can decrypt / re-encrypt them
    - The content of these messages has to be checkable by A and B
    - This forces E to invent messages and she can be detected
    - One technique to prevent E from decrypting the messages is to split them into two parts and to send the second part before the first one.
      - If the encryption algorithm used inhibits certain characteristics E can not encrypt the second part before she receives the first one.
      - As A will only send the first part after he received an answer (the second part of it) from B, E is forced to invent two messages, before she can get the first parts.
- Remark: In practice the number g does not necessarily need to be a primitive root of p, it is sufficient if it generates a large subgroup of $\mathbb{Z}^*_p$

## The ElGamal Algorithm
- The ElGamal algorithm can be used for both, encryption and digital signatures (see also [ElG85a] )
- Like the DH exchange it is based on the difficulty of computing discrete logarithms in finite fields
- In order to set up a key pair:
  - Choose a large prime p, a generator g of the multiplicative group $\mathbb{Z}^*_p$ and a random number v such that $1\leq v\leq p - 2$. Calculate: $y=g^v mod p$
  - The public key is $( y, g, p )$
  - The private key is v
- To sign a message m :
  - Choose a random number k such that k is relatively prime to $p-1$.
  - Compute $r=g^k mod p$
  - With the Extended Euclidean Algorithm compute $k^{-1}$, the inverse of $k mod (p - 1)$
  - Compute $s=k^{-1} \times ( m - v \times r) mod ( p - 1)$
  - The signature over the message is $( r, s )$
- To verify a signature $( r , s )$ over a message m:
  - Confirm that $y^r \times r^s\ MOD\ p = g^m\ MOD\ p$
  - Proof: We need the following
    - Lemma 3: Let p be prime and g be a generator of $\mathbb{Z}^*_p$. Then $i \equiv j mod ( p -1) \Rightarrow g i \equiv g j mod p$
    - Proof: $i\equiv j mod (p-1) \Rightarrow$ there exists $k\in \mathbb{Z}^+$ such that $(i-j)=(p-1)\times k$
    - So, $g^{(i-j)}=g^{(p-1)\times k} \equiv 1^k\equiv 1 mod p$, because of Theorem 3 (Euler) $\Rightarrow g^i \equiv g^j mod p$
  - So as  $s\equiv k^{-1}\times(m-v\times r) mod (p-1)$
    - $\Leftrightarrow k \times s\equiv m-v\times r mod (p-1)$
    - $\Leftrightarrow m \equiv v\times r+k\times s mod (p-1)$
    - $\Rightarrow g^m \equiv g^{(v\times r+ k\times s)} mod p$ with Lemma 3
    - $\Leftrightarrow g^m \equiv g^{(v\times r)}\times g^{(k\times s)} mod p$
    - $\Leftrightarrow g^m \equiv y^r\times r^s mod p$
- Security of ElGamal signatures:
  - As the private key v is needed to be able to compute s, an attacker would have to compute the discrete logarithm of y modulo p to the basis g in order to forge signatures
  - It is crucial to the security, that a new random number k is chosen for every message, because an attacker can compute the secret v if he gets two messages together with their signatures based on the same k (see [Men97a], Note 11.66.ii)
  - In order to prevent an attacker to be able to create a message M with a matching signature, it is necessary not to sign directly the message M as explained before, but to sign a cryptographic hash value $m=h(M)$ of it (these will be treated soon, see also [Men97a], Note 11.66.iii)
- To encrypt a message m using the public key $(y,g,p)$:
  - Choose a random $k\in\mathbb{Z}^+$ with $k<p-1$
  - Compute $r=g^k\ MOD\ p$
  - Compute $s=m\times y^k\ MOD\ p$
  - The ciphertext is $(r,s)$, which is twice as long as m
- To decrypt the message $(r,s)$ using v:
  - Use the private key v to compute $r^{(p-1-v)}\ MOD\ p=r^{(-v)}\ MOD\ p$
  - Recover m by computing $m=r^{(-v)}\times s\ MOD\ p$
  - Proof: $r^{(-v)}\times s\equiv r^{(-v)} \times m \times y^k\equiv g^{(-vk)}\times m \times y^k\equiv g^{(-v \times k)} \times m\times g^{(v \times k)} \equiv m mod p$
- Security:
  - The only known means for an attacker to recover m is to compute the discrete logarithm v of y modulo p to the basis g
  - For every message a new random k is needed ([Men97a], Note 8.23.ii)

## Elliptic Curve Cryptography
- The algorithms presented so far have been invented for the multiplicative group $(\mathbb{Z}^*_p,\times p)$ and the field $(\mathbb{Z}_p, +_p, \times_p)$, respectively
- It has been found during the 1980’s that they can be generalized and be used with other groups and fields as well
- The main motivation for this generalization is:
  - A lot of mathematical research in the area of primality testing, factorization and computation of discrete logarithms has led to techniques that allow to solve these problems in a more efficient way, if certain properties are met:
    - When the RSA-129 challenge was given in 1977 it was expected that it will take some 40 quadrillion years to factor the 129-digit number ($\approx 428$ bit)
    - In 1994 it took 8 months to factor it by a group of computers networked over the Internet, calculating for about 5000 MIPS-years
    - Advances in factoring algorithms allowed 2009 to factor a 232-digit number (768 bit) in about 1500 AMD64-years [KAFL10]
    - $\Rightarrow$ the key length has to be increased (currently about 2048 bit)
  - Some of the more efficient techniques do rely on specific properties of the algebraic structures $(\mathbb{Z}^*_p,\times p)$ and $(\mathbb{Z}_p, +_p, \times_p)$
  - Different algebraic structures may therefore provide the same security with shorter key lengths
- A very promising structure for cryptography can be obtained from the group of points on an elliptic curve over a finite field
  - The mathematical operations in these groups can be efficiently implemented both in hardware and software
  - The discrete logarithm problem is believed to be hard in the general class obtained from the group of points on an elliptic curve over a finite field

### Foundations of ECC - Group Elements
- Algebraic group consisting of
  - Points on Weierstrass’ Equation: $y^2 = x^3 + ax + b$
  - Additional point O in ,,infinity''
- May be calculated over $\mathbb{R}$, but in cryptography $\mathbb{Z}_p$ and $GF(2^n)$ are used
  - Already in $\mathbb{R}$ arguments influence form significantly:
    - $y^2 = x^3-3x+5$ ![](Assets/NetworkSecurity-ecc-1.png)
    - $y^2 = x^3-40x+5$ ![](Assets/NetworkSecurity-ecc-2.png)

### Foundations of ECC - Point Addition
- Addition of elements = Addition of points on the curve
- Geometric interpretation:
  - Each point $P:(x,y)$ has an inverse $-P:(x,-y)$
  - A line through two points P and Q usually intersects with a third point R
  - Generally, sum of two points P and Q equals $-R$
  - ![](Assets/NetworkSecurity-ecc-3.png)
- Addition (Special cases)
  - The additional point O is the neutral element, i.e., $P+O=P$
  - $P + (-P)$:
    - If the inverse point is added to P, the line and curve intersect in ,,infinity''
    - By definition: $P+(-P) = O$
  - $P+P$: The sum of two identical points P is the inverse of the intersecting point with the tangent through P:
    - ![](Assets/NetworkSecurity-ecc-4.png)

### Foundations of ECC - Algebraic Addition
- If one of the summands is O, the sum is the other summand
- If the summands are inverse to each other the sum is O
- For the more general cases the slope of the line is: $\alpha=\begin{cases} \frac{y_Q-y_P}{x_Q-x_P} \quad\text{ for } P\not=-Q \wedge P\not=Q \\ \frac{3x^2_P +a}{2y_P} \quad\text{ for } P=Q \end{cases}$
- Result of point addition, where $(x_r,y_r)$ is already the reflected point $(-R)$

### Foundations of ECC - Multiplication
- Multiplication of natural number n and point P performed by multiple repeated additions
- Numbers are grouped into powers of 2 to achieve logarithmic runtime, e.g. $25P = P + 8P + 16P$
- This is possible if and only if the n is known!
- If n is unknown for $nP = Q$, a logarithm has to be solved, which is possible if the coordinate values are chosen from $\mathbb{R}$
- For $\mathbb{Z}_p$ and $GF(2^n)$ the discrete logarithm problem for elliptic curves has to be solved, which cannot be done efficiently!
- Note: it is not defined how two points are multiplied, but only a natural number n and point P

### Foundations of ECC - Curves over $\mathbb{Z}_p$
- Over $\mathbb{Z}_p$ the curve degrades to a set of points
- For: $y^2=x^3-3x+5\ mod\ 19$
  - ![](Assets/NetworkSecurity-ecc-5.png)
  - Note: For some x values, there is no y value!

### Foundations of ECC - Calculate the y-values in $\mathbb{Z}_p$
- In general a little bit more problematic: determine the y-values for a given x (as its square value is calculated) by $y^2\equiv f(x)\ mod\ p$
- Hence p is often chosen s.t. $p\equiv 3\ mod\ 4$
- Then y is calculated by $y_1\equiv f(x)^{\frac{p+1}{4}}$ and $y_2\equiv -f(x)^{\frac{p+1}{4}}$ if and only if a solution exists at all
- Short proof:
  - From the Euler Theorem 3 we know that $f(x)^{p-1}\equiv 1\ mod\ p$
  - Thus the square root must be 1 or -1 $f(x)^{\frac{p-1}{2}}\equiv\pm 1\ mod\ p$
- Case 1: $f(x)^{\frac{p-1}{2}}\equiv1\ mod\ p$
    - Multiply both sides by f(x): $f(x)^{\frac{p-1}{2}}\equiv f(x)\equiv y^2\ mod\ p$
    - As $p + 1$ is divisible by 4 we can take the square root so that $f(x)^{\frac{p-1}{2}}\equiv y\ mod\ p$
- Case 2: In this case no solution exists for the given x value (as shown by Euler)

### Foundations of ECC - Addition and Multiplication in $\mathbb{Z}_p$
- Due to the discrete structure point mathematical operations do not have a geometric interpretation any more, but
- Algebraic addition similar to addition over $\mathbb{R}$
- If the inverse point is added to P, the line and ,,curve'' still intersect in ,,infinity''
- All x- and y-values are calculated mod p
- Division is replaced by multiplication with the inverse element of the denominator
  - Use the Extended Euclidean Algorithm with w and p to derive the inverse $-w$
- Algebraic multiplication of a natural number n and a point P is also performed by repeated addition of summands of the power of 2
- The discrete logarithm problem is to determine a natural number n in $nP=Q$ for two known points P and Q

### Foundations of ECC - Size of generated groups
- Please note that the order of a group generated by a point on a curve over $\mathbb{Z}_p$ is not $p-1$!
- Determining the exact order is not easy, but can be done in logarithmic time by Schoofs algorithm [Sch85] (requires much more mathematical background than desired here)
- But Hasse’s theorem on elliptic curves states that the group size n must lay between: $p+1 - 2\sqrt{p}\leq n\leq p+1+2\sqrt{p}$
- As mentioned before: Generating rather large groups is sufficient

### Foundations of ECC - ECDH
- The Diffie-Hellman-Algorithm can easily be adapted to elliptic curves
- If Alice (A) and Bob (B) want to agree on a shared secret s:
  - A and B agree on a cryptographically secure elliptic curve and a point P on that curve
  - A chooses a random number q:
    - A computes $Q=qP$ and transmits Q to Bob
  - B chooses a random number r:
    - B computes $R=rP$ and transmits P to Alice
  - Both sides compute the common secret:
    - A computes $S=qR$
    - B computes $S’=rQ$
    - As $qrP=rqP$ the secret point $S=S’$
- Attackers listening to the public channel can only compute S, if able to compute either q or r which are the discrete logarithms of Q and R for the point P

### Foundations of ECC - EC version of ElGamal Algorithm
- Adapting ElGamal for elliptic curves is rather straight forward for the encryption routine
- To set up a key pair:
  - Choose an elliptic curve over a finite field, a point G that generates a large group, and a random number v such that $1 < v < n$, where n denotes to the size of the induced group, Calculate: $Y = vG$
  - The public key is $(Y,G,curve)$
  - The private key is v
- To encrypt a message:
  - Choose a random $k\in\mathbb{Z}^+$ with $k<n-1$, compute $R=kG$
  - Compute $S=M+kY$, where M is a point derived by the message
    - Problem: Interpreting the message m as a x coordinate of M is not sufficient, as the y value does not have to exist
    - Solution from [Ko87]: Choose a constant c (e.g. 100) check if $cm$ is the x coordinate of a valid point, if not try $cm+1$, then $cm+2$ and so on
    - To decode m: take the x value of M and do an integer division by c (receiver has to know c too)
  - The ciphertext are the points $(R,S)$
  - Twice as long as m, if stored in so-called compressed form , i.e. only x coordinates are stored and a single bit, indicating whether the larger or smaller corresponding y-coordinate shall be used
- To decrypt a message:
  - Derive M by calculating $S-vR$
  - Proof: $S-vR=M+kY-vR =M+kvG-vkG= M+O= M$
- To sign a message:
  - Choose a random $k\in\mathbb{Z}^+$ with $k<n-1$, compute $R = kG$
  - Compute $s=k^{-1}(m+rv) mod\ n$, where $r$ is the x-value of R
  - The signature are $(r,s)$, again about as twice as long as n
- To verify a signed message:
  - Check if the point $P=ms^{-1}G+rs^{-1}Y$ has the x-coordinate r
  - Note: $s^{-1}$ is calculated by the Extended Euclidian Algorithm with the input s and n (the order of the group)
  - Proof: $ms^{-1}G+rs^{-1}Y = ms^{-1}G+rs^{-1}vG = (m+rv)(s^{-1})G = (ks)(s^{-1})G = kG = R$
- Security discussion:
  - As in the original version of ElGamal it is crucial to not use k twice
  - Messages should not be signed directly
  - Further checks may be required, i.e., G must not be O, a valid point on the curve etc. (see [NIST09] for further details)

### Foundations of ECC - Security
- The security heavily depends on the chosen curve and point:
- The discriminant of the curve must not be zero, i.e., $4a^3+27b^2\not\equiv 0\ mod\ p$ otherwise the curve is degraded (a so called ,,singular curve'' )
- Menezes et. al. have found a sub-exponential algorithm for so-called ,,supersingular elliptic curves'' but this does not work in the general case [Men93a]
- The constructed algebraic groups should have as many elements a possible
- This class will not go into more details of elliptic curve cryptography as this requires way more mathematics than desired for this course...
- For non-cryptographers it is best to depend on predefined curves, e.g., [LM10] or [NIST99] and standards such as ECDSA
- Many publications choose parameters a and b such that they are provably chosen by a random process (e.g. publish x for $h(x)=a$ and $y$ for $h(y) = b$); Shall ensure that the curves do not contain a cryptographic weakness that only the authors knows about
- The security depends on the length of p
  - Key lengths with comparable strengths according to [NIST12]:
    | Symmetric Algorithms | RSA   | ECC     |
    | -------------------- | ----- | ------- |
    | 112                  | 2048  | 224-255 |
    | 128                  | 3072  | 256-383 |
    | 192                  | 7680  | 384-511 |
    | 256                  | 15360 | > 512   |
- The security also heavily depends on the implementation!
  - The different cases (e.g. with O) in ECC calculation may be observable, i.e., power consumption and timing differences
  - Attackers might deduct side-channel attacks, as in OpenSSL 0.9.8o [BT11]
    - Attacker may deduce the bit length of a value k in $kP$ by measuring the time required for the square and multiply algorithm
    - Algorithm was aborted early in OpenSSL when no further bits where set to ,,1''
  - Attackers might try to generate invalid points to derive facts about the used key as in OpenSSL 0.9.8g, leading to a recovery of a full 256-bit ECC key after only 633 queries [BBP12]
- Lesson learned: Do not do it on your own, unless you have to and know what you are doing!

### Foundations of ECC - Further remarks
- As mentioned earlier it is possible to construct cryptographic elliptic curves over $G(2^n)$, which may be faster in hardware implementations
  - We refrained from details as this would not have brought many different insights!
- Elliptic curves and similar algebraic groups are an active field of research and allow other advanced applications e.g.:
  - So-called Edwards Curves are currently discussed, as they seem more robust against side-channel attacks (e.g. [BLR08])
  - Bilinear pairings allow
    - Programs to verify that they belong to the same group, without revealing their identity (Secret handshakes, e.g. [SM09])
    - Public keys to be structured, e.g. use ,,Alice'' as public key for Alice (Identity based encryption, foundations in [BF03])
- Before deploying elliptic curve cryptography in a product, make sure to not violate patents, as there are still many valid ones in this field!

## Conclusion
- Asymmetric cryptography allows to use two different keys for:
  - Encryption / Decryption
  - Signing / Verifying
- The most practical algorithms that are still considered to be secure are:
  - RSA, based on the difficulty of factoring and solving discrete logarithms
  - Diffie-Hellman (not an asymmetric algorithm, but a key agreement protocol)
  - ElGamal, like DH based on the difficulty of computing discrete logarithms
- As their security is entirely based on the difficulty of certain mathematical problems, algorithmic advances constitute their biggest threat
- Practical considerations:
  - Asymmetric cryptographic operations are about magnitudes slower than symmetric ones
  - Therefore, they are often not used for encrypting / signing bulk data
  - Symmetric techniques are used to encrypt / compute a cryptographic hash value and asymmetric cryptography is just used to encrypt a key / hash value


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
- [Bre88a] D. M. Bressoud. - Factorization and Primality Testing
- [Cor90a] T. H. Cormen, C. E. Leiserson, R. L. Rivest. _Introduction to Algorithms.
- [DH76] W. Diffie, M. E. Hellman - New Directions in Cryptography
- [ElG85a] T. ElGamal - A Public Key Cryptosystem and a Signature Scheme based on Discrete Logarithms.
- [Kob87a] N. Koblitz - A Course in Number Theory and Cryptography
- [Men93a] A. J. Menezes - Elliptic Curve Public Key Cryptosystems.
- [Niv80a] I. Niven, H. Zuckerman - An Introduction to the Theory of Numbers
- [RSA78] R. Rivest, A. Shamir und L. Adleman - A Method for Obtaining Digital Signatures and Public Key Cryptosystems
- [KAFL10] T. Kleinjung, K. Aoki, J. Franke, A. Lenstra, E. Thomé, J. Bos, P. Gaudry, A. Kruppa, P. Montgomery, D. Osvik, H. Te Riele, A.Timofeev, P. Zimmermann - Factorization of a 768-bit RSA modulus
- [LM10] M. Lochter, J. Merkle - Elliptic Curve Cryptography (ECC) Brainpool Standard Curves and Curve Generation_ 
- [NIST99] NIST - Recommended Elliptic Curves for Federal Government Use
- [NIST12] NIST - Recommendation for Key Management: Part 1: General (Revision 3)
- [Ko87] N. Koblitz - Elliptic Curve Cryptosystems
- [BBP12] B.B. Brumley, M. Barbosa, D. Page, F. Vercauteren - Practical realisation and elimination of an ECC-related software bug attack
- [BT11] B.B. Brumley, N. Tuveri - Remote timing attacks are still practical
- [BLR08] D. Bernstein, T. Lange, R. Rezaeian Farashahi - Binary Edwards Curves
- [NIST09] NIST - Digital Signature Standard (DSS)
- [SM09] A. Sorniotti, R. Molva - A provably secure secret handshake with dynamic controlled matching
- [BF03] D. Boneh, M. Franklin - Identity-Based Encryption from the Weil Pairing
- [Sch85] R. Schoof - Elliptic Curves over Finite Fields and the Computation of Square Roots mod p