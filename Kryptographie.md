Literaturempfehlung:
- Ralf Küsters und Thomas Wilke: Moderne Kryptographie,Vieweg+ Teubner 2011
- Jonathan Katz und Yehuda Lindell, Introduction to Modern Cryptography,CRCPress, 2015
- Ulrike Baumann, Elke Franz, Andreas Pfitzmann,Kryptographische Systeme, SpringerVieweg 2014
- Albrecht Beutelspacher, Heike B. Neumann,Thomas Schwarzpaul: Kryptographie in Theorie und Praxis,Vieweg, 2005
- Douglas R. Stinson: Cryptography-Theory and Practice,CRC Press, 1995
- Dietmar Wätjen: Kryptographie, Spektrum Akademischer Verlag, 2004
- David Kahn: The Codebreakers, Scribner, 1996

# Einführung
`κρυ$\pi$τóς`= kryptos(griech.): verborgen
`γραφειν` = graphein (griech.): schreiben

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

Integrität bzw. Authentisierung: Hier ist die Aufgabenstellung verändert. Eva hat nicht nur die Fähigkeit, Nachrichten passiv mitzulesen, sondern sie kann in den Kommunikationskanal eingreifen. Sie kann Nachrichten abfangen(und sogar die Weiterleitungverhindern) und/oder eine neue bzw. veränderte Nachricht in den Kanal einspeisen. Ihre Absicht ist es,Bob dazu zu bringen, diese Nachricht für die echte von Alice abgeschickte Nachricht zu halten.Diese Art von Angriff soll verhindert werden. Hierfür verwendet man einen Mechanismus,der message authentication code (MAC) heißt. Darunter kann man sich eine Funktion vorstellen, die aus einer Nachricht x einen(nicht allzu langen) Code `mac=MAC(x)` berechnet. Diese Funktion ist ein Geheimnis von legitimen Sendern von Nachrichten an Bob. Insbesondere kann Eva bei gegebener Nachricht x′ (verwandt zu x oder nicht) keinen korrekten MAC für x′ berechnen. Bob verfügt über ein Prüfverfahren, das es ihm erlaubt, ein empfangenes Paar `(x,mac)` darauf zu testen, ob der zweite Teil der zu x gehörende MAC-Wert ist. Wenn Alice die einzige Instanz ist,die die geheime Funktion MAC kennt, dann kann Bob sogar überprüfen, ob Alice tatsächlich die Absenderin ist.

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

## Teil 1: Symmetrische Verschlüsselung, Sicherheitsmo delle
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

### Einmalige symmetrische Verschlüsselung und klassische Verfahren
Wir diskutieren hier eine einführende, einfache Situation, für symmetrische Konzelationssysteme und Sicherheitsmodelle. In einer Fallstudie betrachten wir Methoden zum ,,Brechen'' eines klassischen Kryptosystems.

#### Kryptosysteme und possibilistische Sicherheit
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

### Wiederholung: Elementare Wahrscheinlichkeitsrechnung
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

