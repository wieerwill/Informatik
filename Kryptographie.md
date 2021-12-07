- [Einführung](#einführung)
- [Symmetrische Verschlüsselung, Sicherheitsmodelle](#symmetrische-verschlüsselung-sicherheitsmodelle)
  - [Einmalige symmetrische Verschlüsselung und klassische Verfahren](#einmalige-symmetrische-verschlüsselung-und-klassische-verfahren)
    - [Kryptosysteme und possibilistische Sicherheit](#kryptosysteme-und-possibilistische-sicherheit)
  - [Wiederholung: Elementare Wahrscheinlichkeitsrechnung](#wiederholung-elementare-wahrscheinlichkeitsrechnung)
  - [Informationstheoretische Sicherheit](#informationstheoretische-sicherheit)
  - [Fallstudie für Cyphertext-only-Angriffe: Vigenère-Chiffre](#fallstudie-für-cyphertext-only-angriffe-vigenère-chiffre)
    - [Die Vigenère-Chiffre und Angriffe bei bekannter Schlüssellänge](#die-vigenère-chiffre-und-angriffe-bei-bekannter-schlüssellänge)
    - [Der Kasiski-Test](#der-kasiski-test)
    - [Koinzidenzindex und Friedman-Methode](#koinzidenzindex-und-friedman-methode)
- [Frische symmetrische Verschlüsselung und Blockchiffren](#frische-symmetrische-verschlüsselung-und-blockchiffren)
  - [Substitutions-Permutations-Kryptosysteme (SPKS)](#substitutions-permutations-kryptosysteme-spks)
    - [Einschub: Endliche Körper](#einschub-endliche-körper)
    - [AES: Advanced Encryption Standard](#aes-advanced-encryption-standard)
        - [AES-Chiffrieralgorithmus](#aes-chiffrieralgorithmus)
        - [Die S-Box von AES:](#die-s-box-von-aes)
        - [AES-Rundenschlüsselberechnung](#aes-rundenschlüsselberechnung)
     
Literaturempfehlung:
- Ralf Küsters und Thomas Wilke: Moderne Kryptographie,Vieweg+ Teubner 2011
- Jonathan Katz und Yehuda Lindell, Introduction to Modern Cryptography,CRCPress, 2015
- Ulrike Baumann, Elke Franz, Andreas Pfitzmann,Kryptographische Systeme, SpringerVieweg 2014
- Albrecht Beutelspacher, Heike B. Neumann,Thomas Schwarzpaul: Kryptographie in Theorie und Praxis,Vieweg, 2005
- Douglas R. Stinson: Cryptography-Theory and Practice,CRC Press, 1995
- Dietmar Wätjen: Kryptographie, Spektrum Akademischer Verlag, 2004
- David Kahn: The Codebreakers, Scribner, 1996

# Einführung
_$\kappa\ro\vartheta\pi\tau\delta\zeta$_= kryptos(griech.): verborgen
_$\gamma\ro\alpha\varphi\epsilon\iota\nu$_ = graphein (griech.): schreiben

Kryptographie im klassischen Wortsinn betrifft also Methoden,Nachrichten so zu schreiben, dass sie ,,verborgen'' bleiben,das heißt von keinem Unberechtigten (mit)gelesen werden können.Das hier angesprochene ,,Sicherheitsziel'' heißt ,,Vertraulichkeit'' oder ,,Geheimhaltung'' oder Konzelation (concelare(lat.):sorgfältig verbergen, davon englisch: conceal). Verfahren, die dieses Ziel erreichen,heißen Konzelationssysteme.

Simples Schema für dieses Problem (Aktion schreitet von links nach rechts fort, zu Schlüsseln später mehr):
|                |                                           |                                                                       |                                                                  |
| -------------- | ----------------------------------------- | --------------------------------------------------------------------- | ---------------------------------------------------------------- | ------------------------ |
| Sender         | Verschlüsselung                           | Chiffretext y                                                         | Entschlüsselung                                                  | Empfänger                |
| Alice          | (Chiffrierung, authentisieren, signieren) | über                                                                  | (Dechiffrierung, Absenderdentität prüfen, Unversehrtheit prüfen) | Bob                      |
| hat Klartext x |                                           | unsicheren Kanal                                                      |                                                                  | rekonstruiert Klartext x |
|                | Schlüssel k                               |                                                                       | Schlüssel k′                                                     |
|                |                                           | Gegnerin Eva (enemy, eavesdropper, Kryptoanalytiker/in, Angreifer/in) |                                                                  |                          |

,,Alice''  ist dabei ein eingebürgerter Name für die sendende Instanz, ,,Bob'' der für die empfangende Instanz. Dabei kann es sich um Personen, Organisationen oder auch Computer(systeme) o. ä. handeln. Der Verschlüsselungsbereich von Alice (links von der zweiten senkrechten Linie) ist gegen Zugriffe von Eva geschützt, ebenso der Entschlüsselungsbereich von Bob(rechts von der dritten senkrechten Linie).

Beispiel 1: 
- Alice = Bank (und ihr Computersystem), 
- Bob = Online-Bankkunde, 
- Nachricht x = Kontoauszug. Übermittlung des Kontoauszugs über das Internet (,,offenerKanal'').
- Sicherheitsziel: Stelle sicher, dass die Angreifer in Eva (der Internetkriminelle) die vertrauliche Information nicht mitlesen kann, obgleich sie die verschlüsselte Version y der Nachricht sehen kann.

Beispiel 2:
- Alice = Bob = eine Universität.
- Nachricht x = die Liste aller persönlichen Daten aller Studierenden. Diese große Datei soll auf einem Cloudserver (im Ausland) gespeichert werden. Dazu wird sie als y verschlüsselt,um Zugriffe dritter Parteien auf die vertraulichen Daten zu verhindern.

Im Kontext der modernen elektronischen Kommunikation ergeben sich neben der Konzelation auch weitere, andersartige und unabhängige Aufgaben, die mit kryptographischen Methoden,also von Kryptosystemen ausgeführt werden. Wir führen auf:
- Konzelation: Geheimhaltung/Vertraulichkeit/Zugriffsschutz(kein Unberechtigter kann Nachrichteninhalt mithören oder mitlesen)
- Integrität/Fälschungsschutz (stelle sicher, dass Nachrichten auf dem Übertragungsweg nicht manipuliert worden sind)
- Authentizität/Signaturen: Garantiere Absenderidentität (Bob kann kontrollieren, dass Nachricht vom behaupteten Absender Alice kommt)
- Nichtabstreitbarkeit (Bob kann gegenüber Dritten beweisen,dass die Nachricht in der empfangenen Form vom behaupteten Absender Alice kam)
- ...

Integrität bzw. Authentisierung: Hier ist die Aufgabenstellung verändert. Eva hat nicht nur die Fähigkeit, Nachrichten passiv mitzulesen, sondern sie kann in den Kommunikationskanal eingreifen. Sie kann Nachrichten abfangen(und sogar die Weiterleitungverhindern) und/oder eine neue bzw. veränderte Nachricht in den Kanal einspeisen. Ihre Absicht ist es,Bob dazu zu bringen, diese Nachricht für die echte von Alice abgeschickte Nachricht zu halten.Diese Art von Angriff soll verhindert werden. Hierfür verwendet man einen Mechanismus,der message authentication code (MAC) heißt. Darunter kann man sich eine Funktion vorstellen, die aus einer Nachricht x einen(nicht allzu langen) Code $mac=MAC(x)$ berechnet. Diese Funktion ist ein Geheimnis von legitimen Sendern von Nachrichten an Bob. Insbesondere kann Eva bei gegebener Nachricht x′ (verwandt zu x oder nicht) keinen korrekten MAC für x′ berechnen. Bob verfügt über ein Prüfverfahren, das es ihm erlaubt, ein empfangenes Paar $(x,mac)$ darauf zu testen, ob der zweite Teil der zu x gehörende MAC-Wert ist. Wenn Alice die einzige Instanz ist,die die geheime Funktion MAC kennt, dann kann Bob sogar überprüfen, ob Alice tatsächlich die Absenderin ist.

Beispiel 3:
- Alice = Bankkundin,
- Bob = Bank,
- Nachricht = Überweisungsauftrag
- **Integrität**: Stelle sicher, dass Eva nicht Aufträge von Alice,obgleich über offenen Kanal (Internet) übermittelt, abfangen und durch manipulierten oder ganz neuen Auftrag ersetzen kann(nicht Kontonummern oder Beträge ändern kann).
- **Authentizität**: Eva soll nicht, ohne Aktivität von Alice,der Bank vortäuschen können, dass sie Alice ist, und Aufträge erteilen.
- Die **Nichtabstreitbarkeit** ist eine noch stärkere Anforderung an Geschäftsvorgänge, die über das Internet abgewickelt werden. Bei Streit (vor Gericht) soll die Bank nachweisen können, dass ein Auftrag, den sie ausgeführt hat, tatsächlich von Alice stammt. (Im analogen Leben wird dies durch eine als echt nachgewiesene Unterschrift bewirkt.) Hier übernimmt also sogar Alice, die Kundin,die Rolle der Gegenspielerin.

Die Kryptographie im engeren und ,,klassischen'' Sinn beschäftigt sich mit Verfahren, um in verschiedenen Kommunikationsszenarien eine gegen Angriffe von Gegnern  (Mitlesen, Verändern, Unterschieben, Abstreiten)  abgesicherte Kommunikation zu ermöglichen.

Auf der anderen Seite steht die Kryptoanalyse(englisch cryptanalysis). Ursprünglich und jahrhundertelang entwickelten Kryptoanalytiker Methoden zum ,,Brechen'' von Konzelationssystemen, also zum unberechtigten Mitlesen trotz Verschlüsselung. Heute gehören zur Kryptoanalyse auch Angriffe auf andere kryptographische Methoden, mit dem Ziel, ihre Sicherungsfunktion zu umgehen. Es ist wichtig, im Auge zu behalten, dass die Gleichsetzung von Kryptoanalyse mit der Absicht, unberechtigt in die Kommunikation einzugreifen, nicht unbedingt richtig ist. Um die Sicherheit von kryptographischen Verfahren sicherzustellen, ist es unbedingt nötig, dass mit kryptoanalytischen Methoden versucht wird, Schwachstellen solcher Verfahren offenzulegen.Erst die Kenntnis von Schwachstellen macht es möglich, diese zu beseitigen.

Eine klassische Einteilung ist also folgende:
- **Kryptologie** = Kryptographie  (Entwicklung von kryptographischen Verfahren) + Kryptoanalyse (Versuche, kryptographische Verfahren zu brechen).

Für sehr lange Zeit war (und ist auch immer noch) die Beziehung zwischen diesen beiden Seiten die eines Katz-und Maus-Spiels. Die Kryptographie war bestrebt, immer cleverere und ,,sicherere'' Verfahren zu entwickeln, die Kryptoanalyse versuchte, Schwächen in diesen Verfahren aufzuspüren, und zwar sowohl, um unberechtigte Zugriffe auszuführen, als auch, um die Schwächen offenzulegen, um ihre Beseitigung zu ermöglichen. (Die Liste der jemals vorgeschlagenen Systeme und Verfahren,die sich früher oder später als ,,schwach'' erwiesen, ist sehr lang.)

Eine Randbemerkung: Man könnte auf den ersten Blick den Eindruck bekommen, dass das Anliegen,  Nachrichten vertraulich und ohne Manipulationen auszutauschen, zunächst einmal legitim ist und dass Angriffe illegitim sind.Dieser Eindruck wird eventuell durch die Verwendung der harmlosen Bezeichnungen ,,Alice'' und ,,Bob'' für die Kommunikationsparteien einerseits und ,,Eva'' (Gegnerin, Angreiferin, usw.) andererseits verstärkt. Sicherlich ist diese Sicht für viele Situationen insbesondere in der Geschäftswelt passend. Es zeigt sich aber nach kurzem Überlegen, dass nicht in allen Fällen der Schutz das legale oder moralisch gute Ziel sein muss, dass kryptographische Verfahren auch für rechtswidrige, unethische, gefährliche, völkerrechtswidrige, terroristische Zwecke eingesetzt werden (können) und die Kryptoanalyse, das Eingreifen in solche Kommunikation,manchmal rechtlich und moralisch geboten ist. Man landet hier schnell bei interessanten und schwierigen ethischen Fragen. Wie sehr viele Technologien, natürlich eigentlich die gesamte IT und die Informatik, ist die Kryptologie eine Wissenschaft, deren verschiedene Ergebnisse und Entwicklungen für erstrebenswerte wie auch für schlimme Ziele benutzt werden können, wir sind hier beim grundlegenden Thema ,,DualUse''.

Seit den 1980er Jahren wurde eine neue Sicht auf die Kryptologie entwickelt. Dabei schlägt man für verschiedene Kommunikationsszenarien und Sicherheitsziele (Konzelation, Integrität, Authentisierung, Nichtabstreitbarkeit, usw.) ganz präzise mathematische Formulierungen vor, sogenannte Sicherheitskonzepte. Anschließend ist man, wenigstens im Prinzip, in der Lage, Verfahren darauf abzuklopfen, ob sie diese präzise formulierten Sicherheitsanforderungen erfüllen.

Die ,,moderne'' Kryptologie beschäftigt sich also mit kryptographischen Verfahren, mit kryptoanalytischen Verfahren, mit Sicherheitskonzepten und mit mathematischen Methoden zur Untersuchung dieser Dinge, abstrakt und an konkreten Verfahren.
Achtung: Man findet (heute noch mehr als früher) oft die Bezeichnung ,,Kryptographie'' bzw. ,,cryptography'' für die gesamte Kryptologie. Dies betrifft auch alle Titel von Büchern, die trotz des Namens ,,Kryptographie'' bzw. ,,cryptography'' alle Aspekte behandeln.

Ein Zitat aus dem Buch von Katz und Lindell: Moderne Kryptographie ist die Wissenschaft von den mathematischen Methoden, die man benutzen kann, um digitale Information, Systeme und verteilte Anwendungen gegen Eingriffe (,,Angriffe'') von unberechtigten Parteien zu schützen. Dabei geht es sowohl um die Konstruktion von kryptographischen Systemen und um die Entwicklung und Untersuchung von Angriffen als auch um Beweise für die Sicherheit von Systemen. 

Leider sind die Sicherheitsbeweise in den allermeisten Fällen relativ zu unbewiesenen (aber wenigstens plausiblen)mathematischen oder komplexitätstheoretischen oder kryptographischen Annahmen.

In der Vorlesung folgen wir zum Teil den klassischen Ansätzen, ab er stellen auch den modernen Ansatz im Prinzip vor und verstehen ihn an ausgewählten Beispielen.

Bei der Diskussion im Stil des modernen Ansatzes muss man immer die folgenden Komponenten beschreiben: Was ist die Kommunikationssituation, welches sind die Akteure, was ist das Sicherheitsziel? Bei Konzelationssituationen gibt es Alice und Bob, wobei Alice eine Nachricht oder mehrere Nachrichten an Bob übermitteln möchte. Gegenspielerin Eva kann die gesendeten Nachrichten mitlesen und hat eventuell Zugriff auf einige Klartext-Chiffretest-Paare, ab er sie kann nicht anderweitig eingreifen. Das Sicherheitsziel ist grob gesprochen,dass Eva aus einem Chiffretext y keine ,,nicht trivialen Informationen''  über den Klartext x erlangen kann. (Ein ,,triviale Information'' , die sie immer erhält, ist die Tatsache, dass eine Nachricht geschickt wurde.) Es gibt mehrere Präzisierungen dieser Situation, die von folgenden Faktoren abhängen:
- Art der Kommunikation
- Evas Fähigkeiten und Möglichkeiten (kann sie nur mitlesen oder auch Nachrichten einschleusen?)
- was wir als ,,nichttriviale Information'' bezeichnen

Wir werden zumindest in einfachen Situationen präzise definieren, was es heißt, ,,das Sicherheitsziel zu erreichen'' und dabei die Komplexität der Anforderungen schrittweise erhöhen.
Exemplarisch wird diskutiert werden, die Verfahren für einfachere Situation zu Verfahren für kompliziertere Verfahren ausgebaut werden können.

Schließlich muss noch kurz das Konzept ,,Schlüssel''  diskutiert werden. Wir beginnen mit einem Beispiel, nämlich einem jahrtausende alten Konzelationssystem.

Beispiel: Cäsar-Chiffre. Betrachte das antike lateinische Alphabet mit 21 Buchstaben:
    A B C D E F G H I K L M N O P Q R S T V X
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

Cäsar ließ Texte verschlüsseln, indem er folgende Ersetzung Buchstabe für Buchstabe durchführen ließ:
    A B C D E F G H I K L M N O P Q R S T V X
    D E F G H I K L M N O P Q R S T V X A B C

(Man nimmt immer den Buchstaben, der im Alphabet drei Positionen ,,weiter rechts'' steht, mit ,,wrap around'' am Ende.)
Beispiel:
- Klartext x= IMPETVS ( ,,Angriff '' )
- wird y= MPSHABX
 
Der Nachteil ist offensichtlich: Wer den Trick kannte, konnte jede Nachricht mitlesen.

Eine einfache ,,Verbesserung'' dieses sehr primitiven Ansatzes ist Folgendes: Verschiebe zyklisch um eine andere Anzahl von Buchstaben als 3. Für eine Verschiebung um $k=9$ Positionen ergibt sich:
    A B C D E F G H I K L M N O P Q R S T V X
    K L M N O P Q R S T V X A B C D E F G H I

Um hier die Verschlüsselung und die Entschlüsselung durchzuführen, musste man als ,,Schlüssel''  nur das Bild von A kennen (im Beispiel K), alternativ die Verschiebeweite k
als Zahl. Es gibt dann 21 Schlüssel (wobei zunächst ,,A'' oder Verschiebeweite 0 zunächst ziemlich sinnlos erscheint).Diese Methode heißt Verschiebechiffre.

Eine ziemlich naheliegende Verallgemeinerung von Verschiebechiffren ist auf den ersten Blick viel mächtiger: Sie sagt, dass das Bild eines Buchstabens ein ganz beliebiger anderer Buchstabe sein soll. Dabei müssen natürlich verschiedene Buchstaben auf verschiedene Buchstaben abgebildet werden. Es er gibt sich eine ,,Substitutionschiffre'' ,die durch eine Tabelle mit ganz beliebiger Buchstabenanordnung gegeben ist. Beispiel:
    A B C D E F G H I K L M N O P Q R S T V X
    F Q M P K V T A E L H N I G D S B X O R C

Wenn man hier ver- und entschlüsseln möchte, muss man die gesamte zweite Tabellenzeile kennen. Diese kann hier also als ,,Schlüssel''  dienen. Es gibt $21!\approx 5,11* 10^{19}$ viele verschiedene Schlüssel.

Viel später (16.Jh.) wurde die ,,Vigenère-Verschlüsselung'' vorgeschlagen: Man benutzt dabei nicht einen Schlüssel,der dann auf jeden Buchstaben des Klartextes angewendet wird,sondern ein Schlüsselwort $a_0,...,a_{s-1}$ größerer Länge $s > 1$. Man könnte (und das wurde auch so getan) s verschiedene Substitutionschiffren benutzen. Zum Ver-und Entschlüsseln
würde man dann eine Liste von s vielen Permutationen der 21 Buchstaben benötigen. Einfacher ist es, s Verschiebe chiffren zu benutzen. Dann ist ein Schlüssel tatsächlich ein Wort über dem Alphabet $\{A,...,X\}$.

Man geht dann also wie folgt vor: $x=x_0...x_{n-1}$ ist der Klartext, $k=a_0 ...a_{s-1}$ der Schlüssel.Verschlüssle x mit den durch k gegebenen Verschiebungen wie folgt:
$x_0$ mit $A \rightarrow a_0$ ,$x_2$ mit $A \rightarrow a_2,... ,x_{s-1}$ mit $A\rightarrow a_{s-1}$.

Wenn der Schlüssel k aufgebraucht ist, benutze ihn wieder von vorne: Verschlüssle $x_i,i\geq s$, mit Verschiebung $A \rightarrow a_{i\ mod\ s}$.

Beispiel: Schlüssel ist $k=ARCVS$ (für arcus, Bogen). Buchstaben an Positionen $0 , 5 , 10 ,...$ bleiben gleich,da A Position 0 hat, Buchstaben an Positionen $1 , 6 , 11 ,...$ werden um 16 Positionen verschoben (da R Position 16 hat),Buchstaben an Positionen $2 , 7 , 12 ,...$ werden um 2 Positionen verschoben (da C Position 2 hat), und so weiter.Es ergibt sich:

|                           |                             |
| ------------------------- | --------------------------- |
| (wiederholter) Schlüssel: | A R C V S A R C V S A R C V |
| Klartext:                 | S E N A T V S R O M A N V S |
| Chiffretext:              | S X P V P V N T M H A G A Q |

Ab hier betrachten wir meist nur Verfahren, die Schlüssel verwenden. Bei kryptographischen Verfahren mit Schlüsseln betrachten wir zwei grundsätzlich unterschiedliche Ansätze:
- Symmetrische(Private-Key)-Kryptographie: Es gibt einen geheimen Schlüssel $k$, den beide der kommunizierenden Parteien kennen müssen. Bei Konzelationssystemen bedeutet dies etwa, dass das Verschlüsselungsverfahren und das Entschlüsselungsverfahren beide diesen Schlüssel $k=k′$ benutzen. Symmetrische Verfahren sind unser erstes Thema. Ein aktuelles standardisiertes symmetrisches Verfahren ist etwa AES
 (AdvancedEncryptionStandard).
- Asymmetrische (Public-Key-) Kryptographie: Nur eine Seite hat einen geheimen Schlüssel $k′$, die andere Seite benutzt einen ,,öffentlichen'' Schlüssel $k\not =k′$. Beispiel: Bei  Konzelationssystemen hat der Empfänger (Bob) einen geheimen Schlüssel $k′$, der Sender (Alice) benutzt zur Verschlüsselung einen von Bob ausgegebenen öffentlichen Schlüssel $k\not =k′$. (Bei Authentisierung oder bei digitalen Signaturen ist es umgekehrt.) Asymmetrische Verfahren sind unser zweites Thema. Ein weit verbreitetes asymmetrisches Verfahren ist RSA (nach den Erfindern Rivest, Shamir und Adleman).

Das Kerckhoffs-Prinzip (1883, Auguste Kerckhoffs von Nieuwenhof(1835, 1903), niederländischer Linguist und Kryptologe) besagt,dass man davon ausgehen muss, dass Eva die Struktur des Verschlüsselungsverfahrens kennt und die Sicherheit nur von der Geheimhaltung des Schlüssels abhängen darf.

Begründung:
1. Geheimhaltung eines Verfahrens ist schwer sicherzustellen.(Erfahrungstatsache.)
2. Verfahren sind aufwendig zu entwickeln. Ist das geheime Verfahren einmal bekannt, so wäre Verfahren nutzlos. (Mehrfach passiert: Enigma, GSM-Verfahren A5/1 und A5/2 (Mobilfunknetze),Stromchiffre RC4.)
3. Allgemein bekannte Verfahren können von mehr Experten auf ,,Sicherheit'' geprüft werden. Findet niemand einen erfolgreichen Angriff, so kann man eher auf Sicherheit des Verfahrens vertrauen.
4. Nur offen gelegte Verfahren können standardisiert werden und weite Verbreitung finden (DES, AES).

Bemerkung: In der Realität gibt es auch (viele) geheimgehaltene Systeme. Naturgemäß werden solche nicht in Vorlesungen behandelt.

# Symmetrische Verschlüsselung, Sicherheitsmodelle
In diesem Teil beschäftigen wir uns ausschließlich mit symmetrischen Konzelationsverfahren, bei denen also Alice und Bob sich auf einen geheimen Schlüssel geeinigt haben.

Mögliche Kommunikationsszenarien:
- Alice will nur einmal eine Nachricht (mit bekannter maximaler Länge) an Bob schicken.
- Alice will mehrere Nachrichten mit bekannter maximaler Länge schicken.
- Alice will beliebig viele Nachrichten beliebiger Länge schicken.

Angriffsszenarien/Bedrohungsszenarien: 
Das Kerkhoffs-Prinzip impliziert, dass Eva das Ver- und das Entschlüsselungsverfahren kennt (nur den Schlüssel nicht). Folgende Möglichkeiten kann sie weiterhin haben:
1. Nur Mithören: Nur-Chiffretext-Angriff (ciphertext-onlyattack,COA).
2. Mithören + Eva sind einige Paare von Klartext und Chiffretext bekannt: Angriff mit bekannten Klartexten(known-plaintextattack, KPA). 
    - Beispiele: Einige Klartext-Chiffretext-Paare sind aus Versehen oder absichtlich bekannt geworden, Eva hat einige Chiffretexte mit großem Aufwand entschlüsselt, Eva war früher mit der Verschlüsselung beauftragt (ohne den Schlüssel zu kennen).
3. Mithören + Eva kann einige von ihr gewählte Klartexte verschlüsseln: Angriff mit Klartextwahl (chosen-plaintext attack, CPA). 
   - Beispiele: Eva war früher mit der Verschlüsselung beauftragt (ohne den Schlüssel zu kennen)
   - CPA ist immer möglich bei asymmetrischer Verschlüsselung,die wir aber erst später betrachten.
4. Mithören + Eva kann einige von ihr gewählte Chiffretexte entschlüsseln: Angriff mit Chiffretextwahl (chosen-cyphertext attack, CCA).
    - Beispiele: Verschiedene Authentisierungsverfahren verlangen, dass die zu prüfende Partei einen Chiffretext entschlüsselt und den Klartext zurücksendet; Eva war früher mit der Entschlüsselung beauftragt (ohne den Schlüssel zu kennen).
5. Eva hat Möglichkeiten 3. + 4.

Wesentlich sind auch noch die Fähigkeiten von Eva. Einige Beispiele:
1. Unbegrenzte Rechenkapazitäten. Eva soll keine Information über den Klartext erhalten, egal wieviel sie rechnet (,,informationstheoretische Sicherheit'').
2. Konkrete maximale Anzahl an Rechenoperationen, z.B. $2^{60}$. ,,Konkrete Sicherheit'': Mit diesem Aufwand erfährt Eva ,,(fast) nichts'' über Klartexte.
3. Begrenzter Speicher (z.B. 1000 TB). Analog zu 2.
4. Im Design des Verschlüsselungsverfahrens gibt es einen Stellhebel, einen ,,Sicherheitsparameter''. (Beispiel: Schlüssellänge, Rundenzahl bei DES und AES.) Je nach Leistungsfähigkeit von Eva kann man durch entsprechende Wahl dieses Parameters die Sicherheit des Systems an eine gegebene (geschätzte) Rechenzeitschranke anpassen.
5. Man betrachtet ganze Familien von Verschlüsselungsverfahren, für immer längere Klar-und Chiffretexte Typischerweise werden Verschlüsselung und Entschlüsselung von Polynomialzeitalgorithmen geleistet. Wenn asymptotisch, also für wachsende Textlänge, der Rechenzeitaufwand für Eva zum Brechen des Systems schneller als polynomiell wächst, kann man sagen, dass sie für genügend lange Texte keine Chance mehr hat,das System erfolgreich zu brechen. (,,Asymptotische Sicherheit'')

Wir untersuchen in diesem ersten Teil drei verschiedene Szenarien, jeweils symmetrische Konzelationssysteme,mit steigender Komplexität. Alice und Bob haben sich auf einen Schlüssel geeinigt.

1. Einmalige Verschlüsselung: Ein einzelner Klartext $x$ vorher bekannter Länge wird übertragen, Eva hört mit (COA).
   - Unvermeidlich: Triviale Information, z.B. der Sachverhalt,dass eine Nachricht übertragenwurde.
   - Was vermieden werden soll: Eva erhält nicht-triviale Information, z.B. dass der Klartext $x$ ist oder dass der Klartext aller Wahrscheinlichkeit nach weder $x_1$ noch $x_2$ ist.
   - Gegenstand der Steganographie sind Verfahren,Nachrichten so zu übertragen, dass noch nicht einmal die Existenz der Nachricht entdeckt werden kann.
2. Frische Verschlüsselung: Mehrere Klartexte vorher bekannter Länge werden übertragen, Eva hört mit,kann sich einige Klartexte verschlüsseln lassen (CPA).
   - Triviale Information: z.B.Anzahl der Nachrichten oder Klartext, falls Eva sich zufälligerweise vorher den ,,richtigen'' Klartext hat verschlüsseln lassen.
3. Uneingeschränkte symmetrische Verschlüsselung: Mehrere Klartexte verschiedener Länge, Eva hört mit, kann sich einige Klartexte verschlüsseln lassen (CPA).
   - Triviale Information: Analog zur frischen Verschlüsselung.

## Einmalige symmetrische Verschlüsselung und klassische Verfahren
Wir diskutieren hier eine einführende, einfache Situation, für symmetrische Konzelationssysteme und Sicherheitsmodelle. In einer Fallstudie betrachten wir Methoden zum ,,Brechen'' eines klassischen Kryptosystems.

### Kryptosysteme und possibilistische Sicherheit
**Szenarium 1** (Einmalige Verschlüsselung, COA): Alice möchte Bob einen Klartext vorher bekannter Länge schicken, Alice und Bob haben sich auf einen Schlüssel geeinigt, Eva hört den Chiffretext mit.

,,bekannte Länge'': Klartexte entstammen einer bekannten endlichen Menge $X$, z.B. $X=\{0,1\}^l$.

Fragen: Wie soll man vorgehen, damit das verwendete Verfahren als ,,sicher'' gelten kann? Was soll ,,sicher'' überhaupt bedeuten? Wie kann man ,,Sicherheit'' beweisen? Was sind die Risiken von Varianten (mehrere Nachrichten,längere Nachrichten usw.)?

**Definition 1.1** Ein Kryptosystem ist ein Tupel $S=(X,K,Y,e,d)$, wobei
- X und K nicht leere endliche Mengen sind [Klartexte bzw. Schlüssel],
- Y eine Menge ist [Chiffretexte], und
- $e:X\times K\rightarrow Y$ und $d:Y\times K\rightarrow X$ Funktionen sind [Verschlüsselungsfunktion bzw. Entschlüsselungsfunktion],

so dass Folgendes gilt:
1. $\forall x\in X\forall k\in K:d(e(x,k),k) =x$ (Dechiffrierbedingung)
2. $\forall y\in Y\exists x\in X,k\in K:y=e(x,k)$ (Surjektivität)

Bemerkung: Surjektivität kann immer hergestellt werden, indem man $Y$ auf das Bild $Bi(e) =e(X\times K)$ einschränkt. Die Forderung ist für unsere Analysen aber bequem.

Für festes $k\in K$ wird die Funktione $(.,k):X\rightarrow Y,x \rightarrow e(x,k)$ als Chiffre bezeichnet.

**Beispiel 1.2** Sei $n>0, X=\{a_i,b_i| 1\leq i\leq n\},K=\{k_0,k_1\},Y=\{A_i,B_i| 1\leq i\leq n\}$. Die Funktionen $e$ und $d$ sind als Tabellen gegeben:

| e     | $a_1$ | $b_1$ | $a_2$ | $b_2$ | ... | $a_n$ | $b_n$ |
| ----- | ----- | ----- | ----- | ----- | --- | ----- | ----- |
| $k_0$ | $A_1$ | $B_1$ | $A_2$ | $B_2$ | ... | $A_n$ | $B_n$ |
| $k_1$ | $B_1$ | $A_1$ | $B_2$ | $A_2$ | ... | $B_n$ | $A_n$ |

| d     | $A_1$ | $B_1$ | $A_2$ | $B_2$ | ... | $A_n$ | $B_n$ |
| ----- | ----- | ----- | ----- | ----- | --- | ----- | ----- |
| $k_0$ | $a_1$ | $b_1$ | $a_2$ | $b_2$ | ... | $a_n$ | $b_n$ |
| $k_1$ | $b_1$ | $a_1$ | $b_2$ | $a_2$ | ... | $b_n$ | $a_n$ |

Dann gelten Dechiffrierbedingung und Surjektivität, $(X,K,Y,e,d)$ ist also ein Kryptosystem (wenn auch auf den ersten Blick ein nicht sehr intelligentes).

Man kann Kryptosysteme auch durch eine mathematische Beschreibung angeben. Im Wesentlichen genau dasselbe Kryptosystem wie in Beispiel 1.2 ist das folgende: $X=Y=\{0,1\}^l,n=2^l$. Die Elemente dieser Mengen fassen wir als Binärdarstellungen von Zahlen in $\{0, 1,..., 2^l-1\}$ auf. $A_1,...,A_n$ sind die geraden Zahlen $0,2,...,2^l-2,B_1,...,B_n$ die ungeraden Zahlen $1,3,...,2^l- 1$ in dieser Menge.
Genauso sind $a_1,...,a_n$ und $b_1,...,b_n$ definiert. Die Schlüssel sind $k_0=0$ und $k_1=1$, und $e(x,k_0)=d(x,k_0)=x$ und $e(x,k_1)=d(x,k_1)$ ist das Binärwort, das man erhält, wenn man in $x$ das letzte Bit kippt: $e(x,k) =d(x,k) =x\oplus_l k$. 
(Dabei steht $k$ für die Binärdarstellung von $k$ mit l Bits und $\oplus_l$ steht für das bitweise XOR.)

**Beispiel 1.3** $X=\{a,b\},K=\{k_0,k_1,k_2\},Y=\{A,B,C\}$.Die Funktion $e$ ist gegeben durch die erste, die Funktion $d$ durch die zweite der folgenden Tabellen. Dann ist $(X,K,Y,e,d)$ Kryptosystem, denn die Dechiffrierbedingung und die Surjektivität sind erfüllt.

| e     | a   | b   |
| ----- | --- | --- |
| $k_0$ | A   | B   |
| $k_1$ | B   | A   |
| $k_2$ | A   | C   |

| d     | A   | B   | C   |
| ----- | --- | --- | --- |
| $k_0$ | a   | b   | a   |
| $k_1$ | b   | a   | a   |
| $k_2$ | a   | a   | b   |

**Beispiel 1.4** $X=\{a,b\},K=\{k_0,k_1,k_2\},Y=\{A,B,C\}$. Die Funktion $e$ ist durch die folgende Tabelle gegeben:

| e     | a   | b   |
| ----- | --- | --- |
| $k_0$ | A   | B   |
| $k_1$ | B   | B   |
| $k_2$ | A   | C   |

Wegen $e(a,k_1)=e(b,k_1)$ existiert keine Funktion $d$, so dass $(X,K,Y,e,d)$ ein Kryptosystem ist, die Dechiffrierbedingung kann also nicht erfüllt werden.

Merke: Jede Chiffre $e(.,k)$ eines Kryptosystems muss injektiv sein. (Sonst kann es keine Entschlüsselungsfunktion $d$ geben. Anschaulich: Die Einträge in jeder Zeile der Tabelle für $e$ müssen verschieden sein.)

**Beispiel 1.5** $X=K=Y=\{0\},e(0,0)=d(0,0)=0$ (auch $X=\{x\},K=\{k\},Y=\{y\}$). Dies ist das ,,triviale'' minimale Kryptosystem. Dechiffrierbedingung und Surjektivität gelten offensichtlich.

**Beispiel 1.6** Sei $\oplus:\{0,1\}\times\{0,1\}\rightarrwo\{0,1\}$ die Funktion $(b,c)\rightarrow b+c-2bc$ (=b XOR c).
Für $l>0$ sei $\oplus^l:\{0,1\}^l\times\{0,1\}^l\rightarroq\{0,1\}^l$ die komponentenweise Anwendung von $\oplus=\oplus_l$:

$(b_1,b_2,...,b_l)\oplus_l(c_1,c_2,...,c_l) = (b_1\oplus c_1,b_2\oplus c_2,...,b_l\oplus c_l)$

Sei $l>0$. Das Vernam-Kryptosystem oder one-time pad der Länge $l$ ist das Kryptosystem $(\{0,1\}^l,\{0,1\}^l,\{0,1\}^l,\oplus_l,\oplus_l)$. Benannt nach Gilbert S. Vernam (1890, 1960), der im Jahr 1918 dieses System für fünf Bits in der Sprache einer Relais-Schaltung beschrieben und zum US-Patent angemeldet hat. Siehe [http://www.cryptomuseum.com/crypto/files/us1310719.pdf](http://www.cryptomuseum.com/crypto/files/us1310719.pdf)

In diesem Fall ist es für nicht ganz kleine l offensichtlich unbequem, wenn nicht ganz unmöglich,die Ver-und Entschlüsselungsfunktion durch Tabellen anzugeben. Man benutzt hier und auch üblicherweise mathematische Beschreibungen.

Beispiel: $x=1011001,k=1101010$. Dann ist $y=e(x,k)=1011001\oplus_7 1101010 = 0110011$. Zur Kontrolle: $d(y,k) = 0110011\oplus_7 1101010 = 1011001 =x$.

Wir kontrollieren dass das Vernam-System tatsächlich ein Kryptosystem ist.
1. Für $x\in X$ und $k\in K$ gelten $d(e(x,k),k)=(x\oplus_l k)\oplus_l k=x\oplus_l(k\oplus_l k) =x\oplus_l 0^l=x$, d.h. die Dechiffrierbedingung ist erfüllt.
2. Für $y\in Y$ gilt $e(y,0^l) =y$ und $y\in X,0^l\in K$. Also gilt Surjektivität.

Wann soll ein Kryptosystemals sicher betrachtet werden?

Erste Idee: Wenn Eva den Chiffretext $e(x,k)$ abhört und den Schlüssel $k$ nicht kennt, so soll sie nicht in der Lage sein, x zu berechnen.

**Beispiel 1.2** (Fortsetzung) Wenn Eva den Chiffretext $A_1$ abhört, so weiß sie, dass der Klartext $a_1$ oder $b_1$ ist; sie kann aber nicht sagen, welcher von beiden es ist. Allerdings hat sie (signifikante) nicht triviale Information gewonnen, nämlich dass $a_2,b_2,...,a_n,b_n$ nicht in Frage kommen.

Die Anforderung, dass $x$ aus $y$ nicht eindeutig bestimmt werden kann, führt also zu keinem befriedigenden Sicherheitsbegriff.

Zweite Idee: Wenn Eva den Chiffretext $y$ abhört und den Schlüssel $k$ nicht kennt, so kann sie keinen Klartext ausschließen. Dies führt zu der folgenden Definition.

**Definition 1.7** Ein Kryptosystem $S=(X,K,Y,e,d)$ heißt possibilistisch sicher,wenn $\forall y\in Y\forall x\in X\exists k\in K:e(x,k)=y$.

Bemerkung
1. Sei $S=(X,K,Y,e,d)$ Kryptosystem. Dann sind äquivalent:
    - $S$ ist possibilistisch sicher.
    - $\forall x\in X:e(x,K)=\{e(x,k)|k\in K\}=Y$.
2. Für $n\geq 2$ ist das Kryptosystem aus Beispiel 1.2 nicht possibilistisch sicher,denn $A_1$ kann nicht Chiffretext zu $a_2$ sein.
3. Das Kryptosystem aus Beispiel 1.3 ist nicht possibilistisch sicher, denn $C$ kann nicht Chiffretext zu $0$ sein.
4. Das Vernam-Kryptosystem der Länge $l$ ist possibilistisch sicher: Seien $x\in X$ und $y\in Y$. Setze $k=x\oplus_l y$.Dann gilt $e(x,k)=x\oplus_l(x\oplus_l y)=(x\oplus_l x)\oplus_l y= 0^l\oplus_l y=y$.

In der Einführung wurde die Verschiebechiffre betrachtet, bei  der Buchstaben des alten lateinischen Alphabets auf  Chiffrebuchstaben abgebildet wurden, indem man das Bild von $A$ angab und jeder andere Buchstabe um dieselbe Distanz verschoben wurde. Auch die allgemeineren Substitutionschiffren wurden erwähnt, bei der man für jeden Buchstaben $x$ einen beliebigen Bildbuchstaben $\pi(x)$ angibt, auf injektive Weise. Beispiel für eine Substitutionschiffre:

| x        | A   | B   | C   | D   | E   | F   | G   | H   | I   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | V   | X   |
| -------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $\pi(x)$ | F   | Q   | M   | P   | K   | V   | T   | A   | E   | L   | H   | N   | I   | G   | D   | S   | B   | X   | O   | R   | C   |

Man überlege: Es gibt $21!(= 51090942171709440000)$ viele solche Chiffren. Wir können für ganz beliebige Mengen $X$ die Menge aller Substitutionschiffren auf $X$ betrachten.

**Definition 1.9** Für eine endliche, nichtleere Menge $X$ sei $K=P_X$ die Menge der Permutationen (Eine Permutation auf $X$ ist eine bijektive Funktion $\pi:X\rightarrow X$) auf $X$.Das Substitutionskryptosystem auf $X$ ist das Tupel $(X,PX,X,e,d)$ 
mit $$e(x,\pi)=\pi(x)$ und $d(y,\pi)=\pi^{-1} (y)$$. 
Wenn $\pi:X\rightarrow X$ eine Permutation ist, dann ist $\pi^{-1}:X\rightarrow X$ die Permutation mit $\pi^{-1}(\pi(x))=\pi(\pi^{-1}(x)) =x$ für alle $x\in X$.

Man sieht leicht, dass dies tatsächlich ein Kryptosystem ist (Dechiffrierbedingung und Surjektivität).

Proposition 1.10 Ist $X$ eine endliche und nichtleere Menge, so ist das Substitutions-kryptosystem auf X possibilistisch sicher.

Beweis: Seien $y\in Y =X$ und $x\in X$.Definiere $\pi:X\rightarrow X$ wie folgt:

$$\pi(z) =\begin{cases} y\quad\text{ falls} z=x\\ x\quad\text{ falls} z=y\\ z\quad\text{ falls} z\not\in\{x,y\} \end{cases}$$

Dann ist $\pi\in P_X$ mit $e(x,\pi)=\pi(x)=y$.

Beobachtung: $K$ ist in diesem Fall sehr groß, es gibt $|X|!$ Schlüssel. Im Fall des Vernam-Kryptosystems ist $|X|=|Y|=|K|$.

Proposition 1.11 Ist $S=(X,K,Y,e,d)$ ein possibilistisch sicheres Kryptosystem, so gilt $|X|\leq|Y|\leq|K|$.

Beweis: Wähle $k\in K$ beliebig. Da $S$ ein Kryptosystem ist,erfüllt es die Dechiffrierbedingung. Also ist die Chiffre $e(.,k):X\rightarrow Y$ injektiv, d.h. es gilt $|X|\leq |Y|$.

Sei nun $x\in X$ beliebig. Da $S$ possibilistisch sicher ist, gibt es für jedes $y\in Y$ ein $k\in K$ mit $e(x,k) =y$. Also ist die Abbildung $K\ni k\rightarrow e(x,k)\in Y$ surjektiv, und es folgt $|Y|\leq |K|$.

Folgerung: Bei possibilistischer Sicherheit und Klartexten und Schlüsseln, die Zeichenreihen über einem Alphabet sind, müssen Schlüssel mindestens so lang sein wieder zu übermittelnde Text. Wenn man etwa den Inhalt einer Festplatte verschlüsseln will, benötigt man eine weitere Festplatte für den Schlüssel. In solchen Fällen extrem langer Klartexte wird possibilistische Sicherheit unrealistisch. Possibilistisch sichere Systeme kommen daher nur als Bausteine in größeren Systemen vor.

**Beispiel 1.12** Sei $X=\{a,b\},K=\{0,1,2\},Y=\{A,B\}$ und die Verschlüsselungsfunktion sei durch
| e   | a   | b   |
| --- | --- | --- |
| 0   | A   | B   |
| 1   | A   | B   |
| 2   | B   | A   |

gegeben. Dann ist $S=(X,K,Y,e,d)$ ein possibilistisch sicheres Kryptosystem. Fängt Eva den Chiffretext $e(x,k) =A$ ab, so nimmt sie an, dass $x=a$ ,,wahrscheinlicher'' ist als $x=b$. 
Das ist zum Beispiel dann sinnvoll, wenn die Schlüssel $0,1,2$ dieselbe Wahrscheinlichkeit haben.
(Das Kerckhoffs-Prinzip würde sagen, dass Eva auch die verwendete Wahrscheinlichkeitsverteilung auf $K$ kennt.)

Um formal auszudrücken, warum dieses Kryptosystem nicht ,,sicher'' ist, wenn Schlüssel $0,1$ und $2$ gleichwahrscheinlich sind, beziehungsweise um einen passenden Sicherheitsbegriff überhaupt zu formulieren, benötigen wir etwas Wahrscheinlichkeitsrechnung.

## Wiederholung: Elementare Wahrscheinlichkeitsrechnung
Die in dieser Vorlesung benötigten Konzepte aus der Wahrscheinlichkeitsrechnung wurden in den Veranstaltungen ,,Grundlagen und Diskrete Strukturen'' und ,,Stochastik für Informatiker'' im Prinzip behandelt.Wir erinnern hier kurz an die für unsere Zwecke wichtigen Konzepte und legen Notation fest.

Beispiel: Ein Wahrscheinlichkeitsraum, mit dem man das Zufallsexperiment ,,Einmaliges Werfen eines fairen Würfels'' modellieren kann, ist $\Omega=\{ 1 , 2 , 3 , 4 , 5 , 6\}$ mit der Idee, dass jede  ,,Augenzahl'' $a\in\Omega$ Wahrscheinlichkeit $\frac{1}{6}$ hat. Die Wahrscheinlichkeit, $5$ oder $6$ zu würfeln, schreibt man dann als $Pr(\{5,6\})=\frac{1}{3}$, die Wahrscheinlichkeit für eine gerade Augenzahl als $Pr(\{2,4,6\})=\frac{1}{2}$. Allgemein gilt jede Menge $A\subseteq\Omega$ als ,,Ereignis''  mit Wahrscheinlichkeit $Pr(A) =|A|/|\Omega|$.

Wir fassen unsere Grundbegriffe etwas allgemeiner insofern, als wir auch verschiedene Wahrscheinlichkeiten für Elementarereignisse $a\in\Omega$ zulassen und es erlaubt ist,dass $\Omega$ abzählbar unendlich ist. Wir beschränken uns aber auf den Fall endlicher oder abzählbarer Wahrscheinlichkeitsräume, sogenannter diskreter W-Räume. 

**Definition**: Ein (diskreter) Wahrscheinlichkeitsraum ist ein Paar $(\Omega,Pr)$, wobei
- $\Omega$ eine nichtleere endliche oder abzählbar unendliche Menge und
- $Pr:P(\Omega)\rightarrow[0,1]$ eine Abbildung ($P(\Omega)=\{A|A\subseteq\Omega\}$ ist die Potenzmenge)

ist, sodass Folgendes gilt:
1. $Pr(\Omega) = 1$
2. für alle $A\subseteq\Omega$ gilt $Pr(A)=1-Pr(A)$, für $A=\Omega\backslash A$
3. für alle $A_1,A_2,...\in P(\Omega)$ gilt, falls die Mengen $A_i$ paarweise disjunkt sind: $Pr(\bigcup A_i)=\sum_{i\geq i}^{\infty} Pr(A_i)$ ( ,,$\sigma$-Additivität'' )

Man nennt
- die Elemente von $\Omega$ Ergebnisse oder Elementarereignisse,
- die Elemente von $P(\Omega)$ (also die Teilmengen von $\Omega$) Ereignisse und
- $Pr$ die Wahrscheinlichkeitsverteilung

des Wahrscheinlichkeitsraums $(\Omega,Pr)$. Für $A\in P(\Omega)$ heißt $Pr(A)$ die Wahrscheinlichkeit von $A$.

Bemerkung 1.13 $Pr(A) =\sum_{a\in A} Pr(\{a\})$ , d.h., die Wahrscheinlichkeitsverteilung $Pr$ ist durch die Wahrscheinlichkeitsfunktion $\Omega\rightarrow[0,1],a \rightarrow p_a= Pr(\{a\})$, eindeutig gegeben.

Wir schreiben auch für diese Funktion $Pr$ und damit $Pr(a)$ anstelle von $Pr(\{a\})$. Es gilt dann: $Pr(A)=\sum_{a\in A} Pr(a)$, für jedes Ereignis A, und insbesondere $\sum_{a\in\Omega}Pr(a) = 1$.

Sei nun $\Omega$ sogar endlich. Dann ist die uniforme Verteilung (oder Gleichverteilung) die  Wahrscheinlichkeitsverteilung $A\rightarrow\frac{|A|}{|\Omega$|}$, für Ereignisse $A\in P(\Omega)$, mit der Wahrscheinlichkeitsfunktion $a\rightarrow \frac{1}{|\Omega|}$, für $a\in\Omega$.

Lemma 1.14 Sei $(\Omega,Pr)$ ein Wahrscheinlichkeitsraum und seien $A,B\subseteq\Omega$ Ereignisse. Dann gilt $Pr(A\B)\geq Pr(A)-Pr(B)$.

Beweis: Für Ereignisse $C\subseteq D$ gilt stets $Pr(C)=\sum_{a\in C} Pr(a)\leq \sum_{a\in D} Pr(a) = Pr(D)$.
Daher gilt $Pr(A\B) + Pr(B) = Pr((A\B)\cup B) = Pr(A\cup B)\geq Pr(A)$.

Sei $(\Omega,Pr)$ Wahrscheinlichkeitsraum, B Ereignis mit $Pr(B)> 0$. Definiere $Pr_B:P(\Omega)\rightarrow[0,1],A \rightarrow\frac{Pr(A\cap B)}{Pr(B)}$.
Dann ist $(\Omega,Pr_B)$ selbst ein Wahrscheinlichkeitsraum, wie man leicht nachrechnet. Intuitiv ist $Pr_B(A)$ die Wahrscheinlichkeit für das Eintreten von $A$, wenn schon bekannt ist, dass $B$ eingetreten ist. Daher nennt man $Pr_B$ die bedingte Wahrscheinlichkeit bzgl. B und schreibt für $Pr_B(A)$ auch $Pr(A|B)$. Aus der Definition folgt die Grundformel $Pr(A\cap B) = Pr(A|B)*Pr(B)$.

Achtung: die bedingte Wahrscheinlichkeit $Pr(A|B)$ ist nur definiert, wenn $Pr(B)> 0$ gilt.

Lemma 1.15 Sei $(\Omega,Pr)$ ein Wahrscheinlichkeitsraum.
1. (,,Formel von der totalen Wahrscheinlichkeit'') Seien $B_1,...,B_t$ disjunkte Ereignisse mit $Pr(B_1\cup...\cup B_t)=1$. Dann gilt $Pr(A)=\sum_{1\leq s\leq t} Pr(A|B_s)Pr(B_s)$.
2. Seien $A,B,C$ Ereignisse mit $Pr(B\cap C),Pr(C\B)>0$. Dann gilt $Pr(A|C)=Pr(A\cap B|C) + Pr(A\B|C)= Pr(A|B\cap C)Pr(B|C) + Pr(A|C\B)Pr(\bar{B}|C)$.

Beispiel: In dem Würfel-Wahrscheinlichkeitsraum mit $\Omega=\{1,...,6\}$ und der uniformen Verteilung betrachten wir die Ereignisse $A=\{3,6\}$ (durch 3 teilbare Augenzahl) und $B=\{2,4,6\}$ (gerade Augenzahl). Wir haben: $Pr(A\cap B) = Pr(\{6\})=\frac{1}{6}=\frac{1}{3}*\frac{1}{2}=Pr(A)*Pr(B)$.

Damit sind die Ereignisse {Augenzahl ist gerade} und {Augenzahl ist durch 3 teilbar} (stochastisch) unabhängig im folgenden Sinn:

**Definition 1.16** Sei $(\Omega,Pr)$ ein Wahrscheinlichkeitsraum und seien $A,B$ Ereignisse. Dann heißen A und B unabhängig, wenn $Pr(A\cap B)=Pr(A)*Pr(B)$ gilt.

Bemerkung: Wenn $Pr(B)> 0$ gilt, dann sind $A$ und $B$ genau dann unabhängig, wenn $Pr(A) = \frac{Pr(A\cap B)}{Pr(B)})= Pr(A|B)$ gilt. Das bedeutet, dass sich durch die Information, dass B eingetreten ist, nichts an der Wahrscheinlichkeit für $A$ ändert. (Im Beispiel: Wenn wir wissen, dass die Augenzahl $b$  eim Würfeln gerade ist, dann ist die Wahrscheinlichkeit für eine Augenzahl, die durch 3 teilbar ist, genau, genau dieselbe wie im gesamten Wahrscheinlichkeitsraum.)

**Zufallsvariable bzw. Zufallsgrößen** Zufallsvariable ordnen den Ergebnissen eines Experiments (d.h. eines Wahrscheinlichkeitsraums) ,,Werte''  aus einer Menge R zu. (Diese Werte können Zahlen oder andere ,,Eigenschaften'' sein.)

**Definition 1.17** Sei $(\Omega,Pr)$ ein Wahrscheinlichkeitsraum und R eine endliche oder abzählbare Menge. Eine Zufallsvariable ist eine Abbildung $X:\Omega\rightarrow R$.
Zufallsvariablen mit $R\subseteq R$ heißen reelle Zufallsvariable.

Beispiel 1.18 Zu $\Omega=\{1,2,...,N\}^q$ (q,$N\geq 1$) betrachten wir den Wahrscheinlichkeitsraum $(\Omega,Pr)$ mit der Gleichverteilung $Pr$. Beispiele für Zufallsvariablen sind:
- $R=\mathbb{N}$ und $X:\Omega\rightarrow R,(a_1,...,a_q)\rightarrow a_5$ (eine Projektion, definiert für $q\geq 5$)
- $R=\{-1,0,1\}$ und $Y_{ij}((a_1,...,a_q))=\begin{cases} -1\quad\text{falls } a_i< a_j\\ 0\quad\text{falls} a_i=a_j, \text{für } 1\leq i < j\leq n \\ 1\quad\text{falls } a_i> a_j\end{cases}$
- $R=\mathbb{N}$ und $Z:\Omega\rightarrow R,(a_1 ,...,a_q)\rightarrow\sum_{1\leq i\leq q} a_i$

Sei $X:\Omega\rightarrow R$ eine Zufallsvariable. Für $S\subseteq R$ setze $Pr^X(S):= Pr(X^{-1}(S))=Pr(\{a\in\Omega|X(a)\in S\})$. Dann ist $(R,Pr^X)$ ein Wahrscheinlichkeitsraum. Dieser heißt der von $X$ auf $R$ induzierte Wahrscheinlichkeitsraum. $Pr^X$ heißt auch die Verteilung von $X$.

Schreibweisen: Für $S\subseteq R$ ist $X^{-1}(S)=\{a\in\Omega|X(a)\in S\}$ ein Ereignis, für das wir ,,$X\in S$'' oder ,,$\{X\in S\}$'' schreiben. Für $X^{-1}(r)=\{a\in\Omega|X(a) =r\}$ schreiben wir analog ,,$X=r$'' oder ,,$\{X=r\}$''. Insbesondere schreiben wir: $Pr(X=r)=PX(r)=Pr(X^{-1}(r))$ und $Pr(X\in S)=P^X(S)=Pr(X^{-1}(S))$.

Sind $X_i:\Omega\rightarrow R_i$ Zufallsvariable und $S_i\subseteq R_i$, für $i=1,2$, dann schreiben wir ,,$\{X_1\in S_1,X_2\in S_2\}$'' für das Ereignis $X^{-1}(S_1)\cap X^{-1}(S_2)$. Die beiden Zufallsvariablen $X_1$ und $X_2$ heißen unabhängig, wenn $Pr(X_1\in S_1,X_2\in S_2)=Pr(X_1\in S_1)*Pr(X_2\in S_2)$ gilt, für alle $S_i\subseteq R_i,i=1,2$. Dies ist gleichbedeutend mit der Forderung $Pr(X_1=r_1,X_2=r_2)=Pr(X_1=r_1)*Pr(X_2=r_2)$ für alle $r_i\in R_i, i=1,2$.


## Informationstheoretische Sicherheit
Man erinnere sich an Beispiel 1.12. Eine naheliegende Annahme ist, dass jeder Klartextbuchstabe mit Wahrscheinlichkeit $\frac{1}{2}$ und jeder Schlüssel mit Wahrscheinlichkeit $\frac{1}{3}$ auftritt, und zwar unabhängig voneinander. Dann ist $Pr$(Klartext x ist a $\wedge$ Chiffretext y ist A)$=\frac{1}{3}$, Pr(Chiffretext y ist A)$=\frac{1}{2}$, also Pr(Klartext x ist a | Chiffretext y ist A)$=\frac{2}{3}\not=\frac{1}{2}=$Pr(Klartext x ist a). Wenn Eva also A beobachtet,ändert sich ihre Ansicht über die Verteilung auf den Klartextbuchstaben.

Für das Konzept der informationstheoretischen Sicherheit nehmen wir an, dass Klartexte mit bestimmten Wahrscheinlichkeiten auftreten. Was diese Wahrscheinlichkeiten sind, kann der Anwender normalerweise nicht kontrollieren. Die konsequente Anwendung des Kerckhoffs-Prinzips besagt aber, dass man annehmen muss, dass Eva die relevante Wahrscheinlichkeitsverteilung auf X kennt. (Zum Beispiel würde sie wissen, dass $Pr^X(x_0)=\frac{1}{2}$ ist, für ein bestimmtes $x_0\in X$.) Nun betrachten wir ein Kryptosystem $S=(X,K,Y,e,d). Wir nehmen an, dass Alice und Bob ihren gemeinsamen Schlüssel k durch ein Zufallsexperiment wählen. Hierzu gehört ein zweiter Wahrscheinlichkeitsraum $(K,Pr_K)$. Es ist sinnvoll anzunehmen, dass $Pr_X$ und $Pr_K$ nichts miteinander zu tun haben. Es wird verschlüsselt und Chiffretext y wird gesendet. Dieser wird von Eva beobachtet. Wenn sich dadurch die Meinung von Eva über die Wahrscheinlichkeiten der verschiedenen Klartexte von der ursprünglichen Verteilung unterscheidet (etwa jetzt: ,,mit 90%iger Wahrscheinlichkeit ist es Klartext $x_0$''), hat Eva aus der Beobachtung von y eine gewisse Information erhalten.

Wir geben nun ein mathematisches Modell an, innerhalb dessen man über Begriffe wie ,,Eva erhält Information'' sprechen und argumentieren kann. Dazu konstruieren wir einen W-Raum mit $\Omega=X\times K$. In das Modell bauen wir die Vorstellung ein, dass $x\in X$ und $k\in K$ nach den Verteilungen $Pr_X$ und $Pr_K$ zufällig und unabhängig gewählt werden.

Man beachte, dass die Verteilung $Pr_K$ ,,Teil des Kryptosystems'' ist, also der Kontrolle von Alice und Bob unterliegt, während $Pr_X$ ,,Teil der Anwendung'' oder ,,Teil der Realität'' ist, also von den Teilnehmern normalerweise nicht beeinflusst werden kann. Die Verteilung $Pr_X$ braucht beim Entwurf des Kryptosystems nicht einmal bekannt zu sein. (Alice und Bob sollten ihr Kryptosystem ohne Kenntnis von $Pr_X$ planen können. Die Annahme, dass Eva $Pr_X$ kennt, ist eine worst-case-Annahme, sie muss in der Realität nicht unbedingt erfüllt sein.)

**Definition 1.19** Ein Kryptosystem mit Schlüsselverteilung (KSV) ist ein 6-Tupel $V=(X,K,Y,e,d,Pr_K)$, wobei
- $S=(X,K,Y,e,d)$ ein Kryptosystem (das zugrundeliegende Kryptosystem) ist und
- $Pr_K:K\rightarrow (0,1]$ eine Wahrscheinlichkeitsfunktion (die Schlüsselverteilung) ist.
- Für $V=(X,K,Y,e,d,Pr_K)$ schreiben wir auch $S[Pr_K]$.
- Achtung: Die Definition verlangt $Pr_K(k)\in (0,1]$, also $Pr_K(k)> 0$ für alle $k\in K$. (Hat man Schlüssel mit Wahrscheinlichkeit 0, kann man sie aus K einfach weg lassen.)

Sei weiter $Pr_X:X\rightarrow [0,1]$ eine Wahrscheinlichkeitsfunktion auf der Menge der Klartexte. Das heißt: $\sum_{x\in X}Pr_X(x)=1$. Diese Wahrscheinlichkeitsfunktion definiert natürlich eine W-Verteilung auf X, die wir wieder $Pr_X$ nennen. (Achtung: Es kann Klartextexte mit $Pr(x)=0$ geben. Solche Klartexte heißen passiv, die anderen, mit $Pr_X(x)>0$, aktiv.) Wir definieren die gemeinsame Wahrscheinlichkeitsfunktion $Pr:X\times K\rightarrow [0,1]$ durch $Pr((x,k)):=Pr_X(x)*Pr_K(k)$.
Dies definiert einen Wahrscheinlichkeitsraum auf $X\times K$, für den $Pr(X′\times K′)=Pr_X(X′)*Pr_K(K′)$, für alle $X′\subseteq X,K′\subseteq K$ gilt. Durch diese Definition wird die Annahme modelliert, dass der Schlüssel k unabhängig vom Klartext durch ein von $Pr_K$ gesteuertes Zufallsexperiment gewählt wird.

**Beispiel 1.20** Sei $X=\{a,b,c\},K=\{0,1,2,3\},Y=\{A,B,C\}$ und die Verschlüsselungsfunktion sei durch die folgende Tabelle gegeben:
| e                 | a(0,4) | b(0) | c(0,6) |
| ----------------- | ------ | ---- | ------ |
| 0 ($\frac{1}{4}$) | A      | B    | C      |
| 1 ($\frac{1}{8}$) | B      | C    | A      |
| 2 ($\frac{1}{2}$) | C      | A    | B      |
| 3 ($\frac{1}{8}$) | C      | B    | A      |

Die Wahrscheinlichkeiten $Pr_X(x)$ sind beiden Klartexten, die Wahrscheinlichkeiten $Pr_K(k)$ beiden Schlüsseln in Klammern notiert. Klartexte a und c sind aktiv, Klartext b ist passiv. Die Wahrscheinlichkeit für einen Punkt $(x,k)\in X\times K$ erhält man durch Multiplikation: $Pr((c,2)) = 0,6 *\frac{1}{2}=0,3$ und $Pr((b,k))=0*Pr_K(k)=0$ für alle $k\in K$.

Der Chiffretext y ist dann eine Zufallsvariable auf diesem Wahrscheinlichkeitsraum: $X_3((x,k)):=e(x,k)$.
Auch die beiden Komponenten $x$ und $k$ werden als Zufallsvariable betrachtet (Projektionen):
- $X_1:X\times K\rightarrow X,(x,k) \rightarrow x$
- $X_2:X\times K\rightarrow K,(x,k) \rightarrow k$

Wir beobachten einige einfache Zusammenhänge, für $x_0\in X,k_0\in K,y_0\in Y$:
- $Pr(x_0):=Pr(X_1=x_0)=Pr(\{x_0\}\times K) = Pr_X(x_0)*Pr_K(K) = Pr_X(x_0)$.
- $Pr(k_0):=Pr(X_2=k_0)=Pr(X\times\{k_0\})=Pr_X(X)*Pr_K(k_0)=Pr_K(k_0)$

(Man erhält also die ursprünglichen Wahrscheinlichkeiten für Klartexte und Schlüssel zurück. Dies ist eine einfache Grundeigenschaft von Produkträumen.)

$$Pr(y_0):=Pr(X_3=y_0)=Pr(\{(x,k)|x\in X,k\in K,e(x,k) =y_0\}) =\sum_{x\in X,k\in K,e(x,k)=y_0} Pr((x,k)) =\sum_{x\in X,k\in K,e(x,k)=y_0} Pr_X(x)*Pr_K(k)$$

(In Beispiel 1.20 gilt $Pr(A)=\frac{1}{4}*0,4+ \frac{1}{8}*0,6 +\frac{1}{2}*0 +\frac{1}{8}* 0,6=0,25$ und $Pr(B) =\frac{1}{4}*0 +\frac{1}{8}*0,4 +\frac{1}{2}*0,6 +\frac{1}{8}*0 = 0,35$.)

$$Pr(x_0,y_0):=Pr(X_1=x_0,X_3=y_0)=Pr(\{x_0\}\times\{k\in K|e(x_0,k)=y_0\})= Pr_X(x_0)*\sum_{k\in K:e(x_0,k)=y_0} Pr_K(k)$$

(In Beispiel 1.20 gilt $Pr(c,A)=0,6*(\frac{1}{8}+\frac{1}{8})=0,15$ und $Pr(a,C)=0,6*(\frac{1}{2}+\frac{1}{8})= 0,375$.)

$Pr(x_0|y_0):=Pr(X_1=x_0|X_3=y_0)= \frac{Pr(x_0,y_0)}{Pr(y_0)}= Pr_X(x_0)*\frac{\sum_{k\in K:e(x_0,k)=y_0} Pr_K(k)}{\sum_{x\in X,k\in K:e(x,k)=y_0} Pr_X(x)*Pr_K(k)}$.

(In Beispiel 1.20 gilt $Pr(c|A)=0,15/0,25=0,6$.) Die letzte Formel ist nur für $y_0$ mit $Pr(y_0)>0$ definiert.

**Definition 1.21** Sei $V=(X,K,Y,e,d,Pr_K)$ ein Kryptosystem mit Schlüsselverteilung.
1. Sei $Pr_X$ eine Wahrscheinlichkeitsfunktion auf den Klartexten. Dann heißt $V$ informationstheoretisch sicher bezüglich $Pr_X$, wenn für alle $x\in X,y\in Y$ mit $Pr(y)>0$ gilt: $Pr(x) = Pr(x|y)$.
2. Das KSV $V$ heißt informationstheoretisch sicher, wenn es bezüglich jeder beliebigen Klartextverteilung $Pr_X$ informationstheoretisch sicher ist.

Bemerkungen: Hinter Definition 1. steckt die folgende Vorstellung: Eva kennt (im schlimmsten Fall) die Wahrscheinlichkeitsfunktion $Pr_X$. Das System gilt als sicher, wenn sich durch Abfangen eines Chiffretextes y aus Evas Sicht die Wahrscheinlichkeiten der einzelnen Klartexte x nicht ändern. Die Bedingung $Pr(y)>0$ in 1. ist nötig, damit $Pr(x|y)$ definiert ist. Sie bedeutet aber keine Einschränkung, da Chiffretexte $y$ mit $Pr(y)=0$ nie vorkommen, also auch nicht abgefangen werden können. Das Konzept in 2. ist relevant, weil man beim Entwurf eines Kryptosystems meistens die Klartextverteilung nicht oder nicht genau kennt.

Man beachte, dass in der Definition der informationstheoretischen Sicherheit die Fähigkeiten von Eva überhaupt nicht eingeschränkt werden. Auf welche Weise sie eventuell ermittelt, dass sich Wahrscheinlichkeiten geändert haben, wird gar nicht diskutiert. (Eva könnte zum Beispiel für jedes $y\in Y$ eine Tabelle haben, in der die Wahrscheinlichkeiten $Pr(x|y)$ für alle $x\in X$ aufgelistet sind. Oder sie fängt beim Vorliegen von $y$ an, eine solche Tabelle zu berechnen. Beides ist natürlich für nicht ganz kleine X und Y völlig unrealistisch.)

**Beispiel 1.22**
| e                  | a($\frac{1}{4}$) | b(\frac{3}{4}$ ) |
| ------------------ | ---------------- | ---------------- |
| $k_0(\frac{1}{3})$ | A                | B                |
| $k_1(\frac{2}{3})$ | B                | A                |

(Notation: In der Tabelle stehen neben den Namen von Klartexten und Schlüsseln in Klammern deren Wahrscheinlichkeiten.) Dieses Kryptosystem ist possibilistisch sicher. Es gilt ab er:
$Pr(a|A)=\frac{Pr(a,A)}{Pr(A)}=\frac{\frac{1}{3}*\frac{1}{4}}{\frac{1}{3}*\frac{1}{4}+\frac{2}{3}*\frac{3}{4}}=\frac{1}{7}$ und $Pr(a)=\frac{1}{4}$. 
Nach dem Abhören von A sieht also Eva den Klartext a als weniger wahrscheinlich an als vorher. Also ist dieses Kryptosystem mit Schlüsselverteilung bzgl. $Pr_X$ nicht informationstheoretisch sicher.

**Beispiel 1.23**
| e                  | a($\frac{1}{4}$) | b($\frac{3}{4}$) |
| ------------------ | ---------------- | ---------------- |
| $k_0(\frac{1}{2}$) | A                | B                |
| $k_1(\frac{1}{2}$) | B                | A                |

Dieses System ist bezüglich $Pr_X$ informationstheoretisch sicher. Zum Beispiel gilt $Pr(a|A) =\frac{Pr(a,A)}{Pr(A)}=\frac{\frac{1}{4}*\frac{1}{2}}{\frac{1}{4}*\frac{1}{2}+\frac{3}{4}*\frac{1}{2}}=\frac{\frac{1}{8}}{\frac{1}{2}}=\frac{1}{4}$ und $Pr(a)=\frac{1}{4}$. Die anderen drei verlangten Gleichheiten rechnet man analog nach.

**Satz 1.24** (Informationstheoretische Sicherheit des Vernam-Systems) Sei $l>0$ und $S=(X,K,Y,e,d)$ mit $X=K=Y=\{0,1\}^l$ und $e=d=\oplus_l$ das Vernam-System der Länge $l$. Sei weiter $Pr_K:K\rightarrow [0,1]$ die Gleichverteilung. Dann ist $V=S[Pr_K]$ informationstheoretisch sicher.

Beweis: Sei $Pr_X:X\rightarrow [0,1]$ eine beliebige Wahrscheinlichkeitsfunktion. Wir müssen zeigen, dass $V$ bezüglich $Pr_X$ informationstheoretisch sicher ist. Wir beginnen mit folgender Beobachtung: Zu $x\in X$ und $y\in Y$  existiert genau ein $k_{x,y}\in K$ mit $e(x,k_{x,y})=y$, nämlich $k_{x,y}=x\oplus_l y$. Damit gilt für jedes $y\in Y$: $Pr(y)=\sum_{x\in X,k\in K,e(x,k)=y} Pr(x)Pr(k) = \sum_{x\in X} Pr(x) Pr(kx,y)= 2^{-l}* \sum_{x\in X} Pr(x)=2^{-l}$.

(D.h.: Jeder Chiffretext y hat dieselbe Wahrscheinlichkeit $2^{-l}$, ganz gleich was $Pr_X$ ist.)
Sei nun $x\in X$ und $y\in Y$ beliebig gewählt. Dann gilt $Pr(x,y) = Pr(x)*\sum_{k\in K, e(x,k)=y} Pr(k) = Pr(x)*Pr(k_{x,y}) = Pr(x)* 2^{-l}= Pr(x)*Pr(y)$.

Damit folgt $Pr(x)=\frac{Pr(x,y)}{Pr(y)}= Pr(x|y)$, wie bei der informationstheoretischen Sicherheit verlangt.

Bemerkung 1.25
1. Der Beweis und damit das Vernamsystem kommt mit jeder beliebigen Klartextverteilung zurecht.
2. Im KSV V wird die Gleichverteilung $Pr_K$ auf den Schlüsseln benutzt.

Wir wollen nun überlegen, dass diese beiden Sachverhalte nicht zufällig sind.  Es wird sich herausstellen, dass informationstheoretische Sicherheit inbestimmten  Fällen (nämlich wenn y und K möglichst ,,sparsam'' gebaut sind) Gleichverteilung auf den Schlüsseln erzwingt, und dass die informationstheoretische Sicherheit eines KSV nichts mit den konkreten Wahrscheinlichkeiten der Klartextverteilung $Pr_X$ zu tun hat, sondern nur die Menge $\{x\in X|Pr_X(x)> 0\}$ der ''aktiven'' Klartexte relevant ist.

Lemma 1.26 Sei $V=(X,K,Y,e,d,Pr_K)$ ein KSV. Sei $V$ informationstheoretisch sicher bezüglich einer Klartextverteilung $Pr_X$ mit $Pr(x)>0$ für alle $x\in X$. Dann gilt:
1. $Pr(y)>0$ für alle $y\in Y$, und $S=(X,K,Y,e,d)$ ist possibilistisch sicher.
2. Gilt zusätzlich $|X|=|Y|=|K|$, so gilt $Pr_K(k)=\frac{1}{|K|}$ für alle $k\in K$.

Beweis: 
1. Sei $y\in Y$ beliebig. Nach Definition 1.1(2) gibt es $x_0\in X$ und $k_0\in K$ mit $e(x_0,k_0)=y$. Da $Pr_X(x_0)>0$ (nach Vor.) und $Pr_K(k_0)>0$ (nach Def 1.19),erhalten wir $Pr(y)\geq Pr_X(x_0)Pr_K(k_0)>0$. Sei nun zusätzlich auch $x\in X$ beliebig. Dann gilt: $\sum_{k\in K:e(x,k)=y} Pr(x)Pr(k)= Pr(x,y)= Pr(x|y)Pr(y)=^* Pr(x)Pr(y)> 0$. ((*) gilt, da V informationstheoretisch sicher bzgl. $Pr_X$ ist.) Also existiert $k\in K$ mit $e(x,k)=y$. Da $x$ und $y$ beliebig waren, ist S possibilistisch sicher.
2. Nun nehmen wir zusätzlich $|X|=|Y|=|K|$ an. Wir beobachten zuerst zwei Dinge:
    1. Für jedes $x\in X$ ist die Abbildung $K\ni k \rightarrow e(x,k)\in Y$  bijektiv. (Dass diese Abbildung surjektiv ist, ist eine Umformulierung der possibilistischen Sicherheit, die nach 1. gegeben ist. Aus Surjektivität folgt Bijektivität, wegen $|K|=|Y|$.)
    2. Für jedes $k\in K$ ist die Abbildung $X\ni x \rightarrow e(x,k)\in Y$ bijektiv. (Dass die Abbildung injektiv ist, folgt aus der Dechiffrierbedingung. Aus Injektivität folgt Bijektivität, wegen $|X|=|Y|$.)

Nun seien $k_1,k_2\in K$ beliebig. Unser Ziel ist zu zeigen, dass $Pr(k_1)=Pr(k_2)$ gilt. (Dann ist gezeigt,dass $Pr_K$ die uniforme Verteilung ist.) Wähle $x\in X$ beliebig und setze $y:=e(x,k_1)$. Beachte, dass es wegen 1. keinen Schlüssel $k\not=k_1$ mit $y=e(x,k)$ gibt. Wegen 2. gibt es ein $x′\in X$ mit $e(x′,k_2)=y$. Auch hier gibt es kein $k′\not=k_2$ mit $e(x′,k′)=y$. Es gilt also: $Pr(x)Pr(k_1)=\sum_{k\in K:e(x,k)=y} Pr(x)Pr(k) = Pr(x,y) = Pr(x|y)Pr(y) =^* Pr(x)Pr(y)$, und daher $Pr(k_1)=Pr(y)$, wegen $Pr(x)>0$. (* gilt, weil $V$ informationstheoretisch sicher ist.) Analog gilt $Pr(x′)Pr(k_2)=Pr(x′)Pr(y)$, und daher $Pr(k_2)=Pr(y)$. Es folgt $Pr(k_1)=Pr(k_2)$, wie gewünscht.
Teil 2. dieses Lemmas hat eine Umkehrung.

Lemma 1.27 Sei $V=(X,K,Y,e,d,Pr_K)$ KSV mit $|X|=|Y|=|K|$. Wenn $S=(X,K,Y,e,d)$ possibilistisch sicher ist und $Pr_K$ die Gleichverteilung ist, dann ist $V$ informationstheoretisch sicher.

Beweis: Es sei eine beliebige Klartextverteilung $Pr_X$ gegeben. Da S possibilistisch sicher ist und $|X|=|Y|=|K|$ gilt,existiert für jedes Paar $(x,y)\in X\times Y$ genau ein $k_{x,y}\in K$ mit $e(x,k_{x,y}) =y$ (vgl.Aussage 1. im Beweis des vorherigen Lemmas).
Damit gilt für jedes $y\in Y$:$Pr(y)=\sum_{x\in X,k\in K:e(x,k)=y} Pr(x)Pr(k) =\sum_{x\in X} Pr(x) Pr(k_{x,y})=\frac{1}{|K|}* \sum_{x\in X} Pr(x) = \frac{1}{|K|}$.
Wir haben benutzt, dass $Pr_K$ die uniforme Verteilung ist und dass $\sum_{x\in X} Pr(x) = 1$ gilt.
Seien nun $x\in X$ und $y\in Y$ beliebig. Wenn $Pr(x)=0$ ist, gilt auf jeden Fall $Pr(x|y)=0=Pr(x)$. Wir können also $Pr(x)> 0$ annehmen und rechnen: $Pr(x|y) =\frac{Pr(x,y)}{Pr(y)}=\frac{Pr(y|x)*Pr(x)}{Pr(y)}=\frac{Pr_K(k_{x,y})*Pr(x)}{Pr(y)}=^* \frac{\frac{1}{|K|}*Pr(x)}{\frac{1}{|K|}}=Pr(x)$.
(Für * benutzen wir die Annahme über $Pr_K$ und die Gleichheit $Pr(y)=\frac{1}{|K|}$ von oben.) Das heißt, dass V  für $Pr_X$ informationstheoretisch sicher ist.
Aus den beiden Lemmas erhalten wir den folgenden Satz, der die informationstheoretisch sicheren KSVs für den Fall $|X|=|Y|=|K|$ vollständig beschreibt.

Satz 1.28 Sei $V= (X,K,Y,e,d,Pr_K)$ ein KSV mit $|X|=|Y|=|K|$. Dann sind äquivalent:
1. $V$ ist informationstheoretisch sicher.
2. $(X,K,Y,e,d)$ ist possibilistisch sicher und $Pr_K(k)=\frac{1}{|K|}$ für alle $k\in K$.

Beweis:  ,,$(a)\Rightarrow (b)$'': Wenn V informationstheoretisch sicher ist, dann auch bezüglich einer Klartextverteilung $Pr_X$, in der alle Klartexte aktiv sind. Lemma 1.26 liefert 2. ,,$(b)\Rightarrow (a)$'': Lemma 1.27.

Der Satz besagt, dass man informationstheoretisch sichere Systeme mit $|X|=|Y|=|K|$ daran erkennt, dass in der Verschlüsselungstabelle (für e) in jeder Spalte alle Chiffretexte vorkommen (possibilistische Sicherheit) und dass die Schlüsselverteilung $Pr_K$ uniform ist. Auch in jeder Zeile kommen natürlich alle Chiffretexte vor: das liegt aber einfach an der Dechiffrierbedingung. 
Wir geben ein Beispiel für ein solches informationstheoretisch sicheres Kryptosystem mit $|X|=|Y|=|K|=6$ an. Die Klartextverteilung ist irrelevant. (Die Verschlüsselungsfunktion ist übrigens mit Hilfe der Multiplikationstabelle der multiplikativen Gruppe $\mathbb{Z}^*_7$ des Körpers $\mathbb{Z}_7$ konstruiert worden. Solche Tabellen haben die Eigenschaft, dass jeder mögliche Eintrag in jeder Zeile und in jeder Spalte genau einmal vorkommt.)

Beispiel 1.29 Wir betrachten $X=\{a,b,c,d,e,f\},K=\{k_0 ,...,k_5\},Y=\{A,...,F\}$.
| e                   | a   | b   | c   | d   | e   | f   |
| ------------------- | --- | --- | --- | --- | --- | --- |
| $k_0 (\frac{1}{6})$ | A   | B   | C   | D   | E   | F   |
| $k_1 (\frac{1}{6})$ | B   | D   | F   | A   | C   | E   |
| $k_2 (\frac{1}{6})$ | C   | F   | B   | E   | A   | D   |
| $k_3 (\frac{1}{6})$ | D   | A   | E   | B   | F   | C   |
| $k_4 (\frac{1}{6})$ | E   | C   | A   | F   | D   | B   |
| $k_5 (\frac{1}{6})$ | F   | E   | D   | C   | B   | A   |

Nun betrachten wir allgemeinere Situationen, und fragen auch nach informationstheoretischer Sicherheit für spezifische Klartextverteilungen $Pr_X$ und für Mengen $K$ und $Y$, die größer als $X$ sind. Die Bedingung ,,uniforme Verteilung auf den Schlüsseln'' verschwindet dann komplett! Wir erinnern uns: Klartexte $x$ mit $Pr_X(x)> 0$ heißen aktiv (bzgl. $Pr_X$), die anderen passiv. Es wird sich herausstellen, dass sich informationstheoretische Sicherheit für $Pr_X$ mit dem Verhalten von $e(x,k)$ auf den aktiven Klartexten entscheidet, wobei es auf die tatsächlichen Wahrscheinlichkeiten für die aktiven Klartexte nicht ankommt.

Technisch hilfreich sind die folgenden Größen, die nur von der Verschlüsselungsfunktion und der Schlüsselverteilung abhängen (nicht von irgendeiner Klartextverteilung): $P^x(y):=\sum_{k\in K, e(x,k)=y} Pr(k)$, für $x\in X,y\in Y$ (1.1). 
Man beobachtet sofort die folgenden Gleichungen, die aus der Unabhängigkeit der Verteilungen $Pr_X$ und $Pr_K$ folgen:
- Für alle $x\in X:Pr(x,y) = Pr(x)*P^x(y)$. (1.2)
- Wenn $Pr(x)> 0$:$Pr(y|x) = \frac{Pr(x,y)}{Pr(x)}=P^x(y)$. (1.3)

Umgekehrt wie bei der Definition der informationstheoretischen Sicherheit stellt man sich hier vor, dass ein Klartext x gegeben ist und man fragt nach der resultierenden Verteilung auf den Chiffretexten.
Das nächste Lemma besagt, dass man die Wahrscheinlichkeiten aktiver Klartexte beliebig ändern kann (auch auf 0, also sie weglassen), ohne dass eine bestehende informationstheoretische Sicherheit zerstört wird.

Lemma 1.30 Sei $V=(X,K,Y,e,d,Pr_K)$ KSV und seien $Pr_X$ und $Pr′_X$ Klartextverteilungen mit $Pr′_X(x)>0\Rightarrow Pr_X(x)>0$. Dann gilt: Ist $V$ informationstheoretisch sicher bzgl. $Pr_X$, so ist V informationstheoretisch sicher bzgl. $Pr′_X$.

Beweis: Sei $V$ informationstheoretisch sicher bzgl. $Pr_X$. Wir haben es jetzt mit zwei Wahrscheinlichkeitsräumen zu tun, einem zu $Pr_X$ und $Pr_K$ (bezeichnet mit $(X\times K,Pr)$) und einem zu $Pr′_X$ und $Pr_K$ (bezeichnet mit $(X\times K,Pr′)$).
Wir zeigen nacheinander vier Aussagen.
1. $Pr_X(x)> 0 \Rightarrow P^x(y) = Pr(y|x) = Pr(y)$ für alle $y\in Y$. (Die Verteilungen $Pr^X(*)=Pr(*|x)$ auf den Chiffretexten sind für alle (Pr-)aktiven Klartexte x gleich und sind auch gleich der globalen Verteilung auf den Chiffretexten.) Beweis hierzu: Sei $Pr(x)>0$. Dann gilt $P^x(y)=Pr(y|x)$, siehe (1.3). Wenn $Pr(y)=0$ gilt, folgt auch $Pr(y|x)=0$. Sei also $Pr(y)>0$. Dann gilt: $Pr(y|x) =\frac{Pr(x,y)}{Pr(x)}=\frac{Pr(x|y)Pr(y)}{Pr(x)}=^* \frac{Pr(x)Pr(y)}{Pr(x)}= Pr(y)$. (* gilt, weil V informationstheoretisch sicher bzgl. $Pr_X$ ist.)
2. $Pr′_X(x)> 0 \Rightarrow Pr′(y|x) = Pr(y)$ für alle $y\in Y$. Beweis hierzu: Aus $Pr′(x)>0$ folgt $Pr(x)>0$, nach Voraussetzung. Wir wenden (1.3) für $Pr′$ und für $Pr$ an und erhalten für alle $y\in Y$: $Pr′(y|x)=P^x(y)=Pr(y|x)=^a Pr(y)$.
3. $Pr′(y)=Pr(y)$ für alle $y\in Y$. Beweis hierzu: Mit Lemma 1.15(a) (Formel von der totalen Wahrscheinlichkeit): $Pr′(y)=\sum_{x\in X: Pr′(x)> 0} Pr′(y|x)Pr′(x)=^b \sum_{x\in X: Pr′(x)> 0} Pr(y)Pr′(x) = Pr(y)$.
4. $Pr′(x)=Pr′(x|y)$ für alle $x\in X,y\in Y$ mit $Pr′(y)>0$. (D.h.: V ist bzgl. $Pr′_X$ informationstheoretisch sicher.) Beweis hierzu: Wenn $Pr′(x)=0$ gilt, dann folgt $Pr′(x|y)=0=Pr′(x)$. Sei nun $Pr′(x)>0$. Dann: $Pr′(x|y)=\frac{Pr′(x,y)}{Pr′(y)}=\frac{Pr′(y|x)Pr′(x)}{Pr′(y)}=^{b,c} \frac{Pr(y)Pr′(x)}{Pr(y)} = Pr′(x)$.

Satz 1.31 Sei $V=(X,K,Y,e,d,Pr_K)$ KSV und sei $Pr_X$ eine Klartextverteilung. Dann sind äquivalent:
1. V ist informationstheoretisch sicher für $Pr_X$.
2. Für jedes $x\in X$ und jedes $y\in Y$ gilt: $Pr(x,y)=Pr(x)Pr(y)$ (das Eintreten von x und das Eintreten von y sind unabhängig).
3. Für alle $x\in X$ mit $Pr(x)>0$ und alle $y\in Y$ gilt $Pr(y)=Pr(y|x)$ (andere Formulierung der Unabhängigkeit).
4. Für alle $x,x′\in X$ mit $Pr(x),Pr(x′)>0$ und alle $y\in Y$ gilt $P^x(y)=P^{x′}(y)$.

Bemerkung: Bedingung 1. fragt nach der Situation bei gegebenem Chiffretext y mit $Pr(y)>0$. Bedingung 2. ist die wahrscheinlichkeitstheoretisch klarste Charakterisierung von informationstheoretischer Sicherheit, ohne bedingte Wahrscheinlichkeiten zu verwenden. Bedingungen 3. und 4. machen deutlich, dass es nur auf das Verhalten des Kryptosystems (mit seiner Verteilung $Pr_K$) auf den aktiven Klartexten ankommt, nicht auf die Klartextverteilung. Sie sagen auch, worauf genau es ankommt: Für jeden beliebigen aktiven Buchstaben ist die von $e(x,*)$ und der Schlüsselverteilung erzeugte Verteilung auf den Chiffretexten gleich, und zwar gleich der absoluten Verteilung auf den Chiffretexten. Informationstheoretische Sicherheit von $V$ (also für alle Klartextverteilungen) heißt also, dass alle Funktionen $P^x:Y\rightarrow [0,1]$, für $x\in X$, gleich sind (weil man als $Pr_X$ eine Verteilung wählen kann, bei der alle Klartexte aktiv sind, zum Beispiel die Gleichverteilung).

Beweis: 
- ,,$1.\Rightarrow 2.$'': Wenn $Pr(y)=0$, gilt $Pr(x,y)=0=Pr(x)Pr(y)$. Sei jetzt $Pr(y)>0. Dann gilt $Pr(x,y)=Pr(y)Pr(x|y) = Pr(y)Pr(x)$, nach 1.
- ,,2.\Rightarrow 3.'': Wegen 2. gilt $Pr(y)Pr(x)=Pr(x,y)$. Andererseits ist $Pr(y|x)Pr(x)=Pr(x,y)$, also folgt 3. durch Kürzen mit $Pr(x)>0$.
- ,,3.\Rightarrow 4.'': Verwende (1.3) für $x$ und $x′$ und benutze 3.
- ,,4.\Rightarrow 1.'': (Dies ist natürlich der entscheidende und schwierigste Beweisschritt!) Nach Voraussetzung 4. gibt es für jedes $y\in Y$ ein $p_y$ mit $P^x(y)=p_y$ für alle aktiven $x\in X$. 
  - Nach Lemma 1.15.1 (Formel von der totalen Wahrscheinlichkeit) gilt dann für jedes y: $Pr(y)=\sum_{x\in X:Pr(x)>0} Pr(y|x)*Pr(x) = \sum_{x\in X: Pr(x)>0} P^x(y)*Pr(x) = \sum_{x\in X:Pr(x)>0} p_y*Pr(x) =p_y$.
  - Sei nun $y\in Y$ mit $Pr(y)>0$, und sei $x\in X$. Wenn $Pr(x)=0$ gilt, folgt auch $Pr(x|y)=0$. Wenn $x$ aktiv ist, dann gilt $Pr(x|y)=\frac{Pr(x,y)}{Pr(y)}=\frac{Pr(y|x)Pr(x)}{p_y}=\frac{P^x(y)Pr(x)}{p_y}=Pr(x)$, wie gewünscht.

Beispiel 1.32 Wir geben noch ein Beispiel für ein informationstheoretisch sicheres Kryptosystem mit $|X|=4,|Y|=6$ und $|K|=8$ an. Die Klartextverteilung ist irrelevant. Sei $X=\{a,b,c,d\},K=\{k_0,...,k_7\},Y=\{A,B,C,D,E,F\}$, und $e$ durch die folgende Tabelle gegeben. (Sie entsteht durch Zusammensetzen zweier informationstheoretisch sicherer Kryptosysteme mit jeweils vier Schlüsseln und vier Chiffretexten.)
| e                    | a   | b   | c   | d   |
| -------------------- | --- | --- | --- | --- |
| $k_0 (\frac{1}{6})$  | A   | B   | C   | D   |
| $k_1 (\frac{1}{6})$  | B   | C   | D   | A   |
| $k_2 (\frac{1}{6})$  | C   | D   | A   | B   |
| $k_3 (\frac{1}{6})$  | D   | A   | B   | C   |
| $k_4 (\frac{1}{12})$ | A   | B   | E   | F   |
| $k_5 (\frac{1}{12})$ | B   | A   | F   | E   |
| $k_6 (\frac{1}{12})$ | E   | F   | A   | B   |
| $k_7 (\frac{1}{12})$ | F   | E   | B   | A   |

Offensichtlich ist die Schlüsselverteilung nicht uniform. Jeder Schlüssel $k$ hat eine andere Chiffre $x\rightarrow e(x,k)$. Die (absoluten) Wahrscheinlichkeiten für die Chiffretexte sind ebenfalls nicht uniform ($Pr(A)=Pr(B)=\frac{1}{4}$, $Pr(C)=Pr(D)=\frac{1}{6}$, $Pr(E)=Pr(F)=\frac{1}{12}$). 
Die informationstechnische Sicherheit drückt sich dadurch aus, dass diese Chiffretextwahrscheinlichkeiten auch für jeden Klartext (also jede Spalte) separat auftreten.

## Fallstudie für Cyphertext-only-Angriffe: Vigenère-Chiffre
In der Einleitung wurde schon kurz die sogenannte Vigenère-Chiffre angesprochen. Dies ist ein klassisches Verfahren zur Verschlüsselung natürlich sprachiger Texte. Üblicherweise nimmt man dabei den zu verschlüsselnden Text, lässt alle Satzzeichen und alle Leerzeichen weg und wandelt Groß-in Kleinbuchstaben um. Umlaute und andere Sonderzeichen werden umschrieben. Resultat ist eine Folge $x=(x_0,...,x_{l-1})=x_0 ...x_{l-1}$ von Buchstaben im Klartextalphabet $\{a,...,z\}$ der Größe 26. Wir betrachten hier nur den Fall, wo die Klartextlänge von vornherein beschränkt ist (gemäß Szenario 1), also ist $l\geq L$ für ein festes L. Nun möchte man $x$ verschlüsseln. Ein informationstheoretisch sicheres Verfahren ist, für jede Buchstabenposition $0\geq i < L$ rein zufällig einen Schlüssel $k_i\in\{A,...,Z\}$ zu wählen und an Position $i$ die Verschiebechiffre mit Schlüssel $k_i$ anzuwenden. Der Schlüssel $k_0,...,k_{L-1}$ ist dann aber mindestens so lang wie die Klartextfolge. Allerdings ist das nach unseren bisherigen Ergebnissen auch unvermeidlich: Wenn $V=(X,K,Y,e,d,Pr_K)$ informationstheoretisch sicher ist, ist $(X,K,Y,e,d)$ possibilistisch sicher, also $|X|\geq |K|$.

Es liegt nahe, zu versuchen, mit nur einem Schlüsselbuchstaben oder mit einem kürzeren Schlüssel auszukommen. Dies führt zur einfachen (wiederholten) Verschiebechiffre und zur Vigenère-Chiffre. Wir zeigen, dass man diese mit einfachen Mitteln ,,brechen'' kann.

### Die Vigenère-Chiffre und Angriffe bei bekannter Schlüssellänge
Es ist bequem, anstelle von Buchstaben mit Zahlen zu rechnen. Mit $Z_n$ bezeichnen wir den Ring $\mathbb{Z}/n\mathbb{Z}$, also (etwas vereinfachend gesagt) den Ring der Zahlen $\{0,1,...,n-1\}$ mit Addition und Multiplikation modulo n als Operationen.

Definition: Eine Verschiebechiffre ist ein Kryptosystem $S=(Z_n,Z_n,Z_n,e,d)$ mit $e(x,k)=(x+k) mod\ n$. (Offensichtlich ist dann $d(y,k)=(y-k)mod\ n$.)

Unser zentrales Beispiel ist der Fall $n=26$, also $X=Y=K=\{0,1,2,...,25\}$. Wir identifizieren die Elemente dieser Menge mit den Buchstaben $a,...,z$ (bei X) bzw. $A,...,Z$ (bei K und Y). Die Konvention ist nach wie vor, Klartextbuchstaben klein und Schlüsselbuchstaben und Chiffretextbuchstaben groß zu schreiben.

Die einfachste Methode ist folgende Version der Cäsar-Chiffre: Wähle einen Schlüssel k aus $K=\{0,1,...,25\}=\{A,...,Z\}$ zufällig. Um ,,Texte'' (d.h. Wörterüber $\mathbb{Z}_n$) zu verschlüsseln, wird S buchstabenweise angewandt: Aus $x_0 x_1...x_{l-1}$ wird $e(x_0,k)e(x_1,k)...e(x_{l-1},k)$.

Diese Methode ist allerdings sehr leicht zu brechen, sogar ,,von Hand'', also ohne massiven Einsatz von Computern. Es gibt mindestens die folgenden naheliegenden Möglichkeiten, einen gegebenen Chiffretext $y_0...y_{l-1}$, der aus einem natürlichsprachigen Text entstanden ist, zu entschlüsseln:
1. probiere die 26 möglichen Schlüssel aus, oder
2. zähle, welche Buchstaben am häufigsten im Chiffretext vorkommen und teste die Hypothese, dass einer von diesen für ,,e'' steht.

Betrachte beispielsweise den Chiffretext $RYFWAVSVNPLVOULHUZAYLUNBUN$. 
- Zählen liefert folgende Häufigkeiten für die häufigsten Buchstaben: $U:4,L:3,N:3,V:3$.
- Vermutung: Einer dieser Buchstaben entspricht dem ,,e''.
- Der Schlüssel $k$ mit $e(e,k)=U$ ist $k=Q$. Entschlüsselung mit $Q$ liefert das Wort $bipgkfcfxzvfyevrejkivexlex$, das nicht sehr sinnvoll erscheint.
- Der Schlüssel $k$ mit $e(e,k)=L$ ist $k=H$. Entschlüsselung mit $H$ liefert kryptologie ohne anstrengung, und wir sind fertig.
- Als Basis für solche Entschlüsselungsansätze benutzt(e) man Häufigkeitstabellen für Buchstaben, wie die folgende (Angaben in Prozent):
    | Englisch  | Deutsch   | Italienisch |
    | --------- | --------- | ----------- |
    | E,e 12,31 | E,e 18,46 | E,e 11,79   |
    | T,t 9,59  | N,n 11,42 | A,a 11,74   |
    | A,a 8,05  | I,i 8,02  | I,i 11,28   |
    | O,o 7,94  | R,r 7,14  | O,o 9,83    |
- Dass das ,,e'' im Deutschen deutlich häufiger als im Englischen ist, liegt auch daran, dass bei der Umschreibung der Umlaute ä,ö und ü als ae, oe, ue jeweils ein ,,e'' entsteht.)

Man kann auch die Häufigkeiten von ,,Digrammen'' (zwei Buchstaben, z.B. ng) oder ,,Trigrammen''  (drei Buchstaben, z.B. ung oder eit) heranziehen, auch um unterschiedliche Sprachen zu unterscheiden.

Eine unangenehme Eigenschaft bei der wiederholten Anwendung von reinen Verschiebechiffren ist, dass identische Buchstaben stets gleich verschlüsselt werden. Zum Beispiel hat unabhängig vom Schlüssel der Klartext otto stets zu einem Chiffretext mit dem Muster abba.

Die Grundidee der Vigenère-Chiffre ist es nun, verschiedene Verschiebechiffren in festgelegter zyklischer Reihenfolge zu verwenden.

Schlüssel: $k=k_0 k_1 k_2 ...k_{s-1}\in Z^s_n,s\in\mathbb{N}$. (Eine Folge von Verschiebewerten.)

Klartext: $x=x_0 x_1...x_{l-1} \in Z^l_n,l\in\mathbb{N}$.

Man verschlüsselt $x_0$ mit $k_0$, $x_1$ mit $k_1$, und so weiter. Wenn irgendwann der Schlüssel ,,aufgebraucht'' ist, weil $s<l$ gilt, fängt man mit dem Schlüssel wieder von vorne an. Wir verschlüsseln also $x_0$ mit $k_0,...,x_{s-1}$ mit $k_{s-1},x_l$ mit $k_0,...,x_{2s-1}$ mit $k_{s-1}$,usw. 
Zusammengefasst: Der Chiffretext ist: $y=y_0 y_1...y_{l-1}\in(\mathbb{Z}_n)^*$ mit $y_i:=e(x_i,k_{i\ mod\ s})$, für $0\geq i < l$.

Man kann dieses Verfahren mit einem festen Schlüssel k nun natürlich auf beliebig lange Klartexte anwenden. Damit liegt hier kein Kryptosystem im (technischen) Sinn des letzten Abschnitts vor!

Beispiel: Wir benutzen der einfacheren Lesbarkeit halber Buchstaben anstelle der Zahlen $0,...,25$. Der Schlüssel ist VENUS.
|                        |                                 |
| ---------------------- | ------------------------------- |
| wiederholter Schlüssel | V E N U S V E N U S V E N U S V |
| Klartext               | p o l y a l p h a b e t i s c h |
| Chiffretext            | K S Y S S G T U U T Z X V M U C |

Wir werden die Längen $s$ des Schlüssels und $l$ des Klartextes ,,sinnvoll'' beschränken:

**Definition 1.33** Das Vigenère-Kryptosystem (mit Parametern $(n,S,L)\in\mathbb{N}^3$) ist das Kryptosystem ($(\mathbb{Z}_n)\geq L,(\mathbb{Z}_n)\geq S,(\mathbb{Z}_n)\geq L,e,d$), so dass für alle $s\geq S,l\geq L,x_i,k_j\in\mathbb{Z}_n$ gilt: $e(x_0...x_{l-1},k_0 ...k_{s-1})=y_0 ...y_{l-1}$ mit $y_i=(x_i+k_{i\ mod\ s}) mod\ n$, für alle $0\geq i < l$.

Für Anwendungen sollte man L ,,fast unendlich'' wählen, um die unendliche Menge der möglichen Klartexte zu approximieren. Hingegen wird S nicht sehr groß sein, da man die Anzahl der Schlüssel klein halten will.
Nun betrachten wir einen Angriff von Eva im Szenarium 1, bei dem sie nur einen Chiffretext y der Länge l hat. Nehmen wir zunächst an, dass sie auch die Schlüssellänge $s<<l$ und die zugrunde liegende (natürliche) Sprache kennt. Dann kann sie den Chiffretext durch Häufigkeitsanalysen zu entschlüsseln versuchen. Die zentrale Idee ist, dass für die Verschlüsselung des ,,Teiltextes'' $y_i=y_iy_{i+s}y_{i+2s}...$,für $0\geq i<s$, der Buchstabe $k_i$ benutzt wurde, genau wie bei der einfachen Verschiebechiffre. Für $i,0\geq i<s$, bestimmt Eva also die in diesem Teiltext $y_i=y_iy_{i+s}y_{i+2s}...$ am häufigsten vorkommenden Buchstaben und testet die Hypothesen, dass diese für ,,e'' oder einen anderen häufigen Buchstaben stehen.

Wir betrachten ein Beispiel für eine solche Analyse an einem Chiffretext. (In der klassischen Kryptographie war es üblich, die Texte in Fünfergruppen einzuteilen, um das Abzählen von Buchstabenpositionen zu erleichtern).

|                                                             |
| ----------------------------------------------------------- |
| EYRYC FWLJH FHSIU BHMJO UCSEG TNEER FLJLV SXMVY SSTKC MIKZS |
| JHZVB FXMXK PMMVW OZSIA FCRVF TNERH MCGYS OVYVF PNEVH JAOVW |
| UUYJU FOISH XOVUS FMKRP TWLCI FMWVZ TYOIS UUIIS ECIZV SVYVF |
| PCQUC HYRGO MUWKV BNXVB VHHWI FLMYF FNEVH JAOVW ULYER AYLER |
| VEEKS OCQDC OUXSS LUQVB FMALF EYHRT VYVXS TIVXH EUWJG JYARS |
| ILIER JBVVF BLFVW UHMTV UAIJH PYVKK VLHVB TCIUI SZXVB JBVVP |
| VYVFG BVIIO VWLEW DBXMS SFEJG FHFVJ PLWZS FCRVU FMXVZ MNIRI |
| GAESS HYPFS TNLRH UYR                                       |

- $y^0 =EFFBUTFSSMJFPOFTMOPJUFXFTFTUESPHMBVFFJUAVOOLFEVTEJIJBUUPVTSJVBVDSFPFFMGHTU$. 
  - Buchstaben in $y^0$ mit Häufigkeiten $>1:AB(4)DE(4)F(14)GH(2)IJ(5)LM(3)O(4)P(5)S(5)T(7)U(7)V(6)X$
  - Mögliches Bild von ,,e'': F. Schlüsselbuchstabe wäre: B
- $y^1 =YWHHCNLXSIHXMZCNCVNAUOOMWMYUCVCYUNHLNALYECUUMYYIUYLBLHAYLCZBYVWBFHLCMNAYNY$.
  - Buchstaben in $y^1:A(4)B(3)C(8)EFH(6)I(2)L(7)M(5)N(7)O(2)SU(5)V(3)W(2)X(2)Y(19)Z(2)$
  - Mögliches Bild von ,,e'':Y. Schlüsselbuchstabe wäre: U
- $y^2 =RLSMSEJMTKZMMSREGYEOYIVKLWOIIYQRWXHMEOYLEQXQAHVVWAIVFMIVHIXVVILXEFWRXIEPLR$.
  - Buchstaben in $y^2:A(2)E(7)F(2)GH(3)I(8)JK(2)L(5)M(6)O(2)PQ(3)R(5)S(3)TV(7)W(4)X(5)Y(4)Z$
  - Mögliche Bilder von ,,e'':I,V. Schlüsselbuchstaben wären: E,R
- $y^3 =YJIJEELVKZVXVIVRYVVVJSURCVIIZVUGKVWYVVEEKDSVLRXXJREVVTJKVUVVFIEMJVZVVRSFR$.
  - Buchstaben in $y^3 :CDE(6)F(2)GI(5)J(6)K(4)L(2)MR(6)S(3)TU(3)V(21)WX(3)Y(3)Z(3)$
  - Mögliches Bild von ,,e'':V. Schlüsselbuchstabe wäre: R
- $y^4 =CHUOGRVYCSBKWAFHSFHWUHSPIZSSVFCOVBIFHWRRSCSBFTSHGSRFWVHKBIBPGOWSGJSUZISSH$.
  - Buchstaben in $y^4 :AB(5)C(4)F(6)G(4)H(8)I(4)JK(2)O(3)P(2)R(4)S(13)TU(3)V(4)W(5)YZ(2)$
  - Mögliches Bild von ,,e'':S. Schlüsselbuchstabe wäre: O

Man versucht Schlüssel BURRO und erhält keinen sinnvollen Text. Mit BUERO ergibt sich:
denho echst enorg anisa tions stand erfuh rdiek rypto logie
inven edigw osiei nform einer staat liche nbuer otaet igkei
tausg euebt wurde esgab schlu essel sekre taere dieih rbuer
oimdo genpa lasth atten undfu erihr etaet igkei trund zehnd
ukate nimmo natbe kamen eswur dedaf uerge sorgt dasss iewae
hrend ihrer arbei tnich tgest oertw urden siedu rften ihreb
ueros abera uchni chtve rlass enbev orsie eineg estel lteau
fgabe geloe sthat ten

Ohne Gruppierung erhält man:
denhoechstenorganisationsstanderfuhrdiekryptologie
invenedigwosieinformeinerstaatlichenbuerotaetigkei
tausgeuebtwurdeesgabschluesselsekretaeredieihrbuer
oimdogenpalasthattenundfuerihretaetigkeitrundzehnd
ukatenimmonatbekameneswurdedafuergesorgtdasssiewae
hrendihrerarbeitnichtgestoertwurdensiedurftenihreb
uerosaberauchnichtverlassenbevorsieeinegestellteau
fgabegeloesthatten

Nun muss man nur noch die Wortzwischenräume und Satzzeichen ergänzen, um zu erhalten:
Den höchsten Organisationsstand erfuhr die Kryptologie in Venedig, wo sie in Form einer staatlichen Bürotätigkeit ausgeübt wurde. Es gab Schlüsselsekretäre, die ihr Büro im Dogenpalast hatten und für ihre Tätigkeit rund zehn Dukaten im Monat bekamen. Es wurde dafür gesorgt, dass sie während ihrer Arbeit nicht gestört wurden. Sie durften ihre Büros aber auch nicht verlassen, bevor sie eine gestellte Aufgabe gelöst hatten.

### Der Kasiski-Test
Das bisher betrachtete Verfahren setzt voraus, dass die Schlüssellänge s bekannt ist. Ist die maximale Schlüssellänge S klein, dann kann man die Schlüssellängen 1 bis S einzeln durchprobieren. Ist S groß, möchte man die Suche nach der richtigen Schlüssellänge abkürzen. (Besonders vor dem Computerzeitalter, wo die Dechiffrierung per Hand durchgeführt werden musste, war eine solche Zeitersparnis wichtig.) Die Schlüssellänge kann oft durch den Kasiski-Test näherungsweise bestimmt werden. (Der Test ist benannt nach Friedrich Wilhelm Kasiski (1805, 1881), einem preußischen Infanteriemajor. Der Test wurde von ihm 1863 veröffentlicht. Er war aber bereits 1854 von Charles Babbage entwickelt, aber nicht veröffentlicht worden.)

Die zentrale Idee des Tests ist die folgende einfache Beobachtung: Gleiche Klartextfragmente, die eventuell mehrfach vorkommen (z.B. das Wort ,,ein'') werden in gleiche Chiffretexte übersetzt, wenn sie unter dem gleichen Schlüsselfragment liegen. Genauer: Stimmt der Klartext im Abschnitt $i+s*l$ bis $j+s*(l+h)$ mit dem Klartext im Abschnitt von $i+s*l′$ bis $j+s*(l′+h)$ überein, so gilt dies auch für den Chiffretext $(1\geq i,j\geq s,l,l′,h\in\mathbb{N})$. 
Anders ausgedrückt: Kommt ein Teilwort im Klartext an zwei Positionen i und j und ist j-i ein Vielfaches von s, so werden die beiden Vorkommen des Wortes gleich verschlüsselt.

Diese Beobachtung wird in die folgende Idee für einen Angriff umgemünzt: Für möglichst viele ,,lange'' Wörter, die im Chiffretext mehrfach auftreten, notiere die Abstände des Auftretens. (,,lang'' sollte wenigstens 3 sein.) Dann suche ein großes s, das viele dieser Abstände teilt (nicht unbedingt alle, denn einige Mehrfach vorkommen im Chiffretext könnten zufällig entstanden sein).

Beispiel 1.34 Im Chiffretext von Abbildung 1 kommen (mindestens) die folgenden Wörter der Länge 3  mehrfach vor. Wir geben die Positionen und die Abstände an.

|                                                             | #Wörter |
| ----------------------------------------------------------- | ------- |
| AWMCJ IENAW NMOZV EYJOK HPXNK TFKQC JPJSJ NTIVT TCOJA AWKBS | 50      |
| NHKBV UYMJG NNUAH UEKFF DLNSJ SZRZL EUKRW IYLCJ MLZWC ECOBM | 100     |
| NOPSV ECOBX OCSOL IVKFC EYTHF IDYSM EMKFV IPCSK EYZZA CSKBS | 150     |
| LRUFA TSSWK CSKBO ECQNW URKVS BPTIW BPXGL RFQHM RPTRA EPYSJ | 200     |
| LLAPW NOGHW NPLTA ZTKBL ZFUFY AYOGA ECKBM NOGIX ZFLWF DPTIW | 250     |
| BPXVS EFLWY BPTIL ZEKOD GZXWL HXKBM NOAST ECJWW SEGBV ACJHW | 300     |
| CSTWC EYSWL DPTSF MLTOD GZXWL HXOGU HPVFG BWKAW MZJSD LTKFW | 350     |
| NGKFK TPNSF UYJZG EDKBC AYT                                 |

| Wort      | Positionen      | Abstände |
| --------- | --------------- | -------- |
| ODGZXWLHX | 269 , 319       | 50       |
| DPT       | 246 , 311       | 65       |
| BPT       | 176 , 261       | 115      |
| ECOB      | 96 , 106        | 10       |
| CSK       | 138 , 146 , 161 | 8*, 15   |
| AWM       | 1 , 339         | 338*     |
| PTIWBPX   | 177 , 247       | 70       |
| BMNO      | 99 , 234 , 279  | 135 , 45 |

Wir vermuten: Periode ist 5 (dann wären Wiederholungen von AWM und CSK durch Zufall entstanden)

Das Ergebnis der Entschlüsselung wie oben beschrieben mit vermuteter Schlüssellänge 5 und versuchten Schlüsseln ALGXS (erfolglos) und ALGOS (erfolgreich) ergibt den folgenden Text.
|                                                             | #Wörter |
| ----------------------------------------------------------- | ------- |
| algor ithme nbild endas herzs tueck jeder nicht trivi alena | 50      |
| nwend ungvo ncomp utern daher sollt ejede infor matik erinu | 100     |
| ndjed erinf ormat ikerk enntn isseu eberd iewes entli chena | 150     |
| lgori thmis chenw erkze ugeha benue berst ruktu rendi eeser | 200     |
| laube ndate neffi zient zuorg anisi erenu ndauf zufin denue | 250     |
| berha eufig benut zteal gorit hmenu ndueb erdie stand ardte | 300     |
| chnik enmit denen manal gorit hmisc hepro bleme model liere | 350     |
| nvers tehen undlo esenk ann                                 |

Mit Wortzwischenräumen und Satzzeichen:
Algorithmen bilden das Herzstück jeder nichttrivialen Anwendung von Computern. Daher sollte jede Informatikerin und jeder Informatiker Kenntnisse über die wesentlichen algorithmischen Werkzeuge haben: über Strukturen, die es erlauben, Daten effizient zu organisieren und aufzufinden, über häufig benutzte Algorithmen und über die Standardtechniken, mit denen man algorithmische Probleme modellieren, verstehen und lösen kann.

Bemerkungen: 
- (i) Der Test funktioniert nur gut, wenn die Schlüssellänge s gering im Verhältnis zur Chiffretextlänge l ist.
- (ii) Um ihn anwenden zu können, muss die Klartextsprache bekannt sein.
- (iii) Der Test kann auch in der viel allgemeineren Situation benutzt werden, in der Schlüssel nicht s Verschiebungen, sondern s beliebige Substitutionschiffren auf $X$ bestimmen (z.B. $X=Y$ und Schlüssel ist Tupel($\pi_0,...,\pi_{s-1}$) von Permutationen von $X$).

Was passiert im Extremfall $s=l$?
- Grundsätzlich hat man dann ein informationstheoretisch sicheres one-time pad vor sich...
- ... aber nur dann, wenn die Schlüssel gleichverteilt gewählt werden.  Wenn der Schlüssel selbst ein deutscher Text ist (z.B. ein Textstück aus einem Buch), so weist der Chiffretext wieder statistische Merkmale auf, die zum Brechen ausgenutzt werden können. (Beispiel: Wenn Schlüssel und Klartext beides deutsche Texte sind, werden ca. $7,6%$ der Buchstaben mit sich selbst verschlüsselt, d.h. Chiffretextbuchstabe$= 2 *$ Klartextbuchstabe modulo 26.)

Effektive Verfahren der Schlüsselverlängerung (die aber keine informationstheoretische Sicherheit bringen):
- Autokey-Vigenère: Schlüssel k, Klartext m. Dann wird klassische Vigenère-Chiffre mit Schlüssel km auf m angewendet.
- Pseudozufallszahlen: Geheimer Schlüssel ist seed eines (Pseudo-)Zufallszahlengenerators, mit dem eine lange Schlüsselfolge $k_0,...,k_{l-1}$ erzeugt wird.

### Koinzidenzindex und Friedman-Methode
Wir betrachten noch eine andere interessante Methode zur Abschätzung der Schlüssellänge, die bei der Verwendung einer Vigenère-Chiffre oder anderen Substitutionschiffren mit fester Schlüssellänge s helfen können, diese zu ermitteln. Die Methode beruht darauf, dass die Buchstabenhäufigkeiten (zu einer gegebenen Sprache) fest stehen und sich bei der Verschlüsselung mit einer einfachen Substitutionschiffre nicht ändert. Ebenso ändert sich nicht die Wahrscheinlichkeit, bei der zufälligen Wahl eines Buchstabenpaars zwei identische Buchstaben zu erhalten. Die Methode stammt von William F. Friedman (1891, 1969), einem amerikanischen Kryptographen.

Sei $x=x_0...x_{l-1}$ ein Klartext, sei $y=y_0...y_{l-1}$ der zugehörige Chiffretext, bei $s=1$ (an jeder Stelle derselbe Schlüssel). Seien $n_0,...,n_{25}$ die Anzahlen der Buchstaben $a,...,z$ in $x,n′_0,...,n′_25$ die in $y$. Wir wählen zufällig ein Paar von zwei Positionen in x (ohne ,,Zurücklegen''). Dafür gibt es $\binom{l}{2}$ Möglichkeiten. Genau $\binom{n_i}{2}$ viele davon führen dazu, dass man zweimal den Buchstaben Nummer i zieht, und $\sum_{0\geq i<26}\binom{n_i}{2}$ viele führen dazu, dass man an den beiden Positionen denselben Buchstaben sieht. Wir setzen $IC(x):=\frac{\sum_{0\geq i<26}\binom{n_i}{2}}{\binom{l}{2}}=\frac{\sum_{0\leq i<26}n_i(n_i-1)}{l(l-1)}$. 
Diese Zahl nennt man den Koinzidenzindex von x. Sie ist die Wahrscheinlichkeit dafür, dass an den beiden zufällig gewählten Positionen der selbe Buchstabe steht. Weil die Verschlüsselung auf den Buchstaben eine Bijektion ist, also sich die vorkommenden Häufigkeiten durch die Verschlüsselung nicht ändern, gilt für $IC(y):=\frac{\sum_{0\geq i<26} n′_i(n′_i -1)}{l(l-1)}$ die Gleichung $IC(x)=IC(y)$.
Für lange Texte mit (sprachtypischer) Häufigkeitsverteilung der Buchstaben nähert sich $IC(x)$ einem bestimmten Wert an. Wenn $p_i$ die Häufigkeit von Buchstabe i in der verwendeten Sprache ist, wird für lange Texte x die Näherung $\frac{n_i}{l}\approx\frac{n_i-1}{l-1}\approx p_i$ gelten, also $IC(x)\approx \sum_{0\geq i<26} p^2_i$ sein. Die Summe $\sum_{0\geq i<26} p^2_i$ hat beispielsweise einen Wert von etwa $0,076$ für deutsche und $0,066$ für englische Texte. Wenn (in einer fiktiven Sprache) jeder Buchstabe dieselbe Wahrscheinlichkeit hat, ist $\sum_{0\geq i<26} p^2_i= 26*(\frac{1}{26})^2=\frac{1}{26}\approx 0,0385$; dies ist zugleich der minimal mögliche Wert.

Für die Ermittlung eines Schätzwertes für die Schlüssellänge s gehen wir wie folgt vor. Wir nehmen an, die zugrunde liegende Sprache ist Deutsch. Wir berechnen zunächst $IC(y)$ für den Chiffretext y. Die unbekannte Schlüssellänge nennen wir s. Dann berechnen wir eine Näherung für $IC(y)$, auf eine zweite Weise. Dies wird uns eine (Näherungs-)Gleichung für s liefern.

Wir überlegen: Bilde die Teilwörter $y^0,...,y^{s-1}$ wie in Abschnitt 1.4, jedes mit der Länge $\frac{l}{s}$. Innerhalb jedes Teilworts kommen Kollisionen ebenso häufig vor wie in einem gewöhnlichen Text mit nur einem Schlüssel, also erwarten wir zusammen $\binom{l/s}{2} IC(y^0)+...+\binom{l/s}{2} IC(y^{s-1})\approx s\binom{l/s}{2}* 0,076 = \frac{1}{2}l(l/s-1)* 0,076$ viele ,,Kollisionen''  (Paare identischer Chiffretextbuchstaben) aus den einzelnen Teilwörtern. 
Zwischen zwei Teilwörtern $y^u$ und $y^v$ erwarten wir $(l/s)^2*261\approx 0,0385(l/s)^2$ Kollisionen, aus allen $\binom{s}{2}$ Paaren von Teilwörtern zusammen also $\binom{s}{2} 0,0385(l/s)^2 =\frac{s(s-1)}{2}* 0,0385(l/s)^2 =\frac{1}{2} *0,0385 l^2 (1-\frac{1}{s})$ viele. Zusammen ist die erwartete Anzahl an Kollisionen in y gleich $\frac{1}{2}l(0,076(l/s-1) + 0,0385 l(1-\frac{1}{s}))$.
Diese Zahl sollte näherungsweise gleich $\frac{1}{2}l(l-1)IC(y)$ sein. Wir können die resultierende Gleichung $(l-1)IC(y) = 0,076(l/s-1) + 0,0385 l(1-\frac{1}{s})$ nach s auflösen und erhalten: $s\approx \frac{(0,076-0,0385)l}{(l-1)IC(y)-0,0385l+0,076}$. (Wenn man anstelle der Konstanten $0,076$ den Wert $0,066$ einsetzt, erhält man die entsprechende Formel für englischsprachige Texte.)
Eine tatsächliche Durchführung des Verfahrens mit Chiffretexten wie im vorigen Kapitel erfordert viel Geduld (oder den Einsatz eines Computers).

Beim ,,venezianischen'' Chiffretext EYRYC...UYR von oben ergibt sich:
| $a_i$  | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   |
| ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $n′_i$ | 8   | 12  | 13  | 2   | 18  | 25  | 7   | 19  | 20  | 14  | 8   | 15  | 16  | 7   | 12  | 8   | 3   | 15  | 25  | 10  | 19  | 41  | 13  | 11  | 19  | 8   |

Dies liefert $IC(y)\approx 0,048024$ und $l=368$. Damit erhalten wir $s\approx\frac{0,0375*368}{367 *0,048024-0,0385 *368+0,076}\approx 3,9$.
Das ist nicht zu nahe am tatsächlichen Wert 5, aber auch nicht ungeheuer weit weg. (Die Formel reagiert sehr empfindlich auf kleine Änderungen in $IC(y)$. Mit $IC(y)=0,05$ ergibt sich $s\approx 3,24$, mit $IC(y)=0,046$ ergibt sich $s\approx 4,95$.)

# Frische symmetrische Verschlüsselung und Blockchiffren
Szenarium 2 (frische symmetrische Verschlüsselung): Alice möchte Bob mehrere verschiedene Klartexte vorher bekannter und begrenzter Länge übermitteln. Sie verwendet dafür immer denselben Schlüssel. Eva hört die Chiffretexte mit und kann sich sogar einige Klartexte mit dem verwendeten Schlüssel verschlüsseln lassen (chosen-plaintext attack, CPA).

Bemerkung: Das informationstheoretisch sichere Vernam-Kryptosystem aus Kapitel 1 ist nutzlos: Aus Kenntnis von $x\in\{0,1\}^l$ und $y=e(x,k)$ für ein einziges Paar $(x,k)\in X\times K$ kann Eva den Schlüssel $k=x\oplus_l y$ berechnen.
Gleiches gilt für das Cäsar-System und das Vigenère-System.

Mit dem nächsten Begriff erfassen wir folgende Situation: Eva kennt eine ganze Folge von Klartext-Chiffretext-Paaren bezüglich des (ihr unbekannten) Schlüssels k. Dabei kann sie sich die Klartexte sogar selbst herausgesucht haben. Wir wollen ,,possibilistische Sicherheit'' so definieren, dass sie trotzdem bei beliebigem gegebenem weiteren Chiffretext y keinen Klartext ausschließen kann.

Definition 2.1 Ein Kryptosystem $S=(X,K,Y,e,d)$ ist possibilistisch sicher bzgl. Szenarium 2 ,wenn für jedes $1 \leq r\leq |X|$, jede Folge von paarweise verschiedenen Klartexten $x_1,x_2,...,x_r\in X$, jeden Schlüssel $k\in K$ und jedes $y\in Y\backslash\{e(x_i,k)| 1 \leq i < r\}$ ein Schlüssel $k′\in K$ existiert mit $e(x_i,k)=e(x_i,k′)$ für alle $1\leq i< r$ und $e(x_r,k′)=y$.

Wenn man die Definition auf $r=1$ anwendet, ergibt sich, dass S auch possibilistisch sicher im Sinn von Kapitel 1 ist.

Proposition 2.2 Für jede nichtleere Menge $X$ ist das Substitutionskryptosystem (Def.1.9) auf X possibilistisch sicher. (Erinnerung: $K=P_X=\{\pi|\pi\text{ ist Permutation von }X\}$ und $e(\pi,x)=\pi(x)$.) 
Beweis: Seien $x_1,x_2,...,x_r\in X$ paarweise verschieden, $k\in K=P_X$ und $y\in Y\{e(x_i,k)|1\leq i<r\}$. Aufgrund der Dechiffrierbedingung sind die Geheimtexte $e(x_i,k)$ für $1\leq i<r$ paarweise verschieden. Also gilt $|Y\backslash(\{y\}\cup\{e(x_i,k)| 1\leq i<r\})|=|Y|-r=|X|-r=|X\backslash\{x_1 ,...,x_r\}|$, und es existiert eine Bijektion $f:X\{x_1,...,x_r\}\rightarrow Y\backslash(\{y\}\cup\{e(x_i,k)| 1\leq i<r\})$.
Definiere nun $\pi:X\rightarrow Y$ durch $\pi(x) =\begin{cases} e(x_i,k)\quad\text{ falls }\exists i\in\{1,...,r-1\}:x=x_i \\ y\quad\text{ falls } x=x_r \\ f(x)\quad\text{ sonst}\end{cases}$.
Dann ist $\pi$ eine Bijektion und damit eine Permutation von X (da $X=Y$).

Proposition 2.3 Sei $S=(X,K,Y,e,d)$ ein Kryptosystem, das possibilistisch sicher ist bzgl. Szenarium 2. Dann ist $\{e(.,k)|k\in K\}$ die Menge aller injektiven Abbildungen von X nach Y.
Beweis: Aus der Dechiffrierbedingung folgt sofort, dass alle Abbildungen $e(.,k)$ injektiv sind.
Sei nun $\pi:X\rightarrow Y$ eine beliebige injektive Abbildung. Weiter gelte $X=\{x_1,...,x_t\}$. Wir konstruieren induktiv Schlüssel $k_1,...,k_t$ mit $\forall i\in\{1,...,r\}:e(x_i,k_r)=\pi(x_i)$.
Das heißt: Schlüssel $k_r$ realisiert $\pi$ eingeschränkt auf $\{x_1,...,x_r\}$.

Da S auch possibilistisch sicher bzgl. Szenarium 1 ist, existiert der Schlüssel $k_1$ wie gewünscht. Die Schlüssel $k_r$ für $r=2,...,t$ ergeben sich nacheinander, indem man wiederholt Definition 2.1 auf $\{x_1,...,x_r\},k_{r-1}$ und $y=\pi(x_r)$ anwendet. Schließlich gilt $e(.,k_t)=\pi$.

Im Fall $X=Y$ folgt, dass nur das Substitutionskryptosystem possibilistisch sicher bzgl. Szenarium 2 ist.

Ein Kryptosystem, das possibilistisch sicher bzgl. Szenarium 2 ist, hat also mindestens $|\{\pi |\pi :X\rightarrow Y\text{ ist injektiv}\}|=\frac{|Y|!}{(|Y|-|X|)!} \geq |X|!$ Schlüssel. Mit $X=\{0,1\}^{128}$  (das ist durchaus realistisch!) gibt es also $\geq 2^{128}!$ viele Schlüssel. Für die Speicherung eines Schlüssels braucht man also durchschnittlich (Es gilt $log_2(N!)>N(log_2 N-log_2 e)> N(log_2 N- 1.45)$) $log(2^{128}!)> 2^{128}*(128- 1.45)> 2^{134}>(10^3 )^{13.4} > 10^{40}$ viele Bits, eine völlig unpraktikable Zahl.
Also können wir in realen Situationen im Szenarium 2 keine possibilistische Sicherheit, geschweige denn informationstheoretische Sicherheit erhalten.

Wir werden uns in diesem Kapitel also darauf verlassen müssen, dass Eva nur beschränkte Rechenressourcen hat, um einen praktikablen Angriff zu starten. Auf der anderen Seite wollen wir jetzt auch annehmen, dass Alice und Bob mit Computerhilfe verschlüsseln und entschlüsseln wollen, d.h. dass wir effiziente Algorithmen für die Ver- und Entschlüsselung benötigen. Damit wird es sinnvoll anzunehmen, dass Klar- und Geheimtexte und Schlüssel Bitvektoren sind.

Definition 2.4 Sei $l>0$. Ein l-Block-Kryptosystem ist ein Kryptosystem $S=(\{0,1\}^l,K,\{0,1\}^l,e,d)$ mit $K\subseteq \{0,1\}^s$ für ein $s>0$.

Beispiele für l-Block-Kryptosysteme sind das Vernam-System der Länge l und Substitutionskryptosystem mit $X=\{0,1\}^l$, falls Permutationen als Bitvektoren kodiert sind. Wir sprechen dann vom Substitutionskryptosystem mit Parameter $l$.
Eine weitere Klasse von Verfahren wird im nächsten Abschnitt vorgestellt.

## Substitutions-Permutations-Kryptosysteme (SPKS)
Substitutions-Permutations-Kryptosysteme bilden eine große Familie von praktisch relevanten Kryptosystemen, zu denen auch die Verfahren des Data Encryption Standard (DES) und des Advanced Encryption Standard (AES) gehören.

Grundsätzlich handelt es sich um $mn$-Block-Kryptosysteme. Dabei werden die Klartexte $x=(x_0,...,x_{mn-1})\in\{ 0,1\}^{mn}$ als m-Tupel $(x^{(0)},x^{(1)},...,x^{(m-1)})$ von Bitvektoren der Länge n betrachtet. Dabei gilt $x(i)=(x_{in},x_{in+1},...,x_{(i+1)n-1})$, für $0\leq i<m$. 
Ein Baustein der Verschlüsselungs- und Entschlüsselungsfunktion bei diesen Systemen sind Bitpermutationen  auf Bitstrings der Länge l: Sei β eine Permutation von $\{0,...,l-1\}$ und $x\in\{0,1\}^l$. Dann bezeichnet $x^β$ den Bitvektor $(x_{β(0)},x_{β(1)},...,x_{β(l-1)})$. Kurz: $x^β_{(i)}=x_{β(i)}$, für $0\leq i<l$.
Sehr oft werden wir annehmen, dass β selbst invers ist, dass also $β^{-1}=β$ ist (oder $β(β(i))=i$ für $0\leq i<l$). Dann erhält man $x^β$ aus x, indem man $x(i)$ an die Stelle $β(i)$ des neuen Vektors schreibt.

Definition 2.5 Ein Substitutions-Permutations-Netzwerk (SPN) ist ein Tupel $N=(m,n,r,s,S,\beta,\kappa)$ wobei 
- die positiven ganzen Zahlen $m,n,r$ und $s$ die Wortanzahl $m$, die Wortlängen, die Rundenzahl r und die Schlüssellänge s angeben,
- $S:\{0,1\}^n\rightarrow\{0,1\}^n$ eine bijektive Funktion ist (,,Substitution'',die S-Box),
- $β:\{0,...,mn-1\}\rightarrow\{0,...,mn-1\}$ eine selbstinverse Permutation (die Bitpermutation) ist und
- $\kappa :\{0,1\}s\times\{0,...,r\}\rightarrow\{0,1\}^{mn}$ die Rundenschlüsselfunktion ist.

Das zu N gehörende Substitutions-Permutations-Kryptosystem (SPKS) ist das mn-Block-Kryptosystem $B(N)=(\{0,1\}^{mn},\{0,1\}^s,\{0,1\}^{mn},e,d)$, das durch folgende Operationen beschrieben ist:

Chiffrierung: $e(x,k)$ wird für $x\in\{0,1\}^{mn}$ und $k\in\{0,1\}^s$ wie folgt berechnet:
1. Initialisierung (,,Weißschritt''): Berechne $u=x\oplus_{mn} \kappa (k,0)$.
2. Verschlüsselung in Runden: für $i=1,...,r-1$ berechne
    1. $v(j)=S(u(j))$ für $0\leq j<m$ (jedes Wort einzeln durch die S-Box)
    2. $w=v^β$ (Bitpermutation auf dem Gesamtwort der Länge mn)
    3. $u=w\oplus_{mn} \kappa (k,i)$ (XOR mit dem Rundenschlüssel)
3. Schlussrunde: $v(j)=S(u(j))$ für $0\leq j<m$
4. Ausgabe: $y=v\oplus \kappa (k,r)$ (wie gewöhnliche Runde, ohne Bitpermutation)

Dechiffrierung: $d(y,k)$ wird aus y und k nach demselben Verfahren berechnet, wobei jedoch
1. die S-Box (die eine Permutation ist) durch ihre Inverse $S^{-1}$ ersetzt wird und
2. die Rundenschlüsselfunktion $\kappa$ ersetzt wird durch die Funktion $\kappa′:\{0,1\}^s\times\{0,...,r\}\rightarrow\{0,1\}^{mn}$, $(k,i)\rightarrow\begin{cases} \kappa (k,r-i)\quad\text{ für } i\in\{0,r\}\\ \kappa(k,r-i)^{\beta} \quad\text{ für } 0<i<r \end{cases}$

Vorteil der Struktur: Man kann dieselbe Hardware für Verschlüsselung und Entschlüsselung benutzen. Bei der Entschlüsselung läuft der Vorgang rückwärts ab, wobei die Runden anders gruppiert sind. Anstelle von S verwendet man $S^{-1}$. Da $β$ selbst invers ist, kann man für die Permutation auch bei der Dekodierung β verwenden. Da Permutation und Schlüsselanwendung in den Runden vertauscht sind, muss man auf die Rundenschlüssel der ,,inneren'' Runden bei der Dekodierung auch noch β anwenden.

Ein typischer Vertreter dieser Art Kryptosystem ist DES (bzw. sind die Chiffren der DES-Familie). Die DES-Version mit Blocklänge 64 und effektiver Schlüsselbreite 56 (das heißt, dass der Schlüsselraum Größe $2^{56}$ hat) wurde im Jahr 1977 als Standard für nicht geheime Dokumente in den USA publiziert. ,,Lineare Kryptanalyse'' ist eine Methode, solche Verfahren zu attackieren. Nach Weiterentwicklung der Methode gelang 1999 die Entschlüsselung einer DES-verschlüsselten Nachricht in weniger als einem Tag, mit einem Verbund von 100000 Arbeitsplatzrechnern, die im Wesentlichen alle Schlüssel durchprobierten. Dabei wurden über 240 Milliarden Schlüssel pro Sekunde getestet. Stärkere Varianten wie Triple-DES werden auch heute noch eingesetzt.

Beispiel 2.6 Die Wortanzahl ist $m=3$, die Wortlänge $n=4$, die Rundenzahl $r=3$, die Schlüssellänge $s=24=6*n$, und $\kappa (k,i)=k^{(i)}k^{(i+1)}k^{(i+2)}$. Die Bitpermutation β vertauscht die Bits $(0,4),(1,5),(2,8),(3,9),(6,10)$ und $(7,11)$ und ist damit selbst invers. Die S-Box ist gegeben durch die folgende zweizeilige Tabelle:
| b    | 0000 | 0001 | 0010 | 0011 | 0100 | 0101 | 0110 | 0111 | 1000 | 1001 | 1010 | 1011 | 1100 | 1101 | 1110 | 1111 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| S(b) | 0101 | 0100 | 1101 | 0001 | 0011 | 1100 | 1011 | 1000 | 1010 | 0010 | 0110 | 1111 | 1001 | 1110 | 0000 | 0111 |

Für $x= 0000 1111 0000$ und $k=0000 0001 0010 0011 0100 0101$ ergeben sich nacheinander
1. $\kappa (k,0) = 0000 0001 0010$ und damit $u= 0000 1110 0010$
2. 
   - $i=1$ $v=0101 0000 1101$, $w=0011 0101 0100$, $\kappa (k,1) = 0001 0010 0011$ und $u=0010 0111 0111$ 
   - $i=2$ $v=1101 1000 1000$, $w=1010 1100 0100$, $\kappa (k,2) = 0010 0011 0100$ und damit $u= 1000 1111 0000$
3. $v=1010 0111 0101$, $\kappa (k,3) = 0011 0100 0101$ und damit $y=1001 0011 0000$


### Einschub: Endliche Körper
Zur Vorbereitung der Beschreibung von AES und für die spätere Verwendung in asymmetrischen Systemen diskutieren wir kurz die Konstruktion von endlichen Körpern mit $2^k$ Elementen. Dies ist eine Spezialisierung einer allgemeinen Konstruktion, die es erlaubt, aus einem Körper mit $q$ Elementen einen mit $q^k$ Elementen zu konstruieren.
Die Struktur $\mathbb{Z}_2=(\{0,1\},\oplus,\odot, 0 ,1)$ ist ein Körper, wobei $\oplus$ für die XOR-Operation und für $\wedge$ (AND) steht. (Körper: Addition, Multiplikation mit den üblichen Gesetzen, d.h. $(F,\oplus ,0)$ ist kommutative Gruppe, ist assoziativ und hat 1 als neutrales Element, die Distributivgesetze gelten, und Elemente $\not=0$ haben ein multiplikatives Inverses.) Man beachte, dass in $\mathbb{Z}_2$ die Subtraktion dasselbe ist wie die Addition: $a\oplus a= 0$ für $a=0,1$.

Zu einem endlichen Körper $F$ (zentrales Beispiel:$\mathbb{Z}_2$) bildet man den Polynomring $F[X]$. Vorstellen sollte man sich diesen als die Menge aller ,,formalen Ausdrücke'' $a_n* X^n+...+a_2 *X^2 +a_1 *X+a_0$, für $n\geq 0$ und $a_n,...,a_1,a_0\in F$. Ein solcher Ausdruck wird mit seiner Koeffizientenfolge $(...,0,0,a_n,...,a_1,a_0)$ (gegebenenfalls künstlich als unendliche Folge geschrieben) identifiziert. Normalerweise lässt man Terme mit Koeffizient 0 weg. Über $\mathbb{Z}_2$ schreibt man wie üblich oft nur den Bitstring $a_n...a_1a_0$ ohne Klammern und Kommas.

Beispiel: In $\mathbb{Z}_2[X]$ liegen die Polynome $g=01011=(..., 0 , 1 , 0 , 1 ,1) =X^3 +X+1$ und $h=0110=(..., 0 , 1 , 1 ,0) =X^2 +X$.

Der Grad eines solchen Polynoms ist n, wenn n maximal mit $a_n\not = 0$ ist. Falls alle Koeffizienten gleich 0 sind (f ist das ,,Nullpolynom'', man schreibt 0), ist der Grad $-\infty$. Man addiert und subtrahiert solche Polynome wie üblich (d.h. komponentenweise) und multipliziert sie wie üblich (aus multiplizieren, Koeffizienten bei der selben X-Potenz aufsammeln). Als geschlossene Formel: Das Produkt von $(...,0,0,a_n,...,a_1,a_0)$ und $(...,0,0,b_m,...,b_1,b_0)$ ist $(...,0,0,c_{n+m},...,c_1,c_0)$ mit $c_k=\sum_{0\geq i\geq n; 0\geq j\geq m; i+j=k} a_i*b_j$.

Beispiel: Die Summe von g und h ist $g+h=01101=(...,0,1,1,0,1)$, ihr Produkt ist $g*h=X^5+X^4+X^3+X=(...,0,0,1,1,1,0,1,0)=111010$.

Mit diesen Operationen erhält $F[X]$ die Struktur eines Rings: Die Addition ist Gruppe mit neutralem Element 0 (Nullpolynom), die Multiplikation ist assoziativ mit neutralem Element $1=(...,0,0,0,1)$, die Distributivgesetze gelten.
Als Grundmenge des zu konstruierenden Körpers verwenden wir $F^k$, die Menge aller k-Tupel über F. Dies entspricht der Menge aller Polynome vom Grad bis zu $k-1$. Diese Menge hat genau $|F|^k$ Elemente. Im Fall $F=\mathbb{Z}_2$ erhalten wir $\{0,1\}^k$, die Menge aller Bitstrings der Länge k.

Als Addition $\oplus$ benutzen wir die gewöhnliche Addition von Polynomen, also die komponentenweise Addition der Tupel. Bei $F=\mathbb{Z}^k_2$ ist dies einfach das bitweise XOR. Wir geben die Additionstafel für $k=4$ an. Die Elemente des Körpers $GF(2^4)$ werden dabei wir üblich als Hexadezimalziffern geschrieben. Achtung: Man muss die Einträge richtig interpretieren, nämlich als Bitstrings, nicht als Zahlen: $5\oplus C=0101\oplus 1100=1001=9$.

| $\oplus$ | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | A   | B   | C   | D   | E   | F |
| -------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0        | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | A   | B   | C   | D   | E   | F |
| 1        | 1   | 0   | 3   | 2   | 5   | 4   | 7   | 6   | 9   | 8   | B   | A   | D   | C   | F   | E |
| 2        | 2   | 3   | 0   | 1   | 6   | 7   | 4   | 5   | A   | B   | 8   | 9   | E   | F   | C   | D |
| ...      |

Die Multiplikation $\odot$ ist etwas komplizierter.

Es wird ein irreduzibles Polynom $f=X^k+a_{k-1}* X^{k-1}+...+a_1*X+a_0$ vom Grad k (mit ,,Leitkoeffizient'' $a_k=1$) benötigt, also ein Koeffiziententupel $(1,a_{k-1},...,a_1,a_0)$ mit der Eigenschaft, dass man nicht $f=f_1*f_2$ schreiben kann, für Polynome $f_1$ und $f_2$, die Grad $\geq 1$ haben. Man kann zeigen, dass es für jedes $k\geq 2$ stets solche Polynome gibt. Sie können mit randomisierten Algorithmen effizient gefunden werden. Hier einige Beispiele für $F=\mathbb{Z}_2$. Wie üblich schreibt man die Koeffizientenfolge als Bitstring. Dieser Bitstring kann dann auch als natürliche Zahl (dezimal geschrieben) interpretiert werden.

| k   | irreduzibles Polynom vom Grad k über $\mathbb{Z}_2$ | Kurzform  | Zahl |
| --- | --------------------------------------------------- | --------- | ---- |
| 1   | $X+ 1$                                              | 11        | 3    |
| 2   | $X^2 +X+ 1$                                         | 111       | 7    |
| 3   | $X^3 +X+ 1$                                         | 1011      | 11   |
| 4   | $X^4 +X+ 1$                                         | 10011     | 19   |
| 5   | $X^5 +X^2 + 1$                                      | 100101    | 37   |
| 6   | $X^6 +X+ 1$                                         | 1000011   | 67   |
| 7   | $X^7 +X^3 + 1$                                      | 10001001  | 137  |
| 8   | $X^8 +X^4 +X^3 +X+ 1$                               | 100011011 | 283  |

Das Polynom $X^2+1=(1,0,1)=101$ ist nicht irreduzibel, da über $\mathbb{Z}_2$ die Gleichung $(X+1)*(X+1)=X^2+1$ gilt.

Die Multiplikation funktioniert nun wie folgt: Wenn g und h gegeben sind, berechnet man das Prddukt $g*h$ (Grad maximal $2k-2$) und bestimmt den Rest $r$ von $g*h$ bei der Division durch $f$. Dieser Rest (genannt ,,$g*h mod f$'') ist das eindeutig bestimmte Polynom r vom Grad höchstens $k-1$, das $g*h=q*f+r$ erfüllt, für ein ,,Quotientenpolynom'' q.

Beispiel: Sei $k=4$ und $f=(1,0,0,1,1)=10011$. Die Faktoren seien $g=(1,0,1,1)=1011$ und $h=(0,1,1,0)=110$. Das Produkt ist $g*h=(1,1,1,0,1,0)=111010$. Wenn wir hier von $f*(X+1)=(1,1,0,1,0,1)=110101$ subtrahieren, erhalten wir das Produkt $(1,1,1,1)=1111$ im Körper.

Man kann durch geduldiges Multiplizieren und Bilden von Resten (also Dividieren von Polynomen) in dieser Weise eine komplette Multiplikationstabelle aufstellen. Geschickter ist Folgendes: Man berechnet alle Produkte $g*h mod f$, für die in g und in h jeweils die ersten beiden Bits oder die letzten beiden Bits 0 sind. (Wenn man beobachtet, dass $(0,0,0,1)=0001$ das neutrale Element ist, und die Kommutativität berücksichtigt, muss man nur 15 Produkte berechnen.) Es ergibt sich die folgende Tabelle.

| $\odot$ | 0000 | 0001 | 0010 | 0011 | 0100 | 1000 | 1100 |
| ------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 0000    | 0000 | 0000 | 0000 | 0000 | 0000 | 0000 | 0000 |
| 0001    | 0000 | 0001 | 0010 | 0011 | 0100 | 1000 | 1100 |
| 0010    | 0000 | 0010 | 0100 | 0110 | 1000 | 0011 | 1011 |
| 0011    | 0000 | 0011 | 0110 | 0101 | 1100 | 1011 | 0111 |
| 0100    | 0000 | 0100 | 1000 | 1100 | 0011 | 0110 | 0101 |
| 1000    | 0000 | 1000 | 0011 | 1011 | 0110 | 1100 | 1010 |
| 1100    | 0000 | 1100 | 1011 | 0111 | 0101 | 1010 | 1111 |

Wir notieren weiterhin Bitstrings $(a_3,a_2,a_1,a_0)=a_3a_2a_1a_0$ hexadezimal. Das Polynom $g=(1,0,1,1)=1011$ ist also $B=1000\oplus 0011=8\oplus 3$, das Polynom $h=(0,1,1,0)=0110$ ist $6=0100\oplus 0010=4\oplus 2$.
Die Tabelle sieht dann so aus:
| $\odot$ | 0   | 1   | 2   | 3   | 4   | 8   | C   |
| ------- | --- | --- | --- | --- | --- | --- | --- |
| 0       | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1       | 0   | 1   | 2   | 3   | 4   | 8   | C   |
| 2       | 0   | 2   | 4   | 6   | 8   | 3   | B   |
| 3       | 0   | 3   | 6   | 5   | C   | B   | 7   |
| 4       | 0   | 4   | 8   | C   | 3   | 6   | 5   |
| 8       | 0   | 8   | 3   | B   | 6   | C   | A   |
| C       | 0   | C   | B   | 7   | 5   | A   | F   |

Nun wollen wir beliebige Polynome multiplizieren. Beispiel: Um $g=(1,0,1,1)=1011=B$ und $h=(0,1,1,0)=0110=6$ zu multiplizieren, rechnet man unter Benutzung der Tabelle und des Distributivgesetzes wie folgt (Multiplikation modulo f):
$B\odot 6=(8\oplus 3)(4\oplus 2)=(8\odot 4)\oplus(8\odot 2)\oplus(3\odot 4)\oplus(3\odot 2)=6\oplus 3\oplus C\oplus 6= 0110\oplus 0011 \oplus 1100 \oplus 0110 = 1111 = F$.

Mit etwas Geduld und unter Ausnutzung des Distributivgesetzes lässt sich auf diese Weise die folgende Multiplikationstabelle für die Elemente von $\mathbb{Z}^4_2$ finden.
|     | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | A   | B   | C   | D   | E   | F   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | A   | B   | C   | D   | E   | F   |
| 2   | 0   | 2   | 4   | 6   | 8   | A   | C   | E   | 3   | 1   | 7   | 5   | B   | 9   | F   | D   |
| 3   | 0   | 3   | 6   | 5   | C   | F   | A   | 9   | B   | 8   | D   | E   | 7   | 4   | 1   | 2   |
| 4   | 0   | 4   | 8   | C   | 3   | 7   | B   | F   | 6   | 2   | E   | A   | 5   | 1   | D   | 9   |
| 5   | 0   | 5   | A   | F   | 7   | 2   | D   | 8   | E   | B   | 4   | 1   | 9   | C   | 3   | 6   |
| 6   | 0   | 6   | C   | A   | B   | D   | 7   | 1   | 5   | 3   | 9   | F   | E   | 8   | 2   | 4   |
| 7   | 0   | 7   | E   | 9   | F   | 8   | 1   | 6   | D   | A   | 3   | 4   | 2   | 5   | C   | B   |
| 8   | 0   | 8   | 3   | B   | 6   | E   | 5   | D   | C   | 4   | F   | 7   | A   | 2   | 9   | 1   |
| 9   | 0   | 9   | 1   | 8   | 2   | B   | 3   | A   | 4   | D   | 5   | C   | 6   | F   | 7   | E   |
| A   | 0   | A   | 7   | D   | E   | 4   | 9   | 3   | F   | 5   | 8   | 2   | 1   | B   | 6   | C   |
| B   | 0   | B   | 5   | E   | A   | 1   | F   | 4   | 7   | C   | 2   | 9   | D   | 6   | 8   | 3   |
| C   | 0   | C   | B   | 7   | 5   | 9   | E   | 2   | A   | 6   | 1   | D   | F   | 3   | 4   | 8   |
| D   | 0   | D   | 9   | 4   | 1   | C   | 8   | 5   | 2   | F   | B   | 6   | 3   | E   | A   | 7   |
| E   | 0   | E   | F   | 1   | D   | 3   | 2   | C   | 9   | 7   | 6   | 8   | 4   | A   | B   | 5   |
| F   | 0   | F   | D   | 2   | 9   | 6   | 4   | B   | 1   | E   | C   | 3   | 8   | 7   | 5   | A   |

Das neutrale Element der Multiplikation ist das Polynom $1=(0,..., 0 ,1) = 0... 01$. Man beobachtet, dass in jeder Zeile (und ebenso in jeder Spalte) der Tabelle, außer der für das Nullpolynom, alle Elemente genau einmal vorkommen. Dies ist für jeden Körper F und jedes beliebige k so, und es folgt daraus, dass die Elemente der Menge $F^k-\{0\}$ ein Inverses haben.

Fakt: Wenn man die Multiplikation wie beschrieben definiert, mit einem irreduziblen Polynom f mit Leitkoeffizient $a_k=1$, dann gibt es für jedes Polynom $g\not=(0,...,0)$ vom Grad $<k$ (genau) ein Polynom h mit $g*h\ mod\ f=(0,...,0,1)=1$. Dieses Polynom h ist also $g^{-1}$, das multiplikative Inverse von g.

(Beweisidee: Man zeigt, dass die Abbildung $h\rightarrow g*h\ mod\ f$ in der Menge dieser Polynome injektiv ist. Ist $h_1*g\ mod\ f=h_2*g\ mod\ f$, so ist $(h_1-h_2)*g\ mod\ f= 0$, also ist $(h_1-h_2)*g$ durch f teilbar. Nach einem Lemma über irreduzible Polynome (analog zur Situation bei Primzahlen) folgt, dass f Teiler von $h_1-h_2$ oder Teiler von g sein muss. Weil $g$ nicht das Nullpolynom ist und Grad $<k$ hat, kann f kein Teiler von g sein. Also teilt f das Polynom $h_1-h_2$. Da auch dieses Grad $<k$ hat, muss $h_1-h_2$ das Nullpolynom sein, also $h_1=h_2$ gelten. Aus der Injektivität von $h\rightarrow g*h\ mod\ f$ folgt die Surjektivität, also gibt es ein $h$ mit $g*h\ mod\ f=1$.)

Weil die üblichen Rechenregeln in der Struktur $(F^k,\oplus,\odot,0,1)$ mit den angegebenen Operationen leicht nachzuweisen sind, bedeutet dies, dass wir einen Körper mit $|F|^k$ Elementen erhalten haben. Wir nennen ihn $F[X]/(f)$, für das gewählte irreduzible Polynom $f$ vom Grad $k$. Wenn $|F|^k=q$ ist, nennen wir diesen Körper $GF(q)$. Im Fall $F=\mathbb{Z}_2$ erhalten wir so Körper $GF(2^k)$, deren zugrunde liegende Menge einfach $\{0,1\}^k$ ist, die Menge der Bitstrings der Länge k.

Bemerkung: In der Algebra zeigt man folgende Fakten über endliche Körper:
- Es gibt einen endlichen Körper $GF(q)$ mit $q$ Elementen genau dann wenn $q=p^r$ für eine Primzahl p und einen Exponenten $r\geq 1$.
- Es ist gleichgültig, auf welchem Konstruktionsweg man zu einem Körper mit $q$ Elementen gelangt: alle diese Körper sind isomorph, also strukturell identisch. (Insbesondere ist der Körper $GF(2^k)$ immer ,,der gleiche'' , ganz egal welches irreduzible Polynom f man benutzt.) Die Tabellen für die Operationen können eventuell unterschiedlich aussehen, aber nur aufgrund von Umbenennungen von Objekten.

Ab hier schreiben wir $+$ für die Körperaddition und $*$ für die Körpermultiplikation.

Bemerkungen zur Zeit- und Platzeffizienz: Allgemein, und für beliebig große k, kann man für ein festes Polynom f den Rest der Division durch f stets als Produkt des Zeilenvektors, der $g*h$ darstellt, mit einer festen $((2k-1)\times k)$-Matrix $M_f$ erhalten.

Damit ist die Komplexität der Multiplikation in einem solchen Körper definiert: Es muss das Produkt $g*h$ berechnet werden (,,Konvolution'' von zwei Bitvektoren) und dann eine Vektor-Matrix-Multiplikation ausgeführt werden. Über dem Körper $\mathbb{Z}_2$ lässt sich die Vektor-Matrix-Multiplikation mit Hilfe der wortweisen XOR-Operation sehr effizient durchführen. Wenn zusätzlich $f$ nur wenige Terme hat, hat $M_f$ nur wenige 1-Einträge und die Matrix-Vektor-Multiplikation läuft auf einer Addition weniger Shifts eines Vektors hinaus. Für die Konvolution ist effiziente Ausführung etwas schwieriger; es gibt aber moderne Prozessoren, die diese Operation für konstante Wortlängen bereitstellen, was diese Operation auch für beliebige Wortlängen beschleunigt.

Wenn die Bitlänge $k$ kurz und bekannt ist, wird man Tabellen benutzen. (Zum Beispiel benutzt AES einen Körper der Größe 256.) Für die Multiplikation verwendet man auch gerne Potenz- und Logarithmentabellen.

Fakt 2.7 Sei F ein endlicher Körper mit $q$ Elementen. Dann gibt es in Fein ,,primitives Element'' g, d.h., g erfüllt $\{g^i| 0 \geq i < q-1\}=F-\{0\}$. (g ist erzeugendes Element der multiplikativen Gruppe von F.)

Beispiel: Wir hatten oben eine Multiplikationstabelle für $GF(2^4)$ aufgestellt. Mit ihrer Hilfe findet man leicht die ersten 15 Potenzenvon 2:
Potenztab elle:
| i              | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  | 13  | 14  |
| -------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $exp_2(i)=2^i$ | 1   | 2   | 4   | 8   | 3   | 6   | C   | B   | 5   | A   | 7   | E   | F   | D   | 9   |

Diese Potenzen sind alle verschieden, also ist $g=2$ primitives Element. Die entsprechende Logarithmentab elle sieht so aus:
| x          | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | A   | B   | C   | D   | E   | F   |
| ---------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $log_2(x)$ | 0   | 1   | 4   | 2   | 8   | 5   | 10  | 3   | 14  | 9   | 7   | 6   | 13  | 11  | 12  |

Achtung: Der Index der Exponential- und der Logarithmenfunktion ist nicht die natürliche Zahl 2, sondern 2, das ist das Element $X=0010$ von $GF(2^4)$.

Allgemein: Wenn $g$ primitives Element ist, dann betrachtet man die Exponentialfunktion zur Basis $g$: $exp_g:\mathbb{Z}\in i\rightarrow g^i\in F-\{0\}$.

Diese ist periodisch: Wenn $i-j$ durch $q-1$ teilbar ist, dann ist $g^i=g^j$. Es genügt also, die Werte $g^i$ für $0\geq i<q-1$ zukennen. Man erstellt eine Tabelle mit diesen $q-1$ Werten.
Die Umkehrfunktion ist die Logarithmusfunktion $log_g$ zur Basis $g$. Sie ordnet jedem $x\in F-\{0\}$ den (eindeutig bestimmten) Wert $i\in\{0,1,...,q-2\}$ mit $x=g^i$ zu, genannt $log_g(x)$. Es gilt $log_g(g^i)=i$ für $i\in\{0,1,...,q-2\}$ und $g^{log_g(x)}=x$ für alle $x\in F-\{0\}$. Man erstellt ebenfalls eine Tabelle mit diesen Werten. 
Nun kann man leicht multiplizieren.

Aufgabe: Berechne $z=x*y$.
Falls $x=0$ oder $y=0$ in $F$, ist $z=0$. Andernfalls schaue in die log-Tabelle, um $i=log_g(x)$ und $j=log_g(y)$ zu finden. Berechne $k=(i+j)\ mod\ (q-1)$. Das Ergebnis $z=g^k$ liest man nun in der exp-Tabelle an Stelle $k$ ab.

Beispiel: In $GF(2^4)$ seien $x=9$ und $y=C$ gegeben. Die $log_2$-Tabelle liefert $i=log_2(9)=14$ und $j=log_2(C)=6$. Wir erhalten $k= (14+6)\ mod\ 15 = 5$ und $z=g^5=6$ mit der $exp_2$-Tabelle. Man kontrolliert mit der Multiplikationstabelle für $GF(2^4)$, dass dort tatsächlich $9*C=6$ gilt.

Aufwand für eine Multiplikation: Drei Zugriffe auf Tabellen, eine modulare Addition!

Der Rechenaufwand für die Erstellung der Tabellen und auch ihr Platzbedarf ist $O(q)$ und damit akzeptabel, wenn $q$ nicht zu groß ist. Im Fall von $q=256$ hat man zwei Tabellen mit je $255$ Einträgen und kann damit sehr leicht in konstanter Zeit multiplizieren. Auch Tabellen für $q=2\frac{1}{6}=65536$ stellen weiter kein Problem dar. Für noch größere $q$ benötigt man weitere Tricks zum Ermitteln diskreter Logarithmen mit Hilfe von Tabellen der Größe etwa $\sqrt{q}$. (Wir werden später darauf zurückkommen.) Sollte $q$ sehr groß werden (Hunderte oder Tausende von Bits), wird man, wie oben skizziert, Konvolution und Matrix-Vektor-Multiplikation benutzen.

### AES: Advanced Encryption Standard
Der ,,Advanced Encryption Standard(AES)'' ist ein symmetrisches Verschlüsselungsverfahren (d.h., beide Kommunikationspartner benutzen denselben Schlüssel). AES wird in vielen Standardverfahren beider Kommunikation im Internet benutzt, zum Beispiel bei Secure Socket Layer (SSL)/Transport Layer Security (TLS) und bei Secure Shell (SSH). 

Die AES-Chiffren gehören in die Klasse der Substitutions-Permutations-Kryptosysteme, auch wenn es in Details Abweichungen von der in Abschnitt 2.1 vorgestellten Struktur gibt. Bei der standardisierten Version AES ist die Klartextlänge und Chiffretextlänge stets $l= 128$, die Schlüssellänge $128,192$ oder $256$ Bits. Wir konzentrieren uns auf die Variante mit Klartextlänge $128$, Schlüssellänge $128$. AES umfasst einige Spezialfälle der Rijndael-Familie von Chiffren, mit der Klartexte der Länge 128, 160,192, 224 oder 256 Bits ver- und entschlüsselt werden können.

In AES wird Arithmetik im Körper $GF(2^8)$ benutzt, dessen Elemente $8$-Bit-Vektoren, also Bytes, entsprechen.

Klartext und alle Zwischenergebnisse beider Ver- und Entschlüsselung sind Strings aus 128 Bits, die als 16 Wörter von 8 Bit Länge aufgefasst werden (1 Wort= 1 Byte= 2 Hexziffern). Die Bytes werden als Elemente von $GF(2^8)$ aufgefasst, konstruiert aus $\mathbb{Z}_2$ mit irreduziblem Polynom $f(X) =X^8 +X^4 +X^3 +X+ 1 (= (1, 0 , 0 , 0 , 1 , 1 , 0 , 1 ,1) )$.

Die 16 Bytes werden als $4\times 4$-Matrix (mit Einträgen aus $GF(2^8)=GF(256)$) aufgefasst. Die Leseanordnung ist dabei spaltenweise von links nach rechts, wobei Spalten von oben nach unten gelesen werden. Ein Bitstring $z\in\{0,1\}^{128}$ wird also in 16 Bytes $z^{(0)},z^{(1)},...,z^{(15)}$ mit $z=z^{(0)}z^{(1)}...z^{(15)}$ aufgeteilt und wie folgt als Matrix $A(z)\in(\{0,1\}^8)^{4\times 4}$ geschrieben: $A(z) =\begin{pmatrix} z^{(0)}& z^{(4)}& z^{(8)}& z^{(12)} \\ z^{(1)}& z^{(5)}& z^{(9)}& z^{(13)} \\ z^{(2)}& z^{(6)}& z^{(10)}& z^{(14)} \\ z^{(3)}& z^{(7)}& z^{(11)}& z^{(15)} \end{pmatrix}$.

Die Einträge einer solchen Matrix sind mit $0\geq i,j\geq 3$ indiziert, wie folgt: $A=\begin{pmatrix} A_{00}& A_{01}& A_{02}& A_{03}\\ A_{10}& A_{11}& A_{12}& A_{13}\\ A_{20}& A_{21}& A_{22}& A_{23}\\ A_{30}& A_{31}& A_{32}& A_{33}\end{pmatrix}$.

Aus jeder solchen Matrix ergibt sich durch spaltenweises Auslesen wieder ein Bitstring $A_{00} A_{10} A_{20} A_{30} A_{01} A_{11} A_{21} A_{31} A_{02} A_{12} A_{22} A_{32} A_{03} A_{13} A_{23} A_{33}$.

Abkürzungen für Zeilen und Spalten einer Matrix A: 
- Zeile $i: row_i(A)=(A_{i0},A_{i1},A_{i2} ,A_{i3})$, für $i=0,1,2,3$.
- Spalte $j:col_j(A)=\begin{pmatrix} A_{0j}\\ A_{1j}\\ A_{2j}\\ A_{3j} \end{pmatrix}$, für $j=0,1,2,3$.

Elementare Operationen auf Matrizen:
- Für Matrizen A und B in $GF(2^8)^{4\times 4}$ bedeutet $A\oplus B$ die komponentenweise Anwendung der Addition im Körper $GF(2^8)$. (Diese ist wiederum $\oplus_8$, die bitweise XOR-Operation auf Bytes.)
- Zyklischer Linksshift von Zeile i um $h=1,2,3$ Positionen:
  - $rotLeft_1((A_{i0}, A_{i1}, A_{i2}, A_{i3})) =(A_{i1}, A_{i2}, A_{i3}, A_{i0})$ usw.
  - Beispiel: $rotLeft_2((A1,06,4B,EF)) = (4B,EF,A1,06)$.
  - In AES wird Zeile i um i Positionen nach links rotiert. Die Abbildung ist also folgende: $\begin{pmatrix} A_{00}& A_{01}& A_ {02}& A_{03}\\ A_{10}& A_{11}& A_{12}& A_{13}\\ A_{20}& A_{21}& A_{22}& A_{23}\\ A_{30}& A_{31}& A_{32}& A_{33}\end{pmatrix} \rightarrow \begin{pmatrix} A_{00}& A_{01}& A_{02}& A_{03}\\ A_{11}& A_{12}& A_{13}& A_{10}\\ A_{22}& A_{23}& A_{20}& A_{21}\\ A_{33}& A_{30}& A_{31}& A_{32}\end{pmatrix}$
  - Diese Zeilenrotation ist eine Bitpermutation. Ihre Inverse besteht offenbar darin, Zeile i um i Positionen nach rechts zu rotieren. (Sie ist also nicht selbst invers)
- Zyklischer Shift von Spalte $j$ um $h=1,2,3$ Positionen nach oben: $rotUp_1((A_{0j},A_{1j},A_{2j},A_{3j})^T) = (A_{1j},A_{2j},A_{3j},A_{0j})^T$ usw. (Benötigt bei der Rundenschlüsselerzeugung.)
-  ,,Lineare Spaltendurchmischung'' 
  - $col_j(A) \rightarrow M*col_j(A)$, für $0\geq j\geq 3$, für die feste Matrix $M=\begin{pmatrix} 02& 03& 01& 01\\ 01& 02& 03& 01\\ 01& 01& 02& 03\\ 03& 01& 01& 02\end{pmatrix}\in GF(2^8)^{4\times 4}$.

Achtung: Gerechnet wird in $GF(2^8)$!

Beispiel: $M*\begin{pmatrix} 4F\\ B0\\ 3E\\ A0\end{pmatrix} = \begin{pmatrix} 02*4F\oplus 03*B0\oplus 01*3E\oplus 01*A0\\ ... \end{pmatrix} = \begin{pmatrix} 9E\oplus CB\oplus 3E\oplus A0 \\ ... \end{pmatrix} = \begin{pmatrix} CB\\...\end{pmatrix}$.
In AES werden einmal alle vier Spalten auf diese Weise transformiert. Dies kann man auch zu einer Matrixmultiplikation zusammenfassen: $A \rightarrow M*A$.

Diese Operation ,,vermischt'' die Einträge, ist aber keine Bitpermutation mehr, da Bits nicht nur vertauscht werden, sondern mit Körperoperationen verrechnet. Allerdings ist M invertierbar, sodass man die Operation auch wieder rückgängig machen kann, indem man mit $M^{-1}=\begin{pmatrix} 0E& 0B& 0D& 09\\ 09& 0E& 0B& 0D\\ 0D& 09& 0E& 0B\\ 0B& 0D& 09& 0E\end{pmatrix}$ multipliziert.
- Die S-Box von AES ist eine feste bijektive Abbildung $\{0,1\}^8\rightarrow {0,1}^8$. Der mathematische Hintergrund der S-Box wird weiter unten diskutiert.
- Rundenschlüssel: Aus Schlüssel $k\in\{0,1\}^{128}$ und Rundennummer r wird Rundenschlüssel $\kappa (k,r)\in\{0,1\}^{128}=(\{0,1\}^8)^{4\times 4}$ berechnet. Details hierzu folgen.

##### AES-Chiffrieralgorithmus
- X:128-Bit-Klartext, 
- k:128-Bit-Schlüssel)
- Umarrangiert: $X\in GF(2^8)^{4\times 4}$: Klartextmatrix; $k\in\{0,1\}^{128}$: Schlüssel.
1. Initialschritt (,,Weißschritt''):
    - $U\leftarrow X\oplus \kappa (k,0)$ // addiere Rundenschlüssel für Runde $r=0$, als 128-Bit-String.
2. Für $r=1,...,9$ tue
    1. Substitution: Anwendung der S-Box auf jedes Byte in U
        - $V_{ij}\leftarrow S(U_{ij})$, für $0\geq i,j\geq 3$;
    2. Zeilenrotation: i-te Zeile um i Positionen nach links
        - $row_i(W)\leftarrow rotLeft_i(row_i(V))$, für $0\geq i\geq 3$;
    3. Lineare Spalten durchmischung: M wie oben beschrieben
        - $Z\leftarrow M*W$, für $0\geq i\geq 3$;
    4. Schlüsseladdition: Rundenschlüssel für Runde r
        - $U\leftarrow Z\oplus \kappa (k,r)$ // komponentenweise Addition
3. Verkürzte Schlussrunde, $r=10$, keine Spaltendurchmischung:
    1. Substitution
        - $V_{ij}\leftarrow S(U_{ij})$, für $0\geq i,j\geq 3$;
    2. Zeilenrotation
        - $row_i(Z)\leftarrow rotLeft_i(row_i(V))$, für $0\geq i\geq 3$;
    3. Schlüsseladdition
        - $Y\leftarrow Z\oplus \kappa (k,10)$
4. Ausgabe: $Y\in GF(2^8)^{4\times 4}$, geschrieben als 128-Bit-Wort.

Abbildung 3: Die S-Box für AES. $S(z_1 z_0)$ für Hexziffern $z_1,z_0$ steht in Zeile $z_1$, Spalte $z_0$. Beispiel: $S(A4)=49$.
|     | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | A   | B   | C   | D   | E   | F   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 63  | 7C  | 77  | 7B  | F2  | 6B  | 6F  | C5  | 30  | 01  | 67  | 2B  | FE  | D7  | AB  | 76  |
| 1   | CA  | 82  | C9  | 7D  | FA  | 59  | 47  | F0  | AD  | D4  | A2  | AF  | 9C  | A4  | 72  | C0  |
| 2   | B7  | FD  | 93  | 26  | 36  | 3F  | F7  | CC  | 34  | A5  | E5  | F1  | 71  | D8  | 31  | 15  |
| 3   | 04  | C7  | 23  | C3  | 18  | 96  | 05  | 9A  | 07  | 12  | 80  | E2  | EB  | 27  | B2  | 75  |
| 4   | 09  | 83  | 2C  | 1A  | 1B  | 6E  | 5A  | A0  | 52  | 3B  | D6  | B3  | 29  | E3  | 2F  | 84  |
| 5   | 53  | D1  | 00  | ED  | 20  | FC  | B1  | 5B  | 6A  | CB  | BE  | 39  | 4A  | 4C  | 58  | CF  |
| 6   | D0  | EF  | AA  | FB  | 43  | 4D  | 33  | 85  | 45  | F9  | 02  | 7F  | 50  | 3C  | 9F  | A8  |
| 7   | 51  | A3  | 40  | 8F  | 92  | 9D  | 38  | F5  | BC  | B6  | DA  | 21  | 10  | FF  | F3  | D2  |
| 8   | CD  | 0C  | 13  | EC  | 5F  | 97  | 44  | 17  | C4  | A7  | 7E  | 3D  | 64  | 5D  | 19  | 73  |
| 9   | 60  | 81  | 4F  | DC  | 22  | 2A  | 90  | 88  | 46  | EE  | B8  | 14  | DE  | 5E  | 0B  | DB  |
| A   | E0  | 32  | 3A  | 0A  | 49  | 06  | 24  | 5C  | C2  | D3  | AC  | 62  | 91  | 95  | E4  | 79  |
| B   | E7  | C8  | 37  | 6D  | 8D  | D5  | 4E  | A9  | 6C  | 56  | F4  | EA  | 65  | 7A  | AE  | 08  |
| C   | BA  | 78  | 25  | 2E  | 1C  | A6  | B4  | C6  | E8  | DD  | 74  | 1F  | 4B  | BD  | 8B  | 8A  |
| D   | 70  | 3E  | B5  | 66  | 48  | 03  | F6  | 0E  | 61  | 35  | 57  | B9  | 86  | C1  | 1D  | 9E  |
| E   | E1  | F8  | 98  | 11  | 69  | D9  | 8E  | 94  | 9B  | 1E  | 87  | E9  | CE  | 55  | 28  | DF  |
| F   | 8C  | A1  | 89  | 0D  | BF  | E6  | 42  | 68  | 41  | 99  | 2D  | 0F  | B0  | 54  | BB  | 16  |

##### Die S-Box von AES:
Die S-Box ist als $16\times 16$-Tabelle gegeben, siehe Abb.3. Zur kompakten Darstellung wird ein Element $(a_7,a_6,a_5,a_4,a_3,a_2,a_1,a_0)$ von $GF(2^8)$ in zwei Hexziffern zerlegt: $(a_7,a_6,a_5,a_4)$ ist der Zeilenindex, $(a_3,a_2,a_1,a_0)$ der Spaltenindex der Position von $S((a_7,a_6,a_5,a_4,a_3,a_2,a_1,a_0))$.

Interessanterweise steckt hinter dieser chaotisch aussehenden Tabelle eine einfache Formel, die eine ,,nichtlineare'' Komponente in AES einbringt. Zu $x\in GF(2^8)$ betrachtet man $x^{-1}$, das multiplikative Inverse. Künstlich definiert man $00^{-1}:= 00$ (nur hier und nur für diesen Zweck). Weiter ist h eine invertierbare lineare Funktion auf dem $\mathbb{Z}_2$-Vektorraum $\{0,1\}^8$. Dazu werden die Elemente von $GF(2^8)$ als Spaltenvektoren aufgefasst, die 8 Bits enthalten.
$h((a_7,...,a_0))^T= $\begin{pmatrix} 1& 1& 1& 1& 1& 0& 0& 0\\ 0& 1& 1& 1& 1& 1& 0& 0\\ 0& 0& 1& 1& 1& 1& 1& 0\\ 0& 0& 0& 1& 1& 1& 1& 1\\ 1& 0& 0& 0& 1& 1& 1& 1\\ 1& 1& 0& 0& 0& 1& 1& 1\\ 1& 1& 1& 0& 0& 0& 1& 1\\ 1& 1& 1& 1& 0& 0& 0& 1\end{pmatrix} * \begin{pmatrix} a_7\\ a_6\\a_5\\a_4\\a_3\\a_2\\a_1\\a_0\end{pmatrix}$

Dann ist die S-Box wie folgt definiert: $S(x)=h(x^{-1})\oplus_8 63$.

Auch hinter der Matrix M, die im Teil ,,Lineare Spaltendurchmischung'' benutzt wird, steckt eine relativ einfache lineare Operation über einer passenden algebraischen Struktur.

Wir nehmen den endlichen Körper $\mathbb{F}_{2^8}=GF(2^8)$ als Ausgangssituation und betrachten Polynome $b_0+b_1X+b_2X^2+b_3X^3$ vom Grad maximal 3 über diesem Körper. Diese bilden die Grundmenge des Rings $\mathbb{F}_{2^8} [X]/(X^4+1)$: Addition wie gewöhnlich, Multiplikation modulo $X^4+1$. Ein solches Polynom wird durch den Spaltenvektor $(b_0,b_1,b_2,b_3)^T\in (F_{2^8})^4$ beschrieben. Wir multiplizieren dieses Polynom über $F_{2^8} [X]/(X^4+1)$ mit dem festen Polynom $c(X)=02+01*X+01*X^2+03*X^3$. (Da die Koeffizienten Elemente von $F_{2^8}$ sind, werden sie durch zwei Hexziffern dargestellt.) Der Koeffizientenvektor $(c_0,c_1,c_2,c_3)^T$ des Produktpolynoms bildet die transformierte Spalte. Man kann nachrechnen, dass sie sich als $M*(b_0,b_1,b_2,b_3)^T$ ergibt.

Die Rundenschlüssel werden mit einem iterativen Verfahren berechnet. Dabei wird zunächst Spalte 3 intensiv manipuliert und auf Spalte 0 addiert.

##### AES-Rundenschlüsselberechnung
$K_0 =\kappa (k,0)\leftarrow k$ //128-Bit-Schlüssel als $4\times 4$-Matrix

Für $r= 1,..., 10$ führe Runde r aus.
- Input: Rundenschlüssel $K_{r-1}$ als $4\times 4$-Matrix
- Output: Rundenschlüssel $K_r$ als $4\times 4$-Matrix
- Berechnung von Spalte 0:
    1. Rotation (analog zur Zeilenrotation): $U\leftarrow rotUp_1(col_3(K_{r-1}))$ //Spalte 3 zyklisch eine Position nach oben
    2. Substitution: $V_i\leftarrow S(U_i)$, für $0\geq i\geq 3$;
    3. Konstantenaddition: $V_0\leftarrow V_0+02^{r-1}$; //Potenz in $GF(2^8)$;
    4. Addition auf Spalte 0: $col_0(K_r)\leftarrow col_0(K_{r-1})+V$; //Vektoraddition;
- Berechnung von Spalten 1 bis 3:
  - Iterative Addition: für $i=1,2,3: col_i(K_r)\leftarrow col_i(K_{r-1})+col_{i-1}(K_r)$; //Vektoraddition;
- Ergebnis: $K_r=\kappa (k,r)$ für $r=0,1,...10$.

Entschlüsselung: 
Man geht nach dem schon diskutierten grundsätzlichen Ansatz bei Substitutions-Permutations-Kryptosystemen vor. Erst werden alle Rundenschlüssel berechnet. Diese werden in umgekehrter Reihenfolge benutzt. Für die Substitution wird stets die inverse S-Box $S^{-1}$ benutzt. Rotationen werden in umgekehrter Richtung ausgeführt. Die ,,lineare Spaltendurchmischung'' wird mit der zu $M$ inversen Matrix $M^{-1}$ ausgeführt. Ansonsten ist der Ablauf völlig analog der Verschlüsselung.

Aktuelle Lage: 
Bisher gilt AES als praktisch sicher (insbesondere die 192-Bit- und die 256-Bit-Variante), wenn auch nicht in dem im Folgenden zu besprechenden technischen Sinn. Es wurden einige Angriffe vorgeschlagen, die zu schnellerem ,,Brechen'' führen als dem vollständigen Durchsuchen des Schlüsselraums (nur noch 299 Schlüssel müssen getestet werden... ), aber dies führt nicht zu praktisch durchführbaren Verfahren.
