---
titel: Algorithmen und Datenstrukturen
date: Sommersemester 2020
autor: Robert Jeutter
---
# 1. Vorbereitung
## 1.1. O-Notation


## 1.2. Spezifkationstechnik für Datentypen


## 1.3. Implementierungen fundamentaler Datentypen
- Wir werden Datentypen spezifizieren und Implementierungen betrachten. Ihnen sollten Stacks, Queues, Arrays und Lineare Listen bekannt sein. Wir benutzen diese als einfache Beispiele und um Techniken einzüben. Wörterbuch ist ein grundlegender Datentyp mit sehr vielen unterschiedlichen Implementierungsmöglichkeiten, insbesondere auf der Basis von Suchbäumen (verschiedene Varianten) und von Hashtabellen. Damit werden wir uns ausgiebig beschäftigen.
- Binäre Heaps sind eine Implementierung des Datentyps "Prioritätswarteschlange". (Man benutzt sie auch bei Heapsort, einem Sortieralgorithmus.)
- Wir werden eine Reihe von Algorithmen für Graphen sehen. Basis hierfür sind geeignete Datenstrukturen für die rechnerinterne Darstellung von Graphen. Die "Union-Find-Datenstruktur" ist ein Beispiel für einen Hilfsdatentyp für Graphalgorithmen.
- Ein fundamentales Thema der Vorlesung ist, dass man für (rechenzeit-)effziente Algorithmen clevere Datenstrukturen braucht und für effziente Datenstrukturen auch manchmal schlaue Algorithmen: Ein Wechselspiel!
- Mergesort und Quicksort sind schon bekannt. Hier werden Details der exakten Analyse nachgetragen.
- Bei Heapsort ist der Korrektheitsbeweis interessant, und die Anwendungen der Datenstruktur "Prioritätswarteschlangen".
- Breitensuche und Tiefensuche sind Methoden zur Exploration von Graphen, sehr großen Graphen, weit jenseits dessen, was man sich anschaulich machen kann. Denken Sie an zig Millionen von Knoten!
- Divide-and-Conquer: ein Algorithmenparadigma, das heißt, eine Entwurfsstrategie. Wir werden mehrere Entwurfsstrategien sehen, mit typischen klassischen Algorithmen, aber auch dem Potenzial, dass man selber Algorithmen nach dieser Methode entwirft.
- Greedy: Ein weiteres Algorithmenparadigma. Man konstruiert eine Lösung Schritt für Schritt, macht in jedem Schritt kurzsichtig "optimale" Entscheidungen, ohne an die Zukunft zu denken (daher "greedy/gierig"), und durch eine eingebaute Magie ergibt sich dann doch eine optimale Lösung. Manchmal, aber manchmal auch nicht. In die Kategorie greedy gehören extrem wichtige Graphalgorithmen, wie kürzeste Wege von einem Startknoten aus oder billigste Teilnetzwerke, die "alles verbinden" ...
- Dynamische Programmierung (DP) (Das hat mit Programmierung im modernen Sinn nichts zu tun.) Hier berechnen wir kürzeste Wege zwischen allen Knotenpaaren in einem Graphen oder die geringste Anzahl von Buchstabenoperationen, um aus einem String (z. B. "FREIZEIT") einen anderen zu machen (z. B. "ARBEIT").
- Schwierige Probleme (Rucksackproblem oder Traveling Salesperson Problem, beide NPvollständig) können durch DP-Algorithmen etwas schneller als ganz naiv gelöst werden.


## 1.4. Auswahlkriterien für elementare Datenstrukturen kennen und anwenden


## 1.5. Kenntnis grundlegender Entwurfsstrategien


## 1.6. Kenntnis grundlegender Algorithmen und ihrer Eigenschaften
- Sortieren: Mergesort, Quicksort, Heapsort
- Graphdurchläufe: Breitensuche, einfache Tiefensuche
- Volle Tiefensuche, starke Zusammenhangskomponenten
- Divide-and-Conquer: Multiplikation von ganzen Zahlen und von Matrizen, Auswahlproblem, Schnelle Fourier-Transformation (eventuell)
- Greedy-Ansatz: Kürzeste Wege, Human-Codes, Minimale Spannbäume, fraktionales Rucksackproblem
- Dynamische Programmierung: Kürzeste Wege, Editierdistanz, 0-1-Rucksackproblem

## 1.7. Auswahlkriterien für Algorithmen, insbesondere Ressourcenverbrauch, kennen und anwenden


## 1.8. Standard-Analysemethoden für Ressourcenverbrauch (Rechenzeit, Speicherplatz)


## 1.9. Korrektheitsbeweise für Algorithmen verstehen und darstellen


# 2. Einführung und Grundlagen
## 2.1. Beispiel: Sortieren
Beispiel Sortieren mit Insertion Sort (Sortieren durch Einfügen)
```pseudocode
for i from 2 to n do    // Runden i = 2,...,n
  x   A[i] ;            // entnehme A[i]
  j   i ;
  while j > 1 and* x.key < A[j-1].key do
    A[j]   A[j-1] ;     // Einträge größer als A[i] werden einzeln
    j   j-1 ;           // um 1 Position nach rechts verschoben
  A[j]   x ;            // Einfügen
  return A[1..n] .      // Ausgabe
```
- Die erste (unnummerierte) Zeile gibt den Namen und den Input an.
- (1)-(7): Eine for-Schleife, die für i = 2,...,n (in i) ausgeführt wird.
- (2), wenn i Wert i enthält: 
  - Datensatz ai (in A[i]) wird nach x kopiert, ist dort gesichert.
  - Speicherstelle A[i] ist jetzt frei verfügbar.
- (3)-(6): Diese Schleife durchläuft j=i, i-1, i-2;... und testet immer, ob der Schlüssel von A[j-1] größer ist als der Schlüssel von x. Falls ja: Verschiebe A[j-1] an Position j im Array.
  - "sequenzielles and" bedeutet, dass die zweite Bedingung nur ausgeführt wird, wenn die erste "wahr" ergibt.
  - Wenn also j=1 ist, stoppt die Schleife, ohne dass (fehlerhaft) auf A[0] zugegriffen wird.
- Wenn Zeile (7) erreicht wird, gibt j die Stelle an, an die x gespeichert werden muss.
- Ende des Algorithmus, Rückgabe des Arrays als Ausgabe.

### 2.1.1. Ist dieser Algorithmus Korrekt?
Die Frage nach der Korrektheit eines gegebenen bzw. soeben neu entworfenen Algorithmus wird uns durch die Vorlesung begleiten. 
Damit die Frage nach einem Beweis der Korrektheit überhaupt sinnvoll ist, müssen wir zunächst die zu lösende Aufgabe spezifizieren. 
Bemerkung: Aus einer vagen Problemstellung eine präzise Spezikation des zu lösenden Problems zu gewinnen ist ein in der Praxis extrem wichtiger Schritt, dessen Bedeutung oft unterschätzt wird.
Hier: Spezikationstechniken für grundlegende Algorithmen (und Datenstrukturen, siehe Kap. 2).
Ein Beispiel: Beim Sortieren gibt es das Konzept des "stabilen Sortierverfahrens": Objekte mit demselben Schlüssel ändern ihre relative Reihenfolge nicht. Wenn die Implementierung diese Eigenschaft nicht hat, der Kunde sie aber für seine Anwendung voraussetzt, weil Softwareingenieur/in und Kunde sich nicht präzise verständigt haben oder die Beschreibung des Programms nur sagt, dass es "sortiert", kann dies unangenehme Folgen haben. Auf präziser Spezikation zu bestehen und sie bereitzustellen liegt in der Verantwortung des
Informatikers/der Informatikerin! Man nennt dies "Stand der Technik" ("state of the art"), der angewendet werden muss.


### 2.1.2. Wie lange dauern Berechnungen mit diesem Algorithmus?
Die "Laufzeitanalyse" ist das zweite Grundthema in Richtung Algorithmen.
Erklärung: Ein Berechnungsproblem P besteht aus
1. einer Menge I von möglichen Eingaben ("Inputs","Instanzen") (I kann unendlich sein!)
2. einer Menge O von möglichen Ausgaben
3. einer Funktion $f:I \rightarrow O$
Ein Algorithmus A "löst P", wenn A genau die Eingaben aus I verarbeitet und zu Eingabe $x\in I$ Ausgabe $A(x) = f(x)$ liefert.
Spezialfall $O = {1,0} \approx {true,false} \approx {Ja,Nein}$ P heißt Entscheidungsproblem.
Bei der Festlegung, was Eingabemengen und Ausgabemengen eines Algorithmus sind, gibt es dieselben Unschärfen wie bei den Algorithmen selbst. Die Darstellungsform für den Input bleibt offen. Selbst wenn man weiß, dass die Schlüsselmenge die Menge N ist, ist nicht klar, ob eine Zahl in Dezimal- oder in Binärdarstellung gegeben ist. 
Beispiel: Beim Sortierproblem hat man es mit Objekten zu tun, die ein Attribut "Schlüssel" haben. Es muss eine Funktion geben, ja sogar ein algorithmisches Verfahren, das aus dem Objekt a den Schlüssel *key(a)* ermittelt. Die Details dieser Funktion werden aber nicht festgelegt.
Es ist nicht präzisiert, in welcher Weise die Funktion f beschrieben sein soll. Aus praktischen Gründen will man dies auch nicht. Mathematische Beschreibungen sind in der Regel akzeptabel. Wenn Ein-/Ausgabeformat ignoriert werden und man beliebige mathematische Funktionen f als Beschreibung akzeptiert, kann man eine Problemspezikation durchaus als ein mathematisches Tripel (I;O; f) schreiben.
Ein Entscheidungsproblem $(I, {true, false}, f)$ entspricht der Menge ${x\in I | f(x) = true}$.

## 2.2. Was ist ein Algorithmus
Ein Algorithmus A ist eine durch einen endlichen Text gegebene Verarbeitungsvorschrift, die zu jeder gegebenen Eingabe x aus einer Menge I
(der Menge der möglichen Eingaben) eindeutig eine Abfolge von auszuführenden Schritten ("Berechnung") angibt. Wenn diese Berechnung nach endlich vielen Schritten anhält, wird ein Ergebnis A(x) aus einer Menge O (der Menge der möglichen Ausgaben) ausgegeben.
Beschreibungsformen: Umgangssprache, Pseudocode, Programm in Programmiersprache, Programm fur formales Maschinenmodell, Programm in Maschinensprache, Turingmaschinenprogramm, . . .
Es handelt sich nicht um eine formale Definition. Viele Formalismen können benutzt werden, um das Algorithmenkonzept formal/mathematisch
zu erfassen: Turingmaschinenprogramme, while-Programme, Programme für andere (mathematisch genaue) Maschinenmodelle,... 
Man beweist, dass viele unterschiedliche Formalismen zu exakt derselben Klasse von "berechenbaren Funktionen" führt. Erfahrungstatsache: Alle bekannten Algorithmenkonzepte liefern dieselbe Klasse von "berechenbaren Funktionen". Die Church-Turing-These sagt, dass unsere informale, intuitive Beschreibung genau dem entspricht, was man mit diesen mathematischen Definitionen erfasst.

### 2.2.1. Was ist mit nicht abbrechenden Berechnungen?
Eine grundlegende Tatsache der Berechenbarkeitstheorie, nämlich die Unentscheidbarkeit des Halteproblems hat als unangenehme Konsequenz, dass Folgendes passiert: Wenn man der Denition des Algorithmenbegriffs die Aussage "A hält auf allen Inputs" hinzufügt, dann kann ein Compiler einen vorgelegten Programmtext P nicht mehr automatisch (d.h. mit einem Computerprogramm, d.h. mit einem Algorithmus) darauf überprüfen, ob P einen Algorithmus darstellt oder nicht. Das würde bedeuten, dass der Compiler entweder eigentlich legale Algorithmen zurückweist oder "Nicht-Algorithmen" passieren lässt.
Einen Algorithmenbegriff ohne Entscheidungsverfahren will man nicht haben. (Man möchte Programme aufgrund einer reinen Syntaxüberprüfung in korrekt/fehlerhaft einteilen.) Dies ist der Grund, weshalb Algorithmen mit nicht-stoppenden Berechnungen in Kauf genommen werden.

## 2.3. Merkmale eines Algorithmus
- Endlicher Text
- Ein Algorithmus für eine große (oft: unendliche!) Menge I von Eingaben x (Beachte: Zeitliche Trennung der Formulierung des Algorithmus bzw. der Programmierung und der Anwendung auf eine Eingabe.)
- Eindeutig vorgeschriebene Abfolge von Schritten, wenn Eingabe x vorliegt (im Rahmen des benutzten Modells)
- Wenn Verarbeitung anhält: Ausgabe $A(x)\in O$ ablesbar
- Nicht verlangt: Terminierung auf allen $x \in I$.

Algorithmen werden erfunden und in Software umgesetzt. Der Algorithmus, den Sie in Ihrer späteren Tätigkeit entwerfen und implementieren, wird (hoffentlich!) vieltausendfach verkauft und von Kunden eingesetzt, in Umgebungen und für Inputs, an die beim Algorithmenentwurf und bei der Implementierung niemand gedacht hat. Reales Beispiel: Bankensoftware, in den 1960er Jahren in COBOL geschrieben, wurde bis weit ins 21. Jh. eingesetzt, auf Rechnern, die es bei der Erstellung der Programme noch gar nicht gab. Diese Situation ist ein großer Reiz im Informatiker/innen dasein, aber auch eine Riesenverantwortung. Es muss genauestens spezifiziert sein, was genau ein Stück Software tut, und für welche Inputs es geeignet ist.
Je nach Modell oder Detaillierungsgrad des Algorithmus kann "eindeutig vorgeschriebene Abfolge von Schritten" unterschiedliche Dinge bedeuten. Beispiel: Man kann die Addition von natürlichen Zahlen als Elementaroperation ansehen oder die Details der Addition von Dezimalzahlen (Schulmethode) als Teil des Algorithmus betrachten. Nicht selten werden Algorithmen in einer Form beschrieben, die viele Details offen lässt. (Beispielsweise könnte es in einem Algorithmus ein Hilfsprogramm geben, das eine Folge sortiert. Der Algorithmus gilt oft auch dann als vollständig, wenn die verwendete Sortiermethode gar nicht fixiert ist.) 
Noch ein Wort zu Eingabe/Ausgabe: Vor der Verarbeitung durch einen Computer müssen Daten in eine interne Darstellung transformiert werden. Die Ausgabe eines Programms muss wieder in "reale" Daten übersetzt werden.

## 2.4. Erweiterung des Algorithmusbegriffs
- *Online-Algorithmen*: Die Eingabe wird nicht am Anfang der Berechnung, sondern nach und nach zur Verfügung gestellt, Ausgaben müssen nach Teileingabe erfolgen. Häufige Situation bei Datenstrukturen, Standard bei Betriebssystemen, Systemprogrammen, Anwendungsprogrammen mit Benutzerdialog usw.
- *Randomisierung*: Algorithmus führt Zufallsexperimente durch, keine Eindeutigkeit der Berechnung gegeben.
- *Verteilte Algorithmen*: Mehrere Rechner arbeiten zusammen, kommunizieren, zeitliche Abfolge nicht vorhersagbar


#### 2.4.0.1. Varianten
Zu einer Eingabe $x\in I$ könnte es mehrere legale Ergebnisse geben. Formal: In 3. haben wir statt einer Funktion f eine Relation $R\subseteq I \times O$ mit $\forall x \in I \exists y \in O: R(x, y)$. A löst P, wenn A genau die Eingaben aus I verarbeitet und $R(x,A(x))$ für jedes $x\in I$ gilt.
Beispiel "nicht-stabiles Sortieren": Beim Sortieren von Objekten/Datensätzen, wobei Schlüssel wiederholt vorkommen dürfen, kann jede sortierte Anordnung der Objekte eine legale Lösung sein. Dann ist die Lösung nicht eindeutig.
- Online-Situation: Eingabe wird "in Raten" geliefert, Zwischenausgaben werden verlangt.

#### 2.4.0.2. Spezikation des Sortierproblems
Parameter: Die Grundbereiche (Klassen), aus denen die zu sortierenden Objekte und die Schlüssel stammen:
- $(U,<)$: total geordnete Menge (endlich/unendlich, Elemente heißen "Schlüssel").
- Beispiele: Zahlenmengen ${1,...,n}, \N, \Z, \Q$ Mengen von Strings.
- D: Menge (Elemente heißen "Datensätze").
- key : $D \rightarrow U$ gibt zu jedem Datensatz einen "Sortierschlüssel" an.
- $I = O = Seq(D) := D^{<\infty} := U_{n\geq 0} D^n = {(a_1,...,a_n)|n\in \N, a_1,...,a_n \in D}$ (die Menge aller endlichen Folgen von Datensätzen)
Es ist häufiger der Fall als nicht, dass die zu verwendenden Grundbereiche bei einem Berechnungsproblem (oder einer Datenstruktur) als Parameter angegeben werden, die für eine konkrete Verwendung oder auch für eine konkrete Implementierung noch festgelegt werden müssen. Bei der objektorientierten Programmierung entspricht dies der Verwendung von "generischen Typen" (Java-Terminologie) oder Templates (C++-Terminologie).
Der Schlüssel $key(x)$ könnte ein simples Attribut $x:key$ des Objekts x sein, oder mit einer Methode aus x berechnet werden. In Beispielen lassen wir oft die Datensätze (fast) ganz weg und konzentrieren uns auf die Schlüssel. Dies ist bei realen Anwendungen fast nie so. (Sehr selten will man eine Liste von puren Zahlen sortieren, sondern man will meistens komplexere Datensätze nach ihnen zugeordneten Nummern sortieren.)
$D^n$ ist die Menge aller n-Tupel von Datensätzen. $D^0$ hat nur das Element $()$ (die leere Folge). $D^1$ hat als Elemente die Folgen $(a)$ für $a\in D$. Die Menge $Seq(D)$ erhält man, indem man alle diese Mengen zusammenwirft. Bitte die Notation $Seq(D)$ einprägen!

#### 2.4.0.3. Alternative Formulierung des Sortierproblems:
Die Ausgabe ist nicht die sortierte Folge, sondern die Permutation $\pi$, die die Eingabefolge in die richtige Reihenfolge bringt, wie oben beschrieben. $O' = {\pi | \pi Permutation einer Menge {1,...,n},n\in \N}$
Definition: $(a_1,...,a_n)$ wird durch $\pi$ sortiert: $\iff key(a_{\pi (1)}) \leq key(a_{\pi (2)}) \leq ... \leq key(a_{\pi (n)})$
$x = (a1,...,an)\in I$ und $\pi\in O$ stehen in der Relation $R'$, d.h.: $R'(x,\pi )$ gilt$:\iff x$ wird durch $\pi$ sortiert.Dann ist $(I,O',R')$ ebenfalls eine Spezikation des Sortierproblems.
Wir können nun präzise nach der Korrektheit eines Sortieralgorithmus fragen. Auch ein "Beweis der Korrektheit" eines Algorithmus ergibt nun einen Sinn. Die Korrektheitsbeweise dieser Vorlesung funktionieren alle "mathematisch". Es gibt auch maschinenbasierte Korrektheitsbeweise für Programme. Bei Algorithmen, deren Kern eine Schleife ist, verwendet man oft Beweise, die vollständige Induktion benutzen. Wir machen (vollständige) Induktion über $i= 1,...,n$, das heißt, es werden gar nicht alle natürlichen Zahlen betrachtet.
Den Beweis selbst muss man nicht beim ersten Lesen studieren, aber irgendwann doch. Er stellt an einem sehr einfachen Beispiel dar, wie man präzise über das Verhalten eines Algorithmus argumentieren kann, ohne die Formalismen zu übertreiben.

#### 2.4.0.4. Löst Insertionsort das Sortierproblem?
Gilt für jede Eingabe $(a_1,...,a_n)$ in $A[1..n]$, dass nach Ausführung von Insertionsort dieselben Elemente im Array stehen, aber nach Schlüsseln aufsteigend sortiert?
**Korrektheitsbeweis an Beispiel**: Durch vollständige Induktion über $i =1,2,...,n$ zeigt man die folgende (Induktions-)Behauptung:
Nach Durchlauf Nummer i (in i) der äußeren Schleife $(1)-(7)$ stehen in $A[1..i]$ dieselben Elemente wie am Anfang, aber aufsteigend sortiert. Nach Durchlauf Nummer n, also am Ende, gilt dann $(IB_n)$. Diese Behauptung sagt gerade, dass die Einträge aus der ursprünglichen Eingabe nun in aufsteigender Reihenfolge in $A[1..n]$ stehen.

**Korrektheitsbeweis für Insertionsort**
Zunächst erledigen wir zwei (triviale) Randfälle: Wenn n = 0 ist, also das Array leer ist, oder wenn n = 1 ist, es also nur einen Eintrag gibt, dann tut der Algorithmus gar nichts, und die Ausgabe ist korrekt.
Sei nun $n\geq 2$ beliebig, und der Input sei im Array $A[1..n]$ gegeben. Wir beweisen die Induktionsbehauptung $(IB_i)$ durch Induktion über $i=1,2,...,n$.
- I.A.: i = 1: "Nach Durchlauf für i = 1" ist vor Beginn. Anfangs ist das Teilarray $A[1..1]$ (nur ein Eintrag) sortiert, also gilt (IB1).
- I.V.: Wir nehmen an: $1 < i \leq n$ und $(IB_{i-1})$ gilt, d.h. $A[1..i - 1]$ ist sortiert, enthält dieselben Objekte wie am Anfang, und Schleifendurchlauf i beginnt.
- I.-Schritt: Betrachte Schleifendurchlauf i (Zeilen 2-7). 
  - $x := A[i]$ ist das aktuelle Objekt; es wird in Variable x kopiert.
  - Position $A[i]$ kann man sich jetzt als leer vorstellen.
  - Sei $m=m_i$ die größte Zahl in ${0,...,i-1}$, so dass $key(A[j]) \leq key(x)$ für $1\leq j \leq m$.
  - (Wenn es gar kein $j\leq i - 1$ mit $key(A[j]) \leq key(x)$ gibt, ist $m = 0$.
  - Wenn für alle $1\leq j \leq i - 1$ die Ungleichung erfüllt ist, ist $m = i - 1$.)
- Weil nach I.V. $A[1,..,i - 1]$ sortiert ist, gilt: $key(x) < key(A[j])$ für $m + 1 \geq j \geq i - 1$.
  Die innere Schleife 4-7 mit der Initialisierung in Zeile 3 testet, durch direkten Vergleich in Zeile 4, die Zahlen $j-1=i-1,i-2,i-3,...,0$ nacheinander darauf, ob $j-1 = m$ ist. Entweder wird dabei $j = 1$ erreicht, dann ist $m = 0 = j - 1$, oder man stellt für ein $j\geq 2$ fest, dass $key(A[j - 1]) \leq key(x)$ gilt. Dann ist offenbar ebenfalls $m = j - 1$.
- Schon während der Suche nach m werden (in Zeile 5) die Einträge $A[i-1],A[i-2],...,A[m+1]$, in dieser Reihenfolge, um eine Position nach rechts verschoben, ohne die Sortierung dieser Elemente zu ändern. Nun stehen $A[1],...,A[m]$ an ihrer ursprünglichen Position, $A[m+ 1],A[m+ 2],...,A[i-1]$ (vorher) stehen jetzt in $A[m + 2..i]$. In Zeile 7 wird x (aus x) an die Stelle $A[m+1]$ geschrieben. Nach den Feststellungen in den Boxen und aus der I.V. ergibt sich, dass nun $A[1..i]$ aufsteigend sortiert ist. Also gilt $(IB_i)$. Nach Durchlaufen der äußeren Schleife Schleife für $i=2,..,n$ gilt die Aussage $(IB_n)$, also ist nach Abschluss des Ablaufs das Array sortiert.

**Methoden für Korrektheitsbeweise**
- Vollständige Induktion: Damit wird die Korrektheit von Schleifen bewiesen. Meist ist dabei die Formulierung einer geeigneten Induktionsbehauptung zentral, die dann "Schleifeninvariante" genannt wird.
- Verallgemeinerte Induktion (d.h. man schließt von ($IB_j$) für alle $j<i$ auf ($IB_i$). Damit werden rekursive Prozeduren behandelt. (Siehe: Divide-and-Conquer.)
- Diskrete Mathematik: Ad-hoc-Beweise. (Beispiele bei Graphalgorithmen)

[//]: # (Kapitel 1 Seite 21)
### 2.4.1. Laufzeitanalysen 
Einen Algorithmus analysieren heißt, Kosten, Aufwand, "Rechenzeit" (synonym!) zu bestimmen oder zumindest abzuschätzen, die sich einstellt, wenn man eine Implementierung des Algorithmus A auf Eingabe x ablaufen lässt. Natürlich geht es schneller, kurze Arrays zu sortieren als lange. Daher ist ein zentraler Parameter einer solchen Analyse die Größe der Eingabe $x\in I$, bezeichnet mit $|x|$ oder $size(x)$ (oft, nicht immer: n). Die Bedeutung von $size(x)$ ist abhängig vom Problem P.
Beispiele: Beim Sortierproblem ist $size((a_1,...,a_n)) = n$. Wenn $x\in I$ ein String $a_1 ... a_n$ ist: $size(x) = n =$ #(Buchstaben in x). $I_n:={x\in I | size(x) = n}$ - "Größenklasse"

#### 2.4.1.1. Kosten Rechenzeiten
Kosten für Elementaroperationen in Programm: Addition, Vergleich, Test, Sprung, Zuweisung, Auswertung eines Attributs, Zeiger-/Indexauswertung
Jede Elementaroperation $op$ ist mit einer Konstanten $c_{op}$ bewertet, abhängig von Programmiersprache, Compiler, Prozessor, Hauptspeichertyp, Cachestruktur,...
Idee: $op$ benötigt höchstens "Zeit" $c_{op}$ (Takte oder ns oder $\mu$s oder ...). Unabhängig vom konkreten Input x.
Die Konstanten $c_{op}$ werden nie explizit genannt; vereinfachend oft sogar: $c_{op} = 1$ ("1 Maschinenschritt", "1 Operation").

In dieser Sichtweise ist es egal, ob für einen Vergleich $x<y$ von natürlichen Zahlen, die in eine Variable oder ein Register passen, spezielle Hardware zur Verfügung steht, oder ob die Differenz $x-y$ berechnet und dann mit 0 verglichen wird.
Die echten Kosten (der Zeitbedarf) einer Zuweisung $x\leftarrow y$ variieren je nachdem ob der Wert von x in einem Register oder einem Cacheregister steht oder aus dem Hauptspeicher geholt werden muss. Unsere Sichtweise ignoriert diese Unterschiede und Unwägbarkeiten und sagt nur: "auf jeden Fall nicht größer als eine Konstante $c_{Zuweisung}$.
Kontrast zu "konstant" wäre Folgendes: Wir rechnen mit sehr, sehr langen Binärzahlen, mit $n = size(x)$ Bits, wobei n in die Tausende oder in die Millionen geht. Bei solchen Zahlen ist es nicht angebracht, die Kosten einer Addition mit "konstant", unabhängig von x, anzusetzen.

Wir schreiben $O(1)$ für: "ein Wert, nicht größer als eine (von x unabhängige) Konstante c" und wollen Laufzeit des Algorithmus anhand von Pseudocode o.ä. analysieren. Technische Besonderheiten von konkreten Rechnern (Cachearchitekturen, Pipelining, Mehrkernprozessoren, Coprozessoren, ...), Implementierungen, Compileroptimierungen, usw. zu berücksichtigen wäre viel zu komplex!
Wir definieren als Kosten/Rechenzeit von Algorithmus $A$ auf Eingabe $x$: $t_A(x) :=$#(Operationen, die A auf Input x ausführt): (# bedeutet "Anzahl").

**Beispiel Insertionsort**
Wir benutzen $O(1)$, um eine nicht weiter beschriebene Konstante zu bezeichnen.
Die Notation $O(k)$ wird benutzt, zunächst im Sinn von "höchstens eine anonyme Konstante, $O(1)$, mal k".
Kosten von Zeilen $(1), (3), (7): n * O(1) = O(n)$
Zeilen $(4)(6)$ für ein festes $i$ (in i): Entscheidend: Anzahl der Tests in (4). Der Test "$j > 1$" wird zwischen 1-mal und i-mal durchgeführt, der Test $x.key < A[j-1].key$ zwischen 1-mal und $(i-1)$-mal, inputabhängig. Kosten für Zeilen $(4)(6)$ bei Schleifendurchlauf für $i: (k_i+1) * O(1) = O(k_i+1)$.
Kosten insgesamt: Summiere über $2\geq i\geq n = O(n+\sum_{2\geq i\geq n} k_i)$
Typisch für solche Analysen: Nicht jede Operation zählen, sondern Zurückziehen auf das Zählen von "charakteristischen Operationen", die den Rest bis auf einen konstanten Faktor dominieren. 

Definition $F_x = \sum_{2\geq i \geq n} k_i$
Anzahl der Fehlstände in $x=(a_1,...,a_n)$. Z.B. gibt es in $x=(4,7,5,3)$ vier Fehlstände: (1,4),(2,3),(2,4),(3,4). Gesmtaufwand von Insertionsort auf Eingabe x der Länge n ist $O(n+f_x)$

Welchen Wert $F_x$ sollte man für irgendein beliebiges x erwarten? aus $\sum_{0\geq i <n} (a+i*b) = a+ ... +(a+(n-1)b)$ errechnet man den Summenwert mit $n*m=\frac{1}{2}n(2a+ (n-1)b)$.
"Worst Case" (Schlechtester Fall): Gesamtaufwand für Insertionsort auf Inputs mit n Komponenten beträgt $O(n+\frac{n^2}{2})= O(n^2)$. Man schreibt: Worst-Case-Kosten sind $\Theta(n^2)$

##### 2.4.1.1.1. "Worst Case" Kosten allgemein
Sei A Algorithmus für Inputs aus I ($I_n = {x\in I | size(x) = n}$). Wir definieren worst-case-Kosten oder Kosten im schlechtesten Fall auf Inputs der Größe n: $T_A(n) := max\  {t_A(x) | x \in I_n}$. Wenn man betonen will, dass es um die worst-case-Kosten geht: $T_{A,worst}(n)$.
##### 2.4.1.1.2. "Best Case" Kosten allgemein
Wir denieren best-case-Kosten oder Kosten im besten Fall: $T_{A,best}(n) := min{t_A(x) | x\in I_n}$.
Beispiel Insertionsort: Eingabe schon aufsteigend sortiert $\rightarrow T_{IS,best}(n) = O(n+0) = O(n)$

##### 2.4.1.1.3. "Average Case" auf Insertionsort
Annahme: Jede der $n!$ möglichen Anordnungen der n Objekte in der Eingabe $(a_1,...,a_n)$ tritt mit derselben Wahrscheinlichkeit $\frac{1}{n!}$ auf. Bilde Mittelwert/Erwartungswert für $F_x=\sum_{2\geq i \geq n} k_i$ und berechne $E(F_x)= \frac{1}{2}* \binom{n}{2} = \frac{1}{2}* {\frac{n(n-1)}{2}= \frac{1}{4}n(n-1)}$

Erklärung: Wir betrachten der Einfachheit halber Inputs die aus den Zahlen $1,...,n$ bestehen. Dann ist jeder mögliche Input x einfach eine Permutation $(a_1,...,a_n)$ von ${1,...,n}$ und $I_n$ ist die Menge aller dieser Inputs. Es gibt $n!$ viele davon. Nun betrachten wir die Menge $P_n$ aller Paare $(x, (l,i))$ für x einen solchen Input und $1 \geq l \geq i \geq n$. Wir haben offenbar $|P_n| = n! *\binom{n}{2}$. Alle Fehlstände ergeben $|P^x_n|= \frac{1}{2}n! * \binom{n}{2}$. Durch Mittelung erhaöten wir die mittlere/erwartete Anzahl von Fehlständen in einem $x\in I_n$ als $E(F_x)= \frac{1}{n!}*\frac{1}{2}n! * \binom{n}{2}= \frac{1}{2} \binom{n}{2}= \frac{n(n-1)}{4}$. Also ist der Aufwand von Insertionsort im mittleren Fall auf Inputs der Länge n unter der Gleichverteilungsannahme:
$O(n^2)$, aber auch $\Omega (n^2)$, zusammengefasst $\Theta(n^2)$

##### 2.4.1.1.4. "Average Case" Kosten allgemein
Average-case-Kosten oder durchschnittliche Kosten: Gegeben sei, für jedes $n\in \N$ eine Wahrscheinlichkeitsverteilung $Pr_n$ auf $I_n$. D.h. für jedes $x \in I_n$ ist eine Wahrscheinlichkeit $Pr_n(x)$ festgelegt. Dann definieren wir: $T_{A,av}(n) := E(t_A)= \sum_{x\in I_n} Pr_n(x)*t_A(x)$. (E: Erwartungswert, berechnet mit $Pr_n$: Mittelwert).
Beispiel Insertionsort: $T_{IS,av}(n)=\Theta(n+\frac{1}{4}n(n-1)) = \Theta(n^2)$

#### 2.4.1.2. Analyse von Kosten/Rechenzeit
Selbst für feste Implementierung eines Algorithmus A auf fester Maschien und feste Eingabegröße $n=size(x)=|x|$ kann der Berechnungsaufwand auf verschiedenen Inputs sehr unterschiedlich sein. D.h. der Befriff "die Laufzeit des Algorithmus A auf Eingaben x vom Umfang $n=size(x)$ ist oft sinnlos. Sinnvoll sind schlechtester/bester Fall, eventuell durchschnittlicher Fall.
In allen drei Situationen: Konstante Faktoren ignorieren!



# 3. Fundamentale Datentypen und Datenstrukturen
Datentypen werden speziziert, sie geben (mathematisch exakt) ein Wunschverhalten einer Struktur an. Datenstrukturen sind Implementierungen von Datentypen.

## 3.1. Stacks und dynamische Arrays
(Aliasse: Keller, Stapel, LastInFirstOut-Speicher, Pushdown-Speicher)
Informale Beschreibung der Operationen; Vorstellung ist ein Stapel (Alltagsbegriff). Einträge: Elemente einer Menge D (Parameter).
- empty(): erzeuge leeren Stapel ("Konstruktor").
- push(s; x): lege Element $x\in D$ oben auf den Stapel s.
- pop(s): entferne oberstes Element von Stapel s (falls s leer: Fehler).
- top(s): gib oberstes Element des Stapels s aus (falls s leer: Fehler).
- isempty(s): Ausgabe "true" falls Stapel s leer, "false" sonst.
Eine Beschreibung in Umgangssprache und durch ein Beispiel genügt aber nicht. Um die Frage nach der Korrektheit einer Implementierung überhaupt sinnvoll stellen zu können, benötigen wir eine präzise Beschreibung des Verhaltens, also eine Spezikation.

### 3.1.1. Spezikation des Datentyps "Stack über D"
Namen von Sorten, Namen von Operationen mit Angabe der Namen der Argumentsorten und Resultatsorte für jede Operation. 
1. Signatur (Rein syntaktische Vorschriften! Verhalten (noch) ungeklärt)
  - Sorten:
    - Elements
    - Stacks
    - Boolean
  - Operationen
    - empty: $\rightarrow$ Stacks
    - push: Stacks X Elements $\rightarrow$ Stacks
    - pop: Stacks $\rightarrow$ Stacks
    - top: Stacks $\rightarrow$ Elements
    - isempty: Stacks $\rightarrow$ Boolean 

Um die Spezikation mit Inhalt zu füllen, muss erklärt werden, was die Namen "bedeuten" sollen, d.h. die Semantik muss beschrieben werden. Das mathematische Modell beschreibt ein eindeutig bestimmtes Verhalten der Operationen. Dieses Verhalten sollen korrekte Implementierungen dann nachbauen.

2. Mathematisches Modell (Sortennamen werden durch Mengen unterlegt)
  - Sorten:
    - Elements: Menge D, nichtleer (Parameter)
    - Stacks: $D^{<\infty} = Seq(D)$ mit $Seq(D)={(a_1,...,a_n)| n\in \N, a_1,...,a_n \in D}$
    - Boolean: {true,false} bzw {1,0}
  - Operationen:
    - $emtpy():= ()$
    - $push((a_1,...a_n),x):= (x,a_1,...a_n)$
    - $pop((a_1,...,a_n)):= \begin{cases} (a_2,...,a_n), falls n\geq 1 \\ undefiniert, falls (n = 0) \end{cases}$
    - $top((a_1,...,a_n)):= \begin{cases} a_1, falls n\geq 1 \\ undefiniert, falls (n = 0) \end{cases}$
    - $isemtpy((a_1,...,a_n)):= \begin{cases} false, falls n\geq 1 \\ true, falls (n = 0) \end{cases}$

Der Stack wird als Folge $(a_1,...a_n)$ mit $n\geq 0$ dargestellt. Das linke Ende der Folge, ELement $a_1$, steht im Stack oben. Die leere Folge () stellt den Stack dar.
Aus Operationsnamen wird durch Ersetzen der Sortennamen durch die Mengen, die den Sorten zugeordnet sind, die konkrete Signatir einer Funktion. Was die Funktion, die zu einem Operationsnamen gehört, tatsächlich macht, muss man (mathematisch Formuliert) hinschreiben.
Achtung bei emtpy: diese Funktion bekommt als Input eine leere Liste von Argumenten; als Ergebnis liefert sie das Tupel () der Länge 0.
Die Stapelfunktionalität ist durch die Beschreibung von push, top und pop gegeben. pop und top haben die Besonderheit bei einem leeren Stack mit Länge $n=0$ undefinierte Operation zu sein, also zu einem Fehler führen.

#### 3.1.1.1. Spezikation des Datentyps (ADT) "Stack über D" - Alternative
1. Signatur (wie oben)
2. Axiome $\forall$ s: Stacks, $\forall$ x: Elements
    - pop(push(s,x)) = s
    - top(push(s,x)) = x
    - isemtpy(empty()) = true
    - isemtpy(push(s,x)) = false

Vorteil: Zugänglich für automatisches Beweisen von Eigenschaften des Datentyps.
Nachteil: Finden eines geeigneten Axiomensystems für eine geplante Semantik evtl. nicht offensichtlich.

Die Methode, ADTs mit Axiomen zu spezifizieren, ist sehr effizient. Sie erleichtert Korrektheitsbeweise für Implementierungen, da man nur nachprüfen muss, dass die Implementierungen der Operationen, also die Methoden, die Axiome erfüllen. Das ist oft einfacher
als mit unserem mathematischen Modell. Auch automatische Korrektheitsbeweise für Implementierungen werden so ermöglicht. Bei Verwendung der Axiomen-Methode ist die zentrale Schwierigkeit, einen geeigneten vollständigen Satz von Axiomen zu finden.

#### 3.1.1.2. Implementierung von Stacks
Nun wollen wir ihn durch Algorithmen und am Ende durch ein Programm (z. B. in Java) realisieren. Diese algorithmische Realisierung erfolgt durch eine "Datenstruktur". Die Signatur gibt dabei den Plan vor. Aus Sorten werden Klassen. Die Elemente einer Sorte werden also durch Objekte der entsprechenden Klasse realisiert. Aus Operationen werden Methoden einer passenden Klasse. Die Operationen der Signatur sind alle öffentlich ("public"), also durch den Benutzer der Datenstruktur aufrufbar.
Die Klasse "Boolean" mit Konstanten true und false ist in Programmiersprachen eingebaut. Wir bauen eine Klasse für "Stacks". Diese muss (öffentliche) Methoden für empty (den Konstruktor, der ein neues Stackobjekt liefert), für push, top und pop anbieten.
Üblich: Ein Stack-Objekt wird der Methode nicht als Argument übergeben, die Methode wird für dieses Objekt aufgerufen. Daher fehlt das Stack-Objekt in der Parameterliste.
Grundsätzlich, in beliebiger objektorientierter Sprache: als Klasse mit Methoden. 
Prinzip: Kapselung (Information Hiding) $\rightarrow$ Der Benutzer sieht die Details der Implementierung nicht. Zugriff auf die Objekte der Datenstruktur erfolgt ausschließlich über die (öffentlichen) Methoden der Klassen, entsprechend den Operationen des Datentyps.
Zwei strukturell unterschiedliche Möglichkeiten (mindestens!) für Implementierung von Stackobjekten: (Einfach verkettete) Lineare Liste und Array.

##### 3.1.1.2.1. Listenimplementierung von Stacks
Ein Stack wird durch eine einfach verkettete Liste s dargestellt. Die Einträge stehen in der Liste in Reihenfolge $a_1,...a_n$. Zur Stack-Klasse gehören Methoden die den Operationen entsprechen:
- s.empty: Erzeugt neue leere Liste
- s.push(x): Setzte neuen Listenknoten mit Eintrag x an den Anfang der Liste
- s.pop: Entferne ersten Listenknoten (falls vorhanden). Für eine leere Liste muss eine Fehlermeldung aufgerufen werden
- s.top: Gib Inhalt des ersten Listenknotens aus (falls vorhanden, sonst Fehler)
- s.isempty: Falls Liste leer $\rightarrow$ Ausgabe "true", sonst "false"; Ausgabetyp Boolean

Beobachtung 1: Wenn der Benutzer nie den Fehler macht, pop oder top für den leeren Stack (die leere Liste) aufzurufen, dann ist der einzige Fehler, der bei der Benutzung dieser Implementierung auftreten kann, ein Speicherüberlauf bei der Operation s.push(x), weil für das neue Listenelement im für das Programm verfügbaren Speicher kein Platz mehr ist.

Beobachtung 2: Jede der Methoden hat Rechenzeit $O(1)$ (also konstant, unabhängig von n). Wir bemerken aber, dass in vielen Programmiersprachen die Aktion, ein neues Listenelement zu kreieren, wie es in s.push benötigt wird, eine deutlich größere (konstante) Rechenzeit erfordert als etwa ein einfacher Speicherzugriff oder der Zugriff auf den ersten Eintrag einer linearen Liste.
Eine Möglichkeit, diesen Effekt abzuschwächen, wäre es, von Zeit zu Zeit ein ganzes Array von Listenelementen auf einen Schlag zu allozieren und die Verwaltung der Listenelemente direkt, als Teil der Datenstruktur, durchzuführen. Spart Rechenzeit, erhöht aber den Programmieraufwand.

**Korrektheit der Listenimplementierung**
Eine beliebige Menge D sei gegeben. Wir betrachten eine Folge von Stackoperationen $Op_n$, wobei empty nur als $Op_0$ vorkommt. Wenn man die Operationen dieser Folge im mathematischen Modell der Reihe nach anwendet und es keine Fehler gibt entsteht die Folge $s_0,s_1,...,s_n$ von Stacks, die man als Zustände auffasst und eine Folge $z_0,z_1,...,z_n$ von Ausgaben (Werte in D bzw {true, false}).

Beispiel: $Op_i = pop(x)$ angewendet auf $s_{i-1} \in Seq(D)$ liefert $s_i=pop(s_{i-1})$.
Fehlerfall: Wenn $Op_i=top$ oder $Op_i=pop$ und $s_{i-1}=()$ oder wenn $s_{i-1}=$"Fehler" dann ist $s_i$ und $z_i$ ebenso "Fehler" (Keine
"Erholung" nach dem ersten Fehler!)

Eine Implementierung des Datentyps "Stack" heißt dann korrekt, wenn sie auf jede gegebene Operationenfolge als Eingabe genau dieselbe Ausgabefolge erzeugt wie das mathematische Modell. Ausnahme: Die Datenstruktur kann nicht für einen Speicherüberlauf verantwortlich gemacht werden.

**Beweis**: Man zeigt per Indukion über $i=0,...,N$ folgende Induktionsbehauptung für die Ausführung von $Op_0,Op_1,...Op_n$ als Schritte $0,...,N$: ($IB_i$) Wenn in Schritten $0,...,i$ im mathematischen Modell und in der Implementierung kein Fehler aufgetreten ist, dann sind die Einträge in der Liste genau die Einträge in $s_i$ und die Ausgabe der Datenstruktur in Schritt i ist $z_i$

##### 3.1.1.2.2. Arrayimplementierung von Stacks
Das Stackobjekt heißt s; es hat als Attribute einen Zeiger/eine Referenz auf ein Array $A[1...m]$ und eine Integervariable p ("Pegel").
Wenn der Stack im mathematischen Modell momentan $(a_1,...,a_n)$ ist, steht n in p und in $A[1]$ steht $a_n$ (unterster Eintrag); in $A[n]$ steht $a_1$ (oberster Eintrag).

- s.empty: wird durch einen Konstruktor realisiert. m als Parameter oder fix gewählt. Erzeuge neues Objekt s mit $A[1...m]$ elementen und p:int; $p \leftarrow 0;$
- s.push(x):
  if p=A.length then "Fehler"
  else p $\leftarrow$ p+1; $A[p] \leftarrow$ x
- s.pop:
  if p=0 then "Fehler"
  else p $\leftarrow$ p-1
- s.top:
  if p=0 then "Fehler"
  else return $A[p]$
- s.isempty
  if p=0 then return "true" else return "false"

Der wichtigste Punkt ist, dass das obere Ende des Stacks an der Position n (in p) in A sitzt, so dass die Operationen konstante Zeit benötigen. Es gibt eine neue Fehlermöglichkeit in der Implementierung: Das Array $A[1..m]$ ist voll, und es soll push(x) ausgeführt werden.

**Korrektheit der Arrayimplementierung**
Die Arrayimplementierung ist korrekt, d.h. sie erzeugt auf Eingabe $Op_0 = empty, Op_1,..., Op_N$ genau dieselbe Ausgabefolge wie das mathematische Modell, solange weder im mathematischen Modell ein Fehler (top oder pop auf leerem Stack) auftritt noch die Höhe des Stacks $s_i$ (d.h. die Länge der Folge $s_i$) die Arraygröße m überschreitet.

**Beweis $(IB_i)$**
Wenn in Schritten $0,...,i$ im mathematischen Modell kein Fehler aufgetreten ist und die Folge $s_1,...,s_i$ alle höchstens Länge m haben, dann gilt nach Schritt i:
- p enthält die Länge $n_i$ der Folge $s_i$ und
- $s_i = (A[n_i],...,A[1])$ und
- die Implementierung gibt in Schritt i genau $z_i$ aus.
D.h. $A[1...p]$ stellt genau $s_i$ in um gekehrter Reihenfolge dar.

**Zeitaufwand von Arrayimplementierung**
Bei der Initialisierung empty() (Aufruf des Konstruktors) muss man aber auf Folgendes achten: Wenn man m, die Arraygröße, vom Benutzer als Parameter angeben lässt (was sehr sinnvoll ist!), dann darf das Array $A[1...m]$ vom Konstruktor nur alloziert, nicht initialisiert werden. In C++ ist dies möglich. Andere Programmiersprachen wie etwa Java initialisieren ein neu angelegtes Array automatisch. In diesem Fall hat empty() natürlich Rechenzeit $\Theta(m)$. Man beobachte, dass die Korrektheit nicht beeinträchtigt wird, wenn das Array anfangs einen völlig beliebigen Inhalt hat.

Verdopplungsstrategie: In push(x): Bei Überlaufen des Arrays $A[1...m]$ (d. h. wenn der Pegelstand n gleich der Arraylänge m ist) nicht einen Laufzeitfehler (oder eine exception) generieren, sondern:
1. Ein neues, doppelt so großes Array $AA$ allozieren.
2. m Einträge aus $A[1...m]$ nach $AA[1...m]$ kopieren.
3. x an Stelle $n + 1$ schreiben, Pegel auf $n + 1$ setzen.
4. $AA$ in A umbenennen/Referenz umsetzen.
(Altes Array freigeben, falls in der Programmiersprache sinnvoll. (C++ ja, Java nein.)) Kosten: $\Theta(m)$, wo m = n = aktuelle Größe des Stacks.

**Analyse der Gesamtkosten bei Verdoppelungsstrategie**
Betrachte eine beliebige Operationenfolge$Op_0 = empty, Op_1,..., Op_N$. Arraygröße am Anfang: $m_0$ (Von Implementierung x gewählt oder vom Benutzer bestimmt). Jede Operation hat Kosten $O(1)$, außer wenn die Arraygröße verdoppelt wird. Die Arraygröße wächst erst von $m_0$ auf $2m_0$, dann von $2m_0$ auf $4m_0$ usw., allgemein:
> von $m_0*2^{l-1}$ auf $m_0*2^l$. Bei der l-ten Verdopplung entstehen Kosten $\Theta(m_0*2^{l-1})$.

k := Anzahl der push-Operationen in $Op_1,..., Op_N \Rightarrow$ Zahl der Einträge ist immer $geq$k, also gilt, wenn die Verdopplung von $m_0*2^{l-1}$ auf $m_0*2^l$ tatsächlich stattndet: $m_0*2^{l-1} < k$. Sei L maximal mit $m_0*2^{L-1} < k$. Dann sind die Gesamtkosten für alle Verdopplungen zusammen höchstens:
$$\sum_{1\leq i \leq L} O(m_0*2^{l-1})= O(m_0*(1+2+2^2+...+2^{L-1})) = O(m_0*2^L) = O(k)$$
Die Gesamtkosten für alle Verdopplungen zusammen sind also $N*\Theta(1)+O(k)=\Theta(N)$

Wenn ein Stack mit Arrays und der Verdoppelungsstrategie implementiert wird, gilt:
1. Die Gesamtkosten für N Operationen betragen $\Theta(N)$.
2. Der gesamte Platzbedarf ist $\Theta(k)$, wenn k die maximale je erreichte Stackhöhe ist.

##### 3.1.1.2.3. Vergleich Listen-/Arrayimplementierung
| Arrayimplementierung                                                               | Listenimplementierung                                         |
| ---------------------------------------------------------------------------------- | ------------------------------------------------------------- |
| $O(1)$ Kosten pro Operation, "amortisiert" (im Durchschnitt über alle Operationen) | $O(1)$ Kosten pro Operation im schlechtesten Fall             |
| Sequentieller, indexbasierter Zugriff im Speicher (cachefreundlich)                | (jedoch: relativ hohe Allokationskosten bei push-Operationen) |
| Höchstens 50% des allozierten Speicherplatzes bleibt ungenutzt                     | Zusätzlicher Platz für Zeiger benötigt.                       |

Experimente zeigen, dass die Arrayimplementierung spürbar kleinere Rechenzeiten aufweist.

Generelle Erkenntnis: Datentypen lassen sich ebenso exakt spezizieren wie Berechnungsprobleme.

#### 3.1.1.3. Datentyp "Dynamische Arrays"
Stacks + "wahlfreier Zugriff"

Neuer Grunddatentyp: Nat - durch $\N = {0,1,2,...}$ interpretiert.

Operationen, informal beschrieben:
- empty(): liefert leeres Array, Länge 0
- read(A; i): liefert Eintrag A[i] an Position i, falls $1\leq i \leq n$.
- write(A; i; x): ersetzt Eintrag A[i] an Position i durch x, falls $1 \leq i \leq n$.
- length(A): liefert aktuelle Länge n.
- addLast(A; x): verlängert Array um 1 Position, schreibt x an letzte Stelle (= push).
- removeLast(A): verkürzt Array um eine Position (= pop).

Wieso gibt es kein "isempty"? Überprüfung durch "length" zeigt ein leeres Array falls keine Einträge vorhanden

1. Signatur
  - Sorten: 
    - Elements
    - Arrays
    - Nat
  - Operationen
    - empty: -> Arrays
    - addLast: Array x Elements -> Arrays
    - removeLast: Arrays -> Arrays
    - read: Arrays x Nat -> Elements
    - write: Arrays x Nat x Elements -> Arrays
    - length: Arrays -> Nat
2. Mathematisches Modell
  - Sorten:
    - Elements: (nichtleere) Menge D (Parameter)
    - Arrays: Seq(D)
    - Nat: $\N$
  - Operationen:
    - emtpy():=()
    - addLast$((a_1,...,a_n),x):= (a_1,...,a_n,x)$
    - removeLast$((a_1,...,a_n)):= \begin{cases} (a_1,...,a_{n-1}), falls (n\geq 1) \\ undefiniert, falls (n=0) \end{cases}$
    - read$((a_1,...,a_n),i):= \begin{cases} a_i, falls (1\leq i \leq n) \\ undefiniert, sonst \end{cases}$
    - write$((a_1,...,a_n),i,x):= \begin{cases} (a_1,...,a_{i-1},x,a_{i+1},...,a_n), falls (1\leq i \leq n) \\ undefiniert, sonst \end{cases}$
    - length$((a_1,...,a_n)):= n$

**Implementierung**: Wir erweitern die Arrayimplementierung von Stacks in der offensichtlichen Weise, gleich mit Verdoppelungsstrategie.

**Kosten**:
- empty, read, write, length: O(1).
- addLast: k addLast-Operationen kosten Zeit O(k).
- removeLast: Einfache Version (Pegel dekrementieren): O(1).

## 3.2. Queues (Warteschlangen, FIFO-Listen)
(First-in-First-Out Listen) Stacks und Queues verhalten sich sehr unterschiedlich
- "enqueue": Man fügt ein Element ein, indem man hinten an die Kette anhängt.
- "dequeue": Man entnimmt ein Element am vorderen Ende der Kette.
- "first": Man kann den vordersten Eintrag auch lesen.

### 3.2.1. Spezifikation des Datentypes "Queue" über D
Die Signatur ist identisch zur Signatur von Stacks (bis auf Umbenennungen). Rein syntaktische Vorschriften!
1. Signaur
  - Sorten:
    - Elements
    - Queues
    - Boolean
  - Operationen:
    - empty: -> Queues
    - enqueue: Queues x Elements -> Queues
    - dequeue: Queues -> Queues
    - first: Queues -> Elements
    - isemtpy: Queues -> Boolean
2. Mathematisches Modell
  - Sorten:
    - Elements: (ncihtleere) Menge D (Parameter)
    - Queues: Seq(D)
    - Boolean: {true, false}
  - Operationen:
    - empty():=()
    - enqueue$((a_1,...,a_n),x):= (a_1,...,a_n,x)$
    - dequeue$((a_1,...,a_n)):= \begin{cases} (a_2,...,a_n), falls (n\geq 1)\\ undefiniert, falls (n=0) \end{cases}$
    - first$((a_1,...,a_n)):= \begin{cases} a_1, falls (n\geq 1)\\ undefiniert, falls (n=0) \end{cases}$
    - isemtpy$((a_1,...,a_n)):= \begin{cases} false, falls (n\geq 1)\\ true, falls (n=0) \end{cases}$


Die leere Folge () stellt die leere Warteschlange dar.
Das mathematische Modell ist fast identisch zu dem für Stacks. Nur fügt enqueue(x) das Element x hinten an die Folge an, während push(x) das Element x vorne anfügt.

### 3.2.2. Implementierung von Queues
**Listenimplementierung**
Implementierung mittels einfach verketteter Listen mit Listenendezeiger/-referenz. Bei der Verwendung von Listen ist zu beachten, dass man mittels Zeigern/Referenzen Zugang zu beiden Enden der Liste benötigt: mit einem "head"-Zeiger hat man Zugriff auf den Anfang, mit
einem "tail"-Zeiger Zugriff auf das Ende.

**Arrayimplementierung**

##### 3.2.2.0.1. TODO ##########################################################################################################################
!TODO seite 40(394)
#####################################################################################################################################



# 4. Binärbaume
## 4.1. Grundlagen
## 4.2. Definition
Ein Binärbaum T besteht aus einer endlichen Menge V von "inneren" Knoten, einer dazu disjunkten endlichen Menge L von "äußeren" Knoten sowie einer injektiven Funktion

D sei Menge von (möglichen) Knotenmarkierungen, Z sei Menge von (möglichen) Blattmarkierungen:
1. Wenn $z \in \Z$ dann ist (z) ein (D,Z)-Binärbaum
2. Wenn $T_1, T_2$ (D,Z)-Binärbaume sind und $x \in D$ ist, dann ist auch $(T_1,x,T_2)$ ein (D,Z)-Binärbaum
3. nichts sonst ist (D,Z)-Binärbaum

## 4.3. Operationen
1. Signatur
  - Sorten: 
    - Elements
    - Bintrees
    - Boolean
  - Operationen
    - empty: -> Bintrees
    - buildTree: Elements x Bintrees x Bintrees -> Bintrees
    - leftSubtree: Bintrees -> Bintrees
    - rightSubtree: Bintrees -> Bintrees
    - data: Bintrees -> Elements
    - isemtpy: Bintrees -> Boolean
2. mathematisches Modell
  - Sorten:
    - Elements: (nichtleere) Menge D
    - Bintrees: {T | T ist (d,{-})-Binärbaum}
    - Boolean: {true, false}
  - Operationen:
    - empty():= {}:= (-)
    - $buildTree(x,T_1,T_2) := (T_1,x,T_2)$
    - $leftSubtree(T) := \begin{cases} T_1, falls\ T=(T_1,x,T_2) \\ undefiniert, falls\ T=(-) \end{cases}$
    - $rightSubtree(T) := \begin{cases} T_2, falls\ T=(T_1,x,T_2) \\ undefiniert, falls\ T=(-) \end{cases}$
    - $data(T) := \begin{cases} x, falls\  T=(T_1,x,T_2) \\ undefiniert, falls\ T=(-) \end{cases}$
    - $isempty(T) := \begin{cases} false, falls\  T=(T_1,x,T_2) \\ true, falls\ T=(-) \end{cases}$

## 4.4. Terminologie
- Binärbaum T, engl: "binary tree"
- Wurzel, engl "root"
- (innerer) Knoten v, engl: "node"
- (äußerer) Knoten l = Blatt, engl: "leaf"
- Blatteintrag: z= data(l)
- Knoteneintrag: $x = data(v) = data(T_0)$
- $T_v$: Unterbaum mit Wurzel v
- Vater/Vorgänger, engl: "parent", von v: p(v)
  - linkes Kind, engl: "left child", von v: von v: child(v, left)
  - rechtes Kind, engl: "right child", von v: von v: child(v, right)
  - Vorfahr (Vater von Vater von Vater . . . von u), engl: "ancestor"
  - Nachfahr (Kind von Kind von . . . von v), engl: "descendant"
- Weg in T: Knotenfolge oder Kantenfolge, die von v zu einem Nachfahren u führt
- Länge eines Wegs $(v_0,v_1,...,v_s)$: Anzahl s der Kanten auf dem Weg
- Tiefe/Level eines Knotens: Die Länge (das ist die Kantenzahl) des Wegs von der Wurzel zum Knoten heißt die Tiefe oder das Level $d(v)$ von Knoten v. Die Knoten mit Tiefe l bilden das Level l.
- 

## 4.5. TIPL und TEPL
### 4.5.1. Totale innere Weglänge (Total internal path length)
TIPL(T) = Anzahl der Knoten * Tiefe der Knoten

Mittlere innere Weglänge: $\frac{1}{n}* TIPL(T) > log(n - 2)$

### 4.5.2. Totale äußere Weglänge (Total external path length)
TEPL(T) = Anzahl der Blätter * Tiefe der Blätter

Mittlere äußere Weglänge: $\frac{TEPL(T)}{n+1} \geq log(N)$

TEPL(T) = TIPL(T) +2n

## 4.6. Baumdurchläufe
(D,Z)-Binärbäume kann man systematisch durchlaufen, die Knoten nacheinander besuchen und (anwendungsabhängige) Aktionen an den Knoten ausführen. Abstrakt gefasst: visit-Operation.
Organisiere data-Teil der Knoten als Objekte einer Klasse; visit(T) löst Abarbeitung einer Methode von data(T) aus.
 
### 4.6.1. Inorder Durchlauf
>"Erst den linken Unterbaum, dann die Wurzel, dann den rechten Unterbaum"

Bsp: falls $T=(T_1,x,T_2)$
  - Inorder Durchlauf durch $T_1$
  - i-visit(x)
  - Inorder Durchlauf durch $T_2$

Man besucht abwechselnd externe und interne Knoten.

### 4.6.2. Präorder Durchlauf
> "Erst die Wurzel, dann den linken Unterbaum, dann den rechten Unterbaum"

Bsp: falls $T=(T_1,x,T_2)$
  - i-visit(x)
  - Inorder Durchlauf durch $T_1$
  - Inorder Durchlauf durch $T_2$

### 4.6.3. Postorder Durchlauf
> "Erst den linken Unterbaum, dann den rechten Unterbaum, zuletzt die Wurzel"
Bsp: falls $T=(T_1,x,T_2)$
  - Inorder Durchlauf durch $T_1$
  - Inorder Durchlauf durch $T_2$
  - i-visit(x)

### 4.6.4. Kombi Durchlauf
Ermöglicht Datentransport von der Wurzel nach unten in den Baum hinein und wieder zurück.
Bsp: falls $T=(T_1,x,T_2)$
  - preord-i-visit(x)
  - Kombi Durchlauf durch $T_1$
  - inord-i-visit(x)
  - Kombi Durchlauf durch $T_2$
  - postord-i-visit(x)

### 4.6.5. Zeitanalyse für Baumdurchlauf
Die Baumdurchläufe können mittels rekursiver Prozeduren implementiert werden.

Beispiel: Inorder Durchlauf
  - Angewendet auf einen Baum T mit n inneren Knoten
  - Für jeden inneren und äußeren Knoten wird die Prozedur inorder() einmal aufgerufen, insgesamt $(2n+1)$-mal
  - Kosten pro Aufrug $O(1)$ plus Kosten für i-visit/e-visit-Operation
  - Insgesamt: $(2n+1)*(O(1)| +C_{visit})$ wobei $C_{visit}$ eine Schranke für die Kosten der visit-Operationen ist

Behauptung: Baumdurchläufe haben lineare Laufzeit.

# 5. Hashverfahren
Gegeben: Universum U (auch ohne Ordnung) und Wertebereich R. Hashverfahren (oder Schlüsseltransformationsverfahren) implementieren ein Wörterbuch (alias dynamische Abbildung, assoziatives Array) $f: S \rightarrow R$, mit $S \subseteq U$ endlich.

Ziel: Zeit $O(1)$ pro Operation "im Durchschnitt" unabhängig vom Umfang der Datenstruktur

Grundansatz: "x wird in h(x) umgewandelt/transformiert" (Ideal: Speichere Paar (x, f(x)) in Zelle T[h(x)] )

Eine Funktion $h: U \rightarrow [m]$ heißt Hashfunktion. Wenn $S \subseteq U$ gegeben ist, verteilt h die Schlüssel in S auf $[m]$. $B_j := {x \in S | h(x) = j}$ heißt Behälter ("bucket").
$h$ perfekt (ideal) für S falls $h$ zu S injektiv, d.h. gür jedes $j \in [m]$ existiert höchstens ein $x \in S$ mit $h(x) = j$.

**Uniformitätsannahme** (UF): Werte $h(x_1),...,h(x_n)$ in $[m]$ sind "rein zufällig": Jeder der $m^n$ Vektoren $(j_1,...,j_n)\in [m]^n$ kommt mit derselben Wahrscheinlichkeit $1/m^n$ als $(h(x_1),...,h(x_n))$ vor. UF tritt (näherungsweise) ein, wenn:
  - U endlich ist und
  - h das Universum in gleich große Teile zerlegt ($|h^{-1}({j}) = \lfloor |U|/m \rfloor$ oder $\lceil |U|/m \rceil$ )
  - $S \subseteq U$ eine rein zufällige Menge der Größe n ist
Pr(keine Kollision)=Pr(injektiv auf S) $< e^{-\frac{n(n-1)}{2m}}$

"Geburtsparadoxon": $x_1,...,x_n$ sind Leute und $h(x_1),...,h(x_n) \in [m]$ die Nummern ihrer Geburtstage im Jahr, $m=365$. Wenn z.B. $n=23$ ist, ist Pr(alle Geburtstage verschieden)$< e^{-\frac{23*22}{365*2}} = e^{\frac{-506}{730}} < 0,5$.
Mit Wahrscheinlichkeit >1/2 sind unter 23 Personen mit zufälligen Geburtstagen zwei, die am selben Tag Geburtstag haben.

Wunsch: Linearer Platzverbrauch, also "Auslastungsfaktor" $\alpha := \frac{n}{m}$ nicht kleiner als eine Konstante $\alpha_0$. Dann: Pr(h injektiv auf S)$\leq e^{-\alpha_0(n-1)/2}$. D.h. falls h nicht auf S abgestimmt ist, kommen Kollisionen praktisch immer vor! $\rightarrow$ Kollisionsbehandlung ist notwendig.

## 5.1. Hashing mit Verketteten Listen
engl.: chained hashing

Auch: "offenes Hashing", weil man Platz außerhalb von T benutzt. In $T[0... m-1]$: Zeiger auf die Anfänge von m einfach verketteten linearen Listen $L_0,...,L_{m-1}$. (Oder auch: Zeiger auf "kleine" Arrays/Vektoren mit variabler Länge.) Liste $L_j$ enthält die Einträge mit Schlüsseln x aus Behälter/Bucket: $B_j={x\in S | h(x) = j}$

### 5.1.1. Wir implementieren die Wörterbuchoperationen: Algorithmen
- empty(x)
  - Erzeugt Array $T[0...m-1]$ mit m NULL-Zeigern/NULL-Referenzen und legt $h:U\rightarrow [m]$ fest.
  - Kosten: $\Theta(m)$
  - Beachte: Man wählt h, ohne S zu **kennen**
- lookup(x)
  - Berechne $j=h(x)$ suche Schlüssel x durch Durchlaufen der Liste $L_j$ bei $T[j]$; falls Eintrag gefunden: $return R$; sonst: $return "nicht vorhanden"$
  - Kosten/Zeit: O(1+ Zahl der Schlüsselvergleiche "x=y?"); Erfolglose Suche exakt $|B_j|$; Erfolgreiche Suche höchstens $|B_j|$
- insert(x,r)
  - Berechne $J=h(x)$ suche Schlüssel x in Liste $L_j$ bei $T[j]$; falls gefunden ersetze Daten bei x durch r
  - Kosten: wie bei lookup
- delete(x)
  - Berechne $J=h(x)$, suche Schlüssel x in Liste $L_j$ bei $T[j]$; falls gefunden lösche Eintrag $(x,f(x))$ aus $L_j$
  - Kosten: wie bei lookup

Ziel: analysiere erwartete Kosten für lookup, insert, delete. Hierfür genügt Analyse erwarteter Anzahl der Schlüsselvergleiche.
- Pr(A): Wahrscheinlichkeit für Ereignis A
- E(X): Erwartungswert der Zufallsvariablen X
- abgeschwächte "Uniformitätsannahme": Für je 2 Schlüssel $x \not = z$ in U gilt: $Pr(h(x)=h(z)\leq \frac{1}{m})$

### 5.1.2. Verdoppelungsstrategie
Wenn nach $insert(x, r)$ (mit x neu) der Wert load die Grenze $a_1m$ überschreitet:
- Erzeuge neue Tabelle $T_{neu}$ der Größe $2m$.
- Erzeuge neue Hashfunktion $h_{neu}:U \rightarrow [2m]$.
- Übertrage Einträge aus den alten Listen in neue Listen zu Tabelle $T_{neu}$, gemäß neuer Hashfunktion. Dabei Einfügen am Listenanfang ohne Suchen. (Wissen: Alle Schlüssel sind verschieden!) Kosten: O(m) im schlechtesten Fall.
- Benenne $T_{neu}$ in $T$ und $h_{neu}$ in $h$ um.

## 5.2. Hashfunktionen
### 5.2.1. Einfache Hashfunktionen
Kriterien für Qualität:
1. Zeit für Auswertung von $h(x)$ (Schnell!) entscheidend: Schlüsselformat
2. Wahrscheinlichkeit für Kollisionen (unter "realistischen Annahmen" über Schlüsselmenge S). (Klein, am besten $\leq c=m$ für c konstant.)

#### 5.2.1.1. Fall: Schlüssel sind natürliche Zahlen: $U \subseteq \N$
##### 5.2.1.1.1. Divisionsrestmethode
$h(x)= x\ mod\ x$ Sehr einfach, recht effzient.
Nachteile:
- Unflexibel: Nur eine feste Funktion für eine Tabellengröße.
- Bei strukturierten Schlüsselmengen (z. B. aus Strings übersetzte Schlüssel) deutlich erhöhtes Kollisionsrisiko.

##### 5.2.1.1.2. Diskrete Multiplikationsmethode
$U=[2^k]$ und $m=2^l$. $h_a(x)=(ax\ mod\ 2^k)div 2^{k-l}$
mit $a\in[2^k]$ ungerade und z.B. $\frac{a}{2^k} \approx \frac{1}{2}(\sqrt{5} -1 ) = 0,618...$
Oder: $a\in [2^k]$ ungerade, zufällig. Sehr effziente Auswertung ohne Division.

#### 5.2.1.2. Fall: Schlüssel sind Strings/Wörter: $U \subseteq Seq(\sum)$
$\sum$:"Alphabet" (endliche nichtleere Menge). $Seq(\sum)$: Menge aller endlichen Folgen von Elementen von $\sum$:"Wörter über $\sum$".
- Kollisionen $n(x) = n(y)$ nie auflösbar!
- Selbst wenn n injektiv: Ineffziente Auswertung von $h(^x)$.
##### 5.2.1.2.1. Lineare Funktionen über Körper $\Z_p = [p] = {0,...,p-1}$
$\sum \subseteq [p]$ für p Primzahl, $m = p$. (Beispiel: ISO-8859-1 $b= [256] \subseteq [p] = [1009]$)
Wähle Koeffzienten $a_1, ..., a_r \in [p]$ mit $h(c_1...c_r)=(\sum_{i=1}^r a_i*c_i) mod\ p$
Vorteile:
- Rechnung nur mit Zahlen $< p_2 = m_2$ (wenn man nach jeder Multiplikation/Addition Rest modulo p bildet);
- sehr effzient;
- theoretisch nachweisbares gutes Verhalten, wenn $a_1,...,a_r$ aus $[p]$ zufällig gewählt werden.

### 5.2.2. Anspruchsvolle Hashfunktionen
Qualitätskriterien:
1. Zeit für Auswertung von $h(x)$ (klein!)
2. geringe Wahrscheinlichkeit für Kollisionen ohne Annahmen über die Schlüsselmenge S (ähnlich der zufälligen Situation!)
3. Effiientes Generieren einer neuen Hashfunktion (benötigt z.B. bei der Verdoppelungsstrategie)
4. Platzbedarf für die Speicherung von h (Programmtext, Parameter) (gering gegenüber n!)

Universelles Hashing (Idee): Bei der Festlegung der Hashfunktion h wird (kontrolliert) Zufall eingesetzt ("Randomisierter Algorithmus"). (Bei Programmierung: "Pseudozufallszahlengenerator", in jeder Prog.-Sprache bereitgestellt.) Analyse beruht auf dadurch vom Algorithmus erzwungenen Zufallseigenschaften von h.

$a_1,...,a_r$ seien (uniform) zufällig gewählt aus $[p]$. Definiere $h(c_1...c_r)=(a_1*c_1+...+a_r*c_r)mod\ p$. Es gilt für $x,z \in U$ mit $x \not = z$: $Pr(h(x)=h(z))?\frac{1}{p}$

Wähle a aus ${1, ..., p-1}$ (uniform) zufällig, wobei p Primzahl. Es gilt für $x,z \in U$ mit $x\not = z$: $Pr(h(x)=h(z))\leq \frac{2}{m}$

Mit multiplikativem Hashing (wobei $U=[2^k]$, $m=2^l$), mit $h(x)=(a*x\ mod\ 2^k)div\ 2^{k-l}$ als a eine zufällige ungerade Zahl in $[2^k]$ wählt, dann gilt für beliebige $x,z\in U, x\not = z$: $Pr(h(x)=h(z))\leq \frac{2}{2^l}=\frac{2}{m}$

**Tabellenhashing** 
Universum $U=\sum^r$, mit $\sum={0,..., s-1}$. $m=2^l$ mit $l\leq w$ (w: Wortlänge, z.B. w=32). Wertebereich: [m] entspricht ${0,1}^l$ via Binärdarstellung. Repräsentation der Hashfunktion h: Array $A[1...r, 0... s-1]$ mit Einträgen aus ${0,1}^w$
- Nachteil: Array $A[1..r,0..s-1]$ benötigt Platz $r*s$ (Wörter). Sinnvoll nur für große Hashtabellen.
  - Platzsparend, etwas langsamer: $\sum={0,1}^4={0,1,...,9,A,...,F}$ ("Tetraden" bzw. Hexadezimalziffern.)
- Vorteile von Tabellenhashing:
  - Extrem schnelle Auswertung
  - Dasselbe A kann für $m=2^4,2^5,2^6,...,2^w$ benutzt werden. Ideal für die Kombination mit der Verdoppelungsstrategie: Verdopple Tabellengröße = erhöhe l um 1; Einträge in A bleiben unverändert.
  - Beweisbar gutes Verhalten, wenn Einträge von A zufällig.

Sei c konstant. Wenn $Pr(h(x) = h(z))\leq \frac{c}{m}$, für beliebige $x,z\in U$, $x \not = z$, und wenn wir Hashing mit verketteten Listen benutzen, dann ist die erwartete Zahl von Schlüsselvergleichen
- höchstens $c*a$ bei der erfolglosen Suche und
- höchstens $1 + c*a$ bei der erfolgreichen Suche.

## 5.3. Geschlossenes Hashing
> oder "offene Adressierung": Kollisionsbehandlungs-Methode.
Idee: Für jeden Schlüssel $x\in U$ gibt es eine Sondierungsfolge $h(x,0),h(x,1),h(x,2),...$ in [m]. Beim Einfügen von x und Suchen nach x werden die Zellen von T in dieser Reihenfolge untersucht, bis eine leere Zelle oder der Eintrag x gefunden wird.

### 5.3.1. Lineares Sondieren
$h(x,k)=(h(x)+k)mod\ m, k=0,1,2,...$

Ergebnisse für lineares Sondieren: Eine einzelne erfolglose Suche wird z.B. bei zu 90% gefüllter Tabelle durchaus teuer. Bei vielen erfolglosen Suchen in einer nicht veränderlichen Tabelle (anwendungsabhängig!) sind diese Kosten nicht tolerierbar. $a\leq 0,6$ oder $0,7$ liefert jedoch akzeptable Suchkosten. Die (über $x_i\in S$) gemittelte Einfüge-/Suchzeit ist dagegen sogar bei 90% gefüllter Tabelle erträglich.

### 5.3.2. Quadratisches Sondieren
$h:U\rightarrow [m]$ sei beliebige Hasfunktion. $h(x,k)=(h(x)+\lceil \frac{k}{2} \rceil^2 * (-1)^{k+1})mod\ m$, für $k=0,1,2,...$
Ist m Primzahl, so dass $m+1$ durch 4 teilbar ist, dann gilt bei der Verwendung von quadratischem Sondieren: ${h(x,k)| 0\leq k < m}=[m]$
Quadratisches Sondieren verhält sich sehr gut.

### 5.3.3. Doppel Hashing
Benutze zwei (unabhängig berechnete) Hashfunktionen $h_1:U\rightarrow [m]$ und $h_2:U\rightarrow [m-1]$ und setzte für $k=0,1,...$: $h(x,k):=(h_1(x)+k*(1+h_2(x)))mod\ m$. Wenn m Primzahl ist, dann gilt für Doppel-Hashing ${h(x,k) | 0 \leq k < m}$. Man kann beweisen: Wenn $h_1(x), h_2(x), x \in S$, rein zufällig sind, verhält sich Doppel-Hashing sehr gut, nämlich im Wesentlichen wie "Uniformes Sondieren".

### 5.3.4. Uniformes Sondieren / Ideales Hashing
Keine Methode, sondern eine Wahrscheinlichkeitsannahme für Verfahren mit offener Adressierung:
$(h(x,0), h(x,1),..., h(x,m-1))$ ist eine rein zufällige Permutation von $[m]$, unabhängig für jedes $x\in U$.

## 5.4. Löschen
Jede Zelle hat Statusvariable status (voll, leer, gelöscht ).
Löschen: Zelle nicht auf leer, sondern auf gelöscht setzen (engl.:"tombstone").
Suchen: Immer bis zur ersten leeren Zelle gehen.
Zellen, die gelöscht sind, dürfen mit einem neuen Schlüssel überschrieben werden.

Überlauf tritt spätestens ein, wenn die letzte leere Zelle beschrieben werden würde. 
Sinnvoller: Überlauf tritt ein, wenn die Anzahl der vollen und gelöschten Zellen zusammen eine feste Schranke bound überschreitet.

Operationen bei offener Adressierung
- empty(m):
  - Lege leeres Array $T[0...m-1]$ an.
  - Initialisiere alle Zellen $T[j]$ mit $(-,-, leer)$.
  - Wähle Hashfunktion $h: U x [m] \rightarrow [m]$.
  - Initialisiere inUse mit 0. (Zählt nicht-leere Zellen.)
  - Initialisiere load mit 0. (Zählt Einträge.)
  - Initialisiere bound (z.B. mit $\alpha_0m$, maximal $m-1$).
- lookup/delete(x)
  - Finde erstes l in der Folge $h(x,0),h(x,1),h(x,2),...$ mit
    - 1.Fall: $T[l].status = leer$: return "not found" bzw mache nichts
    - 2.Fall: $T[l].status = voll$ und $T[l].key=x$: return data bzw lösche key und setzte status auf gelöscht (load--)
- insert(x)
  - 1. Fall: $T[l].status = voll$: $T[l].data \leftarrow r$ (Update)
  - 2. Fall: $T[l'].status = gelöscht: T[l']\leftarrow (x,r,voll); load++ (überschreibe gelöschtes Feld)
  - 3. Fall: $T[l'].status = leer$: $l=l'$, neue Zelle

## 5.5. Cuckoo Hashing
Implementierung eines dynamisches Wörterbuchs. Zwei Tabellen $T_1, T_2$, jeweils Größe m. Zwei Hashfunktionen $h_1$ und $h_2$, $x\in S$ sitzt in $T_1[h_1(x)]$ oder in $T_2[h_2(x)]$. $\Rightarrow$ Konstante Suchzeit garantiert; auch delete(x) in $O(1)$ Zeit.
$h_1,\ h_2$ passen zu $S$, falls die Schlüssel aus $S$ gemäß der Regel gespeichert werden können, d.h. man kann $S$ in $S_1$ und $S_2$ partitionieren, so dass $h_1$ auf $S_1$ und $h_2$ auf $S_2$ injektiv ist. Das Verfahren heißt "Kuckucks-Hashing" wegen seiner Einfügeprozedur:
Schlüssel $x$, der eingefügt werden soll, kann Schlüssel $y$, der in $T_1[h_1(x)]$ oder $T_2[h_2(x)]$ ("im Nest") sitzt, hinauswerfen (verdrängen). Der verdrängte Schlüssel geht zu seinem alternativen Platz.

Hashfunktionen verteilen Schlüssel rein zufällig. Wenn man Cuckoo-Hashing mit $n$ Schlüsseln in zwei Tabellen mit je m Plätzen durchführt, wobei $\frac{}{m} \leq 1- \beta$ (essenziell!), dann passen $h_1, h_2$ mit Wahrscheinlichkeit $1-O(\frac{1}{m})$ zur Schlüsselmenge S.
Falls $h_1, h_2$ passen, ist die erwartete Einfügezeit $O(\frac{1}{\beta})$.
Nachteil: Auslastung der Tabelle unter 50%.

# 6. Sortierverfahren
Input: Tupel $x =(a_1,..., a_n)$ von Objekten $a_i$ mit Schlüssel- und Datenteil: $a_i.key$ und $a_i.data$. Gegeben als Array $A[1..n]$ oder als lineare Liste.

Stabil (Bei Vorkommen gleicher Sortierschlüssel) Sortierverfahren heißt stabil, wenn Objekte mit identischen Schlüsseln in der Ausgabe in derselben Reihenfolge stehen wie in der Eingabe.

Maßzahlen für Sortieralgorithmen (in Abhängigkeit von n):
1. Laufzeit (in O-Notation)
2. Anzahl der Vergleiche ( wesentliche Vergleiche“)
  ”$a_i.key < a_j.key$“ bzw. "$a_i.key \leq a_j.key“
3. Anzahl der Datenverschiebungen oder Kopiervorgänge
4. der neben dem Array (bzw. der linearen Liste) benötigte Speicherplatz;
   wenn dieser nur $O(1)$, also von n unabhängig, ist: Algorithmus arbeitet "in situ“ oder "in-place“.

## 6.1. Mergesort
(engl. merge = vermengen, reißverschlussartig zusammenfügen)
Algorithmenparadigma oder -schema: "Divide-and-Conquer“ (D-a-C, teile und herrsche“). (Kleine Teilarrays werden durch Insertionsort sortiert)
Sortiert stabil. Rechenzeit ist $\Theta(n\ log(n))$

Vorgehen auf Instanz $x\in I$:
0. Trivialitätstest: Wenn P für x einfach direkt zu lösen ist, tue dies. – Sonst:
1. Teile: Zerteile x in (zwei oder mehr) Stücke $x_1,..., x_a \in I$.
  (Wesentlich für Korrektheit/Terminierung: Jedes der Stücke ist "kleiner“ als x .)
2. Rekursion: Löse P für $x_1,..., x_a$, separat, durch rekursive Verwendung von A.
  Teillösungen: $r_1,..., r_a$ .
3. Kombiniere: Baue aus $x$ und $r_1,..., r_a$ und $x_1,..., x_a$ eine Lösung $r$ für $P$ auf $x$ auf.

```cpp
function Mergesort (a, b) // 1 ≤ a ≤ b ≤ n , sortiert A[ a..b ]
  if b − a ≤ n 0 // n 0 ≥ 0 ist vorausgesetzt
    then Insertionsort (a, b)
  else  // Wissen: Länge von A[ a..b ] ist ≥ 2
    m = a + $\lfloor$b(b − a)/2 $\rfloor$;
    Mergesort(a, m);
    Mergesort( m + 1, b) ;
    Merge (a, m , b) // fügt sortierte Teilfolgen zusammen;

function Merge (a, m, b) // für 1 ≤ a ≤ m < b ≤ n , sortiert A[ a..b ], nimmt an, dass A[ a..m ] und A[ m + 1..b ] sortiert sind.
  i = a; // Index in A[ a..m ]
  j = m + 1; // Index in A[ m + 1..b ]
  k = a; // Index in B[ a..b ]
  while i ≤ m and j ≤ b do
    if A[i] ≤ A[j]
      then B[k] = A[i]; ++i; ++k
    else B[k] = A[j]; ++j; ++k // verbleibendes Schlussstück kopieren:
  while i ≤ m do B[k] = A[i]; ++i; ++k;
  while j ≤ b do B[k] = A[j]; ++j; ++k;
    // B[ a..b ] nach A[ a..b ] kopieren:
  for k from a to b do A[k] = B[k]
```

## 6.2. Quicksort
Folgt ebenso wie Mergesort dem Divide-and-Conquer-Ansatz.
Quicksort ist nicht stabil.
Rechenzeit beträgt $O(n)+O(Gesamtzahl\ aller\ Schlüssel) =: V$

Ansatz für qsort(a, b), gleichzeitig Korrektheitsbetrachtung:
0. Trivialitätstest: Wenn $a \leq b$, ist nichts zu tun. (Oder: Wenn b − a < n 0 : Insertionsort(a, b).)
1. Teile: (Hier "partitioniere“) Wähle Pivotelement x ∈ {A[a].key,...,A[b].key}.
    Arrangiere die Einträge von A[a..b] so um, dass für ein p mit a ≤ p ≤ b gilt:
    A[p].key = x und A[a].key, . . . , A[p − 1].key ≤ x < A[p + 1].key, . . . , A[b].key.
2. Rekursion auf Teilinstanzen x 1 = A[a..p − 1] und x 2 = A[p + 1..b]:
    qsort(a, p − 1); r qsort(p + 1, b).
    Nach I.V. gilt nun: A[a..p − 1], A[p + 1..b] sortiert.
3. Kombiniere: Es ist nichts zu tun: A[a..b] ist sortiert.

- "Clever Quicksort“: Das Pivotelement x ist der Median der drei Schlüssel A[a].key, A[b].key, A[a + b(b − a)/2c].key
- "Randomisiertes Quicksort“: Wähle einen der b − a + 1 Einträge in A[a..b] zufällig.
- Allgemein: Wähle ein s mit a ≤ s ≤ b, vertausche A[a] mit A[s]. Das Pivotelement ist danach immer A[a].key.

```cpp
function qsort(a, b) // Rekursive Prozedur im Quicksort-Algorithmus, 1 ≤ a ≤ n + 1, 0 ≤ b ≤ n.
  if a < b then
    s = ein Element von {a, . . . , b}; // Es gibt verschiedene Methoden, um s zu wählen;
    vertausche A[a] und A[s];
    partition(a, b, p); // p: Ausgabeparameter
    qsort(a, p − 1);
    qsort(p + 1, b);

function partition(a, b, p) // Voraussetzung: a < b; Pivotelement: A[a]
  x = A[a].key;
  i = a + 1;
  j = b;
  while i ≤ j do // noch nicht fertig; Hauptschleife
    while i ≤ j and A[i].key ≤ x do ++i;
    while j > i and A[j].key > x do --j;
    if i = j then --j;  // Wissen: A[i].key > x
    if i < j then
      vertausche A[i] und A[j];
      ++i; --j;
  if a < j then vertausche A[a] und A[j];
  p = j; // Rückgabewert
```


## 6.3. Heapsort
Heap-Ordnung in Binärbäumen

Min-Heapsort: Ein Binärbaum T mit Knotenbeschriftungen m(v) aus (U, <) heißt min-heapgeordnet (kurz oft: heapgeordnet), wenn für alle Knoten v und w gilt: v Vorgänger von w ⇒ m(v) ≤ m(w). ⇒ in Knoten v steht der minimale Eintrag des Teilbaums $T_v$ mit Wurzel v.
T heißt max-heapgeordnet, wenn für alle v , w gilt: v Vorgänger von w ⇒ m(v) ≥ m(w).

Ein "linksvollständiger“ Binärbaum: Alle Levels j = 0, 1, . . . voll (jeweils 2 j Knoten) bis auf das tiefste. Das tiefste Level l hat von links her gesehen eine ununterbrochene Folge von Knoten.

(Unendlicher) vollständiger Binärbaum (mit Kunstwurzel), Kante zu linkem/rechtem Kind mit 0/1 beschriftet, Knoten gemäß Leveldurchlauf-Anordnung nummeriert. Beispiel: $(101110)_2 = 46$. Damit können linksvollständige Binärbaume ohne Zeiger als Arrays dargestellt werden: 
Speichere Eintrag zu Knoten Nummer i im Baum in A[i].
Dennoch können wir leicht zu Kindern und Vorgängern navigieren:
- Knoten 1 ist die Wurzel;
- Knoten 2i ist linkes Kind von i;
- Knoten 2i + 1 ist rechtes Kind von i;
- Knoten i ≥ 2 hat Vorgänger $\lfloor i/2 \rfloor$.

Min-Heap: $A[\lfloor i/2 \rfloor ].key ≤ A[i].key$, für 1 < i ≤ k (analog Max-Heap)

### 6.3.1. Heap reparieren
Heaps reparieren nach austausch von Knoten/Werten:
```cpp
function bubbleDown (1, k) // Heap-Reparatur in A[ 1 . . k ]. Vorbedingung: Höchstens A[ 1 ] ist zu groß
  j = 1; // aktueller Knoten“
  done = (2 · j > k);
  while not done do // (∗) höchstens A[j] ist zu groß, A[j] hat Kind A[ 2 · j] im Baum
    m = 2 · j;
    if m + 1 ≤ k and A[m+1].key < A[m].key
      then m = m + 1 ; // nun gilt: A[m] ist einziges oder "kleineres“ Kind von A[j]
    if A[m].key < A[j].key
      then vertausche A[j] mit A[m];
        j = m; // neuer aktueller Knoten
        done = (2 · j > k) ; // wenn done = false, gilt wieder (∗)
      else done = true. // fertig, kein Fehler mehr.
```

### 6.3.2. Heap sortieren
Die Idee von Heapsort für ein Array A[1..n] ist nun folgende:
1. (Heapaufbau) Arrangiere A[1..n] so um, dass ein Heap entsteht.
2. (Auswahlphase) Für k von n abwärts bis 2:
    Entnimm kleinsten Eintrag A[1] aus dem Heap A[1..k]. Stelle mit den in A[2..k] verbliebenen Einträgen in A[1..k − 1] wieder einen Heap her.
    (In A[k] ist dann Platz für den entnommenen Eintrag.)

```cpp
function HeapSelect(1, n)
  for k from n downto 2 do    // in A[1] steht das Minimum von A[1..k]
    vertausche A[1] mit A[k]; // in A[1..k − 1] ist höchstens A[1] zu groß
    bubbleDown(1, k − 1);     // Heapreparatur
```
Die Prozedur HeapSelect(1, n) führt höchstens 2n log n Vergleiche durch und hat Rechenzeit O(n log n).

### 6.3.3. Heap aufbauen
Idee: Betrachte im linksvollständigen Baum mit n Knoten die Teilbäume $T_l$ mit Wurzel l, und stelle in diesen "von unten nach oben“, also in der Reihenfolge $l = n, n − 1, . . . , 3, 2, 1$, die Heapbedingung her.

Also löst die folgende Variante von bubbleDown (s.o.) die Aufgabe (mit j=l als Startbedingung).
```cpp
function makeHeap(1, n) // Transformiert Array A[1 . . n] in einen Heap
  for ell from $\lfloor$ n/2 $\rfloor$ downto 1 do
    bubbleDown(ell, n);
```
Ein Aufruf makeHeap(1, n) wandelt A[1..n] in einen Heap um. Die Anzahl der Vergleiche ist nicht größer als 2n; die Rechenzeit ist $O(n)$.

#### 6.3.3.1. HeapSort
Der Aufruf HeapSort(A[1 . . n]) sortiert A[1 . . n] in fallende Reihenfolge. Die gesamte Rechenzeit ist O(n log n), die Gesamtzahl der Vergleiche ist kleiner als 2n(log n + 1). HeapSort arbeitet in situ/in-place (ist aber nicht stabil).
```cpp
function HeapSort(A[1 . . n])
  makeHeap(1, n);
  HeapSelect(1, n);
```

## 6.4. Datentyp: Prioritätswarteschlange (oder Vorrangwarteschlangen)
In einer Prioritätswarteschlange werden Objekte aufbewahrt, die mit einem Schlüssel aus einem totalgeordneten Universum (U, <) versehen sind. (Oft sind die Schlüssel Zahlen.) Objekte werden eingefügt und entnommen. Einfügungen sind beliebig möglich. Beim Entnehmen wird immer ein Eintrag mit minimalem Schlüssel gewählt. Idee: Schlüssel entsprechen hier "Prioritäten“ – je kleiner der Schlüssel, desto höher die Priorität. Wähle stets einen Eintrag mit höchster Priorität! Der Datentyp Prioritätswarteschlage ist mit Heaps effizient zu realisieren.

Datentyp: SimplePriorityQueue (Einfache Prioritätswarteschlange)
1. Signatur:
    - Sorten:
       - Keys
       - Data
       - PrioQ // "Priority Queues“
       - Boolean
   - Operatoren:
       - empty : → PrioQ
       - isempty : PrioQ → Boolean
       - insert : PrioQ × Keys × Data → PrioQ
       -extractMin: PrioQ → PrioQ × Keys × Data
2. Mathematisches Modell
    - Sorten:
      - Keys: (U, <) //totalgeordnetes Universum
      - Data: D // Menge von "Datensätzen"
      - Boolean: {false, true}
      - PrioQ: die Menge aller endlichen Multimengen (Elemente dürfen mehrfach vorkommen) P ⊆ U × D
    - Operationen:
      - empty ( ) = ∅ // die leere Multimenge
      - isemtpy(P) = true, für P = ∅; false, für $P \not= ∅$
      - insert(P, x, d) = P ∪ {(x, d)} (als Multimenge), 
      - extractMin(P) = undefiniert, wenn P = ∅; (P' , x_0 , d_0 ), wenn P \not= ∅

extractMin: Implementierung von extractMin(P): Ein Eintrag mit minimalem Schlüssel steht in der Wurzel, d. h. in Arrayposition 1.
Zeitaufwand: $O(log(n))$, wobei n die aktuelle Größe des Heaps ist.
```cpp
function extractMin()
// Entnehmen eines minimalen Eintrags aus Priority-Queue
// Ausgangspunkt: Pegelstand n (in n), A[1 . . n] ist Heap, n ≥ 1
  if n = 0 
    then Fehlerbehandlung“;
  x = A[1].key; 
  d = A[1].data;
  A[1] = A[n];
  n--;
  if n > 1 then bubbleDown(1, n);
  return (x, d);
```

Für Fehlerbehandlung z.B. bubbleUp um Heap zu reparieren
```cpp
function bubbleUp(i) // Heapreparatur ab A[i] nach oben
  j = i;
  h = $\lfloor$ j/2 $\rfloor$ ;
  while h ≥ 1 and A[h].key > A[j].key do
    vertausche A[j] mit A[h];
    j = h;
    h = $\lfloor$ j/2 $\rfloor$.
```

Überlaufbehandlung
```cpp
function insert(x, d) // Einfügen eines neuen Eintrags in Priority-Queue
// Ausgangspunkt: Pegel n enthält n, A[1 . . n] ist Heap.
  if n = m 
    then "Überlaufbehandlung"; // z. B. Verdopplung
  n++;
  A[n] ← (x, d);
  bubbleUp(n)
```

Allgemeinere Operation: "decreaseKey" ersetzt einen beliebigen Schlüssel im Heap (Position i) durch einen kleineren. Mit bubbleUp(i) wird die Heapeigenschaft wieder hergestellt.
```cpp
function decreaseKey(x, i)
// Erniedrigen des Schlüssels an Arrayposition i auf x
  if A[i].key < x 
    then Fehlerbehandlung
  A[i].key = x;
  bubbleUp(i)
```

Dabei erfordern empty und isempty (und das Ermitteln des kleinsten Eintrags) konstante Zeit, und insert, extractMin und decreaseKey benötigen jeweils Zeit O(log n). Dabei ist n jeweils der aktuelle Pegelstand, also die Anzahl der Einträge in der Prioritätswarteschlange.


### 6.4.1. Technisches Problem, noch zu klären:
Wie soll man der Datenstruktur "mitteilen“, welches Objekt gemeint ist, wenn decreaseKey auf einen Eintrag angewendet werden soll?
Erweiterung der Datenstruktur: Objekt (x, d) erhält bei Ausführung von insert (x, d) eine eindeutige und unveränderliche "Identität“ p zugeteilt, über die dieses Objekt angesprochen werden kann. (Damit können sogar verschiedene Kopien ein und desselben Datensatzes unterschieden werden!)

Datentyp: PriorityQueue (Prioritätswarteschlange)
1. Signatur:
    - Sorten:
        - Keys
        - Data
        - Id    // "Identitäten“
        - PrioQ
        - Boolean
    - Operationen:
        - empty : → PrioQ
        - isempty : PrioQ → Boolean
        - insert: PrioQ × Keys × Data → PrioQ × Id
        - extractMin: PrioQ → PrioQ × Id × Keys × Data
        - decreaseKey : PrioQ × Id × Keys → PrioQ
2. Mathematisches Modell
    - Sorten:
        - Keys: (U, <) // totalgeordnetes Universum“
        - Data: D // Menge von Datensätzen“
        - Id: N = {0, 1, 2, . . .} // unendliche Menge möglicher Identitäten“
        - Boolean: {false, true}
        - PrioQ: die Menge aller Funktionen f : X → U × D, wobei X = Def (f ) ⊆ N endlich ist
    - Operationen:
        - empty () = ∅  // die leere Funktion
        - isempty(f) = true, für f = ∅; false, für f \not = ∅
        - insert(x, d, f ) = (f ∪ {(p, (x, d))}, p), für ein p ∈ N − Def(f )
        - extractMin(f) = undefiniert, für f = ∅; (f 0 , p 0 , x 0 , d 0 ), für f \not= ∅
        - decreaseKey(p,x) = (f − {(p, (y, d))}) ∪ {(p, (x, d))}, falls f (p) = (y, d) mit x ≤ y (sonst Fehler)

## 6.5. Untere Schranke für Sortieren
Ein Sortieralgorithmus A heißt ein Schlüsselvergleichsverfahren, wenn in A auf Schlüssel x, y aus U nur Operationen:
$x<y$?, $x ≤ y$?, $x = y$? sowie Verschieben und Kopieren angewendet werden. Schlüssel sind also "atomare Objekte", die als Semantik nur ihre Rolle in der Ordnung (U, <) haben.
Gegensatz wäre: Die Binärdarstellung eines zahlenwertigen Schlüssels wird gelesen und verwendet.
Mergesort, Quicksort, Heapsort, Insertionsort sind Schlüsselvergleichsverfahren.
Wir haben gesehen: Diese Verfahren benötigen $O(n log n)$ oder $O(n^2 )$ Vergleiche.
Ziel in diesem Abschnitt: Schlüsselvergleichsverfahren können nicht schneller als in $Ω(n log n)$ Vergleichen sortieren.

Allgemein: Jeder vergleichsbasierte Sortieralgorithmus A erzeugt für jedes n einen Vergleichsbaum T A,n mit genau n! Blättern. Die Wege im Baum von der Wurzel zu den Blättern entsprechen den Berechnungen von A auf den n! genannten Eingaben; die Knoten auf einem solchen Weg entsprechen den in der Berechnung ausgeführten Vergleichen.

Wenn A ein Schlüsselvergleichsverfahren ist, das das Sortierproblem für beliebige Inputs mit n Komponenten löst, dann gibt es eine Eingabe (a 1 , . . . , a n ) (eine Permutation von {1, . . . , n} ) ,auf der A mindestens $\lceiling log(n!) \rceiling$ Vergleiche ausführt. Dies sind $n log n − O(n)$ viele. 
Beweis: Der Vergleichsbaum, den A erzeugt, hat $n!$ (externe) Blätter, also hat er Tiefe $\geq \lceiling log(n!) \rceiling$ ). Wir zeigen auch: $log(n!) = n log n − O(n)$

Wenn A ein Schlüsselvergleichsverfahren ist, das das Sortierproblem für alle Inputs mit n Komponenten löst und dabei Randomisierung benutzt (d. h. Zufallsexperimente ausführt wie etwa Randomisiertes Quicksort) , dann gibt es eine Eingabe a = (a 1 , . . . , a n ), so dass die erwartete Vergleichsanzahl von A auf a (gemittelt über die Zufallsexperimente von A) mindestens log(n!) ist.

## 6.6. Sortieren in Linearzeit
Wenn wir Schlüssel nicht als atomares Objekt, sondern z. B. als Index benutzen, dann gilt die untere Schranke nicht. Wir wollen (für besondere Schlüsselformate, ganze Zahlen oder Strings) in Linearzeit sortieren!

### 6.6.1. Countingsort – Sortieren durch Zählen
Idee, drei Phasen:
1. Zähle in Komponente C[i] eines Arrays C[0..m − 1], wie oft der Schlüssel i vorkommt.
2. Benutze das Ergebnis von 1., um (wieder in C[i]) zu berechnen, wie viele Einträge in A einen Schlüssel ≤ i haben.
3. Übertrage die Einträge mit Schlüssel i aus A in die Positionen C[i−1]+1, . . . ,C[i] in Array B, stabil.

```cpp
for i from 0 to m − 1 do C[i] = 0; // Zeitaufwand: Θ(m)
for j from 1 to n do C[A[j].key]++; // Zeitaufwand: Θ(n)
for i from 1 to m − 1 do C[i] = C[i−1] + C[i]; // Zeitaufwand: Θ(m)
for j from n downto 1 do          // Zeitaufwand: Θ(n)
  i = A[j].key;
  B[C[i]] = A[j]; // aktueller Platz für Schlüssel i (in i)
  C[i]--; // auf linken Nachbarn umsetzen
                                
```

n Objekte mit Schlüsseln aus [m] (gegeben in Array) können in Zeit Θ(n + m) und mit Zusatzplatz Θ(n + m) sortiert werden.
Das Sortierverfahren ist stabil.
Linearzeit und linearer Platz, falls m ≤ cn, c konstant.
Countingsort ist auch in der praktischen Anwendung sehr schnell

### 6.6.2. Bucketsort – Fachsortieren
Nun seien die zu sortierenden Objekte mit Schlüsseln aus [m] als (einfach verkettete) lineare Liste gegeben. Durchlaufe Eingabeliste, übertrage Einträge mit Schlüssel i an den Anfang der Liste $L_i$ (angehängt in B[i]): Zeit Θ(n)
Bemerke: Identische Schlüssel in umgekehrter Reihenfolge.

1. Bearbeite Elemente der Liste A nacheinander.
    Füge Listenelement (i, data) vorn in Liste B[i] ein.
    NB: Reihenfolge von Elementen mit demselben Schlüssel wird umgedreht.
2. Für i = m − 1, . . . , 1, 0: lies B[i] von vorn nach hinten.
    Füge Element (i, data) vorn in Ausgabeliste ein.
    NB: Reihenfolge wird erneut umgedreht → Stabilität.

Korrektheit: klar.
Laufzeit:
0. Anlegen von B, Initialisieren mit NULL-Zeigern: Θ(m).
1. Verteilen auf die Listen: Θ(n)
2. Zusammenfügen: Θ(m) + Θ(n) (Jeder Listenanfang B[i] muss inspiziert werden.)
Gesamt: Θ(m + n).
Linearzeit und linearer Platz, falls m ≤ cn, c konstant.

### 6.6.3. Radixsort – Mehrphasen-Counting-/Bucketsort
Anwendbar in verschiedenen Situationen:
1. Schlüssel sind Folgen (Anordnungskriterium: lexikographisch)
2. Schlüssel sind Zahlen
3. k (möglicherweise verschiedene) geordnete Mengen
4. Σ^{<∞} . Dabei: Σ ist "Alphabet“, d. h. nichtleere endliche Menge (z. B. ein ISO/IEC 8859-Alphabet) mit Ordnung <

Idee: sortiere k-mal mittels Counting-/Bucketsort und zwar gemäß Komponente k, dann k − 1, . . . , dann 1 (die "am wenigsten signifikante“ Komponente zuerst).


# 7. Graphen, Digraphen und Breitensuche
Graphen und Digraphen sind eine in der Informatik und zur Modellierung von Anwendungssituationen
allgegenwärtige (Daten-)Struktur.

Ein gerichteter Graph oder Digraph G (wegen "directed graph“) ist ein Paar (V, E), wobei V eine endliche Menge und E eine Teilmenge von V × V = {(v, w) | v, w ∈ V } ist. Die Elemente von V heißen Knoten 1 , die Elemente von E heißen Kanten.

Ist e = (v, w) eine Kante (von G) bzw sei G = (V, E) ein Digraph, so 
- v bzw. w heißen inzident zu e (v, w liegen auf“ e),
- Eine Kante (v, v) heißt Schleife ( loop“).
- Der Eingangsgrad ( "indegree“) eines Knotens v ist die Anzahl der Kanten, die in v hineinführen
- Der Ausgangsgrad ( "outdegree“) eines Knotens v ist die Anzahl der Kanten, die aus v herausführen
- Ein Kantenzug in G ist eine Folge p = (v 0 , v 1 , . . . , v k ) von Knoten, wobei (v i−1 , v i ) ∈ E für 1 ≤ i ≤ k.
- Ein Kantenzug (v 0 , v 1 , . . . , v k ) in einem Digraphen G heißt ein Kreis oder Zyklus ( "cycle"), wenn k ≥ 1 und v 0 = v k . Die Länge des Kreises ist k
- Ein Digraph G heißt kreisfrei oder azyklisch, wenn es in G keinen Kreis gibt, sonst heißt G zyklisch.
- Ein Graph G, der nur eine Zusammenhangskomponente hat, heißt zusammenhängend.
- Ein Graph heißt ein freier Baum (oder nur Baum), wenn er zusammenhängend und kreisfrei ist.
- maximal Kreisfrei für: G ist kreisfrei, aber das Hinzufügen einer beliebigen Kante zu G erzeugt einen Kreis


Ein ungerichteter Graph, oft auch: ein Graph G ist ein Paar (V, E), wobei V eine endliche Menge ist und E eine Teilmenge von $[V]_2$

Handshaking-Lemma: Wenn G=(V,E) ein Graph ist, dann gilt $\sum deg(v)=2|E|$


## 7.1. Datenstrukturen für Digraphen und Graphen
Sei G = (V, E) Graph oder Digraph.
V kann irgendeine endliche Menge sein. (z.B. {A,B,C,D,E}.)
Ordne die n = |V| Knoten beliebig an, z. B. als $V = {v_1 , . . . , v_n }$ und stelle sie durch ein Array dar:
nodes: array [1 . . n] of nodetype

Ist G = (V, E) Graph oder Digraph mit V = {1, . . . , n}, dann ist die Adjazenzmatrix von G die n × n-Matrix. Die Adjazenzmatrix eines Graphen ist symmetrisch: A[i, j] = A[j, i]. Die Anzahl der 1en in Zeile/Spalte i ist deg(i).
Verwendet man zur Darstellung eines Graphen bzw. Digraphen mit n Knoten eine Adjazenzmatrix, so gilt:
- Der Speicherplatzbedarf ist $Θ(n^2 )$ [Bits];
- $a_{ij}$ kann in Zeit $O(1)$ ermittelt oder geändert werden;
- die Ermittlung aller Nachfolger, Vorgänger oder Nachbarn eines Knotens erfordert Zeit $Θ(n)$. (Zeilen/Spaltendurchlauf; Reihenfolge: 1, . . . , n ).

Erweiterungen der Adjazenzlistenstruktur:
1. Knotenbeschriftungen: im nodes-Array zu platzieren.
2. Kantenbeschriftungen: in zusätzlichen Komponenten (Attributen) in den Elementen für die Adjazenzlisten.
3. In Graphen: Der Listeneintrag für j in $L_i$ kann einen Zeiger zum Listeneintrag für i in $L_j$ (die "Gegenkante“) enthalten.
4. Bei Digraphen: Der Umkehrgraph $G^R$ enthält in der Adjazenzliste $L^R_i$ für i die Knoten j, die Vorgänger von i in G sind.

Wenn ein Graph oder Digraph G = (V, E) mittels Adjazenzlisten dargestellt wird, gilt:
1. Speicherplatz $O(|V | + |E|)$ wird benötigt
2. das Durchlaufen aller Kanten kann in Zeit $O(|V | + |E|)$ ausgeführt werden
3. das Durchlaufen der Adjazenzliste zu Knoten i benötigt Zeit $O(deg(i))$ bzw. $O(outdeg(i))$
4. (nur) falls Vorgängerlisten vorliegen, können auch die Vorgänger von Knoten i in Zeit $O(indeg(i))$ durchlaufen werden.


## 7.2. Breitensuche in Digraphen
### 7.2.1. Breitensuche von einem Knoten $v_0$ aus:
- Finde alle Knoten v, die von $v_0$ aus erreichbar sind.
- Nummeriere die entdeckten Knoten.
- Bestimme für jeden erreichbaren Knoten v einen Weg von $v_0$ nach v mit minimaler Länge, und notiere diese Länge.
- Diese Länge heißt der Abstand von $v_0$ nach v, kurz $d(v_0 , v)$, oder das Level von v (von $v_0$ aus gemessen).

Initialisierung: bfs_count=0;
Alle bfs_num(v) werden auf 0 gesetzt.
Q: Queue
```cpp
function bfs (v_0 ) // Breitensuche von v 0 aus, v 0 wird entdeckt
  bfs count++;
  bfs num [v_0 ] = bfs count;
  level [v_0 ] = 0 ;
  p [v_0 ] = v_0 ; // Kennzeichne Startknoten
  Q.enqueue (v_0 ) ; // Startknoten in Warteschlange stecken
  while not Q.isempty do
    v = Q.dequeue; // nun bearbeite v:   für jeden Nachfolger w von v (Adjazenziste!) tue:
    if bfs_num [ w ] = 0 then // w wird entdeckt:
      bfs_count++;
      bfs_num[ w ] = bfs_count;
      level[ w ] = level[v] + 1 ;
      p[ w ] = v; // w von v aus erreicht
      Q.enqueue( w ) ;
```
Genau diejenigen Knoten, die von v_0 aus erreichbar sind, werden entdeckt, erhalten also eine bfs-Nummer, eine Levelnummer und einen Vorgänger, und sie werden bearbeitet, d. h., ihre Adjazenzliste wird durchlaufen. Die entdeckten Knoten mit den Kanten (p(v), v), $v \not = v_0$ , bilden einen Baum, den Breitensuchbaum oder BFS-Baum.

### 7.2.2. Globale Breitensuche in G#
Wie erreichen wir die restlichen Knoten in G?
Starte eine Breitensuche bei jedem Knoten v, der nicht bei einer vorherigen Breitensuche entdeckt worden ist. Behalte dabei die vorher vergebenen Nummern bei.
```cpp
function BFS(G) // Breitensuche in G = (V, E)
  bfs count ← 0;
  for v from 1 to n do bfs num(v) ← 0;
  for v from 1 to n do
    if bfs num[v] = 0 then
      bfs(v); // starte Breitensuche von v aus
```

# 8. Tiefensuche
## 8.1. einfache Tiefensuche in Digraphen
Eingabeformat: Digraph $G = (V, E)$, Knotenmenge $V = {1, . . . , n}$, in Adjazenzlisten-/array- oder Adjazenzmatrixdarstellung, aus v ausgehende Kanten sind (implizit) angeordnet.
Ziele:
- Besuche alle Knoten und Kanten.
- Sammle einfache Strukturinformation.

Tiefensuche (Depth-First-Search)
Zunächst: Gehe von Knoten $v_0$ aus, finde alle auf Wegen von $v_0$ aus erreichbaren Knoten und Kanten.
Vorwärtsgehen hat Vorrang! Effekt: Die Folge der entdeckten Knoten geht immer "so weit wie möglich in die Tiefe“.

Realisierung: Rekursive Prozedur "dfs(v)":
- "Besuche“ Knoten v (Aktion an diesem Knoten).
- Dann betrachte die Nachfolger $w_1, . . . , w$ outdeg(v) von v nacheinander, aber: 
- Sobald neuer Knoten w "entdeckt“ wird, starte sofort dfs(w).


Man muss verhindern, dass Knoten v mehrfach besucht wird. Dazu: "Statusinformation“, in Array $status[1 . . n]$ (oder im nodesArray) :
- v neu – noch nie gesehen
- v aktiv – dfs(v) gestartet, noch nicht beendet
- v fertig – dfs(v) beendet
Initialisierung: Alle Knoten sind neu .

Einfachversion:
Knoten werden in der Reihenfolge der Entdeckung durchnummeriert: $dfs num[1 . . n]$ speichert Tiefensuch-Nummerierung.
Mitzählen in dfs_count (globale Variable), mit 0 initialisiert. dfs-visit(v): Aktion an v bei Entdeckung (anwendungsabhängig).

```cpp
funcition dfs(v) // Tiefensuche an v, rekursiv, nur für v mit status[v] = neu aufzurufen
  dfs count++;
  dfs num[v] = dfs count;
  status[v] = aktiv ;
  dfs-visit(v); // Aktion an v bei Erstbesuch; für jeden Nachfolger w von v (Adjazenzliste!) tue:
    if status[w] = neu // w wird entdeckt!
      then dfs(w);
  status[v] ← fertig .
```

Bei Tiefensuche von $v_0$ aus wird für jeden Knoten $v \in \R v_0 dfs(v)$ (genau einmal) aufgerufen, für Knoten $v \in \R_{v_0}$ wird dfs(v) nicht aufgerufen. Jede Kante $(v, w) \in E_{v_0}$ wird genau einmal betrachtet, andere Kanten nicht.

Globale Tiefensuche in Digraphen: Alle Knoten und Kanten werden besucht.
```cpp
function DFS(G)  // Tiefensuche in G = (V, E) mit V = {1, . . . , n}
  dfs count = 0;
  for v from 1 to n do status[v] = neu ;
  for v from 1 to n do
    if status[v] = neu then
        dfs(v);
// starte Tiefensuche von v aus
```

## 8.2. Volle Tiefensuche in Digraphen
Wir bauen $dfs(v)$ und $DFS(G)$ aus, so dass die Kanten $(v, w)$ von G in vier Klassen T, B, F, C eingeteilt werden:
- T ("Tree"): Baumkanten, die Kanten des Tiefensuchwaldes.
    Kriterium: Wenn $dfs(v)$ die Kante $(v, w)$ betrachtet, ist $w$ noch neu.
- B ("Back"): Rückwärtskanten. $(v, w) ist Rückwärtskante, wenn w Vorfahr von v im Tiefensuchwald ist.
    Kriterium: Wenn $dfs(v)$ die Kante $(v, w)$ betrachtet, ist w aktiv .
- F Vorwärtskanten ("Forward"): (v, w) ist Vorwärtskante, wenn w Nachfahr von v im Tiefensuchwald ist, und (v, w) keine Baumkante ist.
    Kriterium: Wenn dfs(v) die Kante (v, w) betrachtet, ist w fertig und dfs num(v) < dfs num(w).
- C Querkanten ("Cross"): (v, w) ist Querkante, wenn der gesamte Unterbaum von w schon fertig abgearbeitet ist, wenn dfs(v) aufgerufen wird.
    Kriterium: Wenn dfs(v) die Kante (v, w) betrachtet, ist w fertig und dfs num(v) > dfs num(w).

```cpp
function dfs (v) // "volle“ Tiefensuche in v , nur für v neu erlaubt
  dfs count++;
  dfs num[ v ] ← dfs count;
  status[ v ] ← aktiv ;
  dfs-visit (v) ; // Aktion an v bei Entdeckung für jeden Nachfolger w von v (Adjazenzliste!) tue:
    1. Fall: status[w] = neu: T ← T ∪ {(v, w )} ; dfs ( w ) ;
    2. Fall: status[w] = aktiv: B ← B ∪ {(v, w )} ;
    3. Fall: status[w] = fertig ∧ dfs num[ v ] < dfs num[w]: F ← F ∪ {(v, w )} ;
    4. Fall: status[w] = fertig ∧ dfs num[ v ] > dfs num[w]: C ← C ∪ {(v, w )} ;
  f count++;
  f num[ v ] ← f count;
  fin-visit (v) ; // Aktion an v bei Abschluss
  status[ v ] ← fertig .
```

Initialisierung: dfs count ← 0; f count ← 0.
Alle Knoten sind neu ; Mengen T , B, F , C sind leer.
Tiefensuche von $v_0$ aus ("dfs(v 0 )“) entdeckt $R_{v_0}$ .

Tiefensuche für den ganzen Graphen: DFS(G) wie vorher, nur mit der voll ausgebauten dfs-Prozedur, und der Initialisierung von f count und T , B, F , C. 
```cpp
function DFS (G) // Tiefensuche in G = (V, E) , voll ausgebaut
  dfs count ← 0 ;
  f count ← 0 ;
  T ← ∅; B ← ∅; F ← ∅; C ← ∅;
  for v from 1 to n do status[v] ← neu ;
  for v from 1 to n do
    if status[v] = neu then
      dfs ( v ) ; // starte (volle) Tiefensuche von v aus
```

- Beobachtung 1: Jede Kante (v, w) wird genau einmal betrachtet und daher genau in eine der Mengen T , B, F und C eingeordnet.
- Beobachtung 2: Die dfs-Nummern entsprechen einem Präorder-Durchlauf, die f-Nummern einem Postorder-Durchlauf durch die Bäume des Tiefensuch-Waldes.
- Beobachtung 3: Folgende Aussagen sind äquivalent:
  - dfs(w) beginnt nach dfs(v) und endet vor dfs(v) (d.h. dfs (w) wird (direkt oder indirekt) von dfs (v) aus aufgerufen);
  - dfs num[v] < dfs num[w] ∧ f num[v] > f num[w];
  - v ist Vorfahr von w im Tiefensuch-Wald.


## 8.3. Tiefensuche in ungerichteten Graphen
Einfacher als Tiefensuche in gerichteten Graphen.
Zweck:
- Zusammenhangskomponenten finden
- Spannbaum für jede Zusammenhangskomponente finden
- Kreisfreiheitstest

```cpp
function udfs(v) // Tiefensuche von v aus, rekursiv; nur für v mit status[v] = neu aufrufen
  dfs count++;
  dfs num[v] ← dfs count;
  dfs-visit(v); // Aktion an v bei Erstbesuch
  status[v] ← aktiv ;
    für jede neue“ Kante (v, w) (Adjazenzliste!) tue:
      setze Gegenkante (w, v) auf gesehen“ ;
        1. Fall: status[w] = neu : T ← T ∪ {(v, w)}; udfs(w);
        2. Fall: status[w] = aktiv: B ← B ∪ {(v, w)};
  f count++;
  f num[v] ← f count;
  fin-visit(v); // Aktion an v bei letztem Besuch
  status[v] ← fertig.

//Globale Tiefensuche in (ungerichtetem) Graphen G:
function UDFS(G) // Tiefensuche in G = (V, E)
  dfs_count ← 0;
  f_count ← 0;
  for v from 1 to n do status[v] ← neu ;
  T ← ∅; B ← ∅;
  for v from 1 to n do
    if status[v] = neu then
      udfs(v); // starte Tiefensuche von v aus
```

$udfs(v_0)$ werde aufgerufen. Dann gilt:
- $udfs(v_0)$ entdeckt genau die Knoten in der Zusammenhangskomponente von $v_0$
- Die Kanten (v, w), für die udfs(w) unmittelbar aus udfs(v) aufgerufen wird, bilden einen gerichteten Baum mit Wurzel v 0 ("Tiefensuchbaum")
- (Satz vom weißen Weg) u ist im DFS-Baum ein Nachfahr von v genau dann wenn zum Zeitpunkt des Aufrufs udfs(v) ein Weg von v nach u existiert, der nur neue (weiße) Knoten enthält.

$UDFS(G)$ werde aufgerufen. Dann gilt:
- Die T -Kanten bilden eine Reihe von Bäumen (die Tiefensuch-Bäume). Die Knotenmengen dieser Bäume sind die Zusammenhangskomponenten von G.
- Die Wurzeln der Bäume sind die jeweils ersten Knoten einer Zusammenhangskomponente in der Reihenfolge, die in Zeile (2) benutzt wird.

Gesamtrechenzeit: $O(|V | + |E|)$: linear!

Kreisfreiheitstest in Graphen und Finden eines Kreises, wenn es einen gibt: 
Nach Ausführung von UDFS(G) gilt: $B \not= ∅ ⇔ G$ enthält einen Kreis.

## 8.4. Kreisfreiheitstest und topologische Sortierung
- Ein Kantenzug $(v_0 , v_1 , . . . , v_k )$ in einem Digraphen G heißt ein Kreis oder Zyklus, wenn k ≥ 1 und $v_0 = v_k$ .
- Ein Kreis $(v_0 , v_1 , . . . , v_{k−1} , v_0 )$ heißt einfach, wenn $v_0 , . . . , v_{k−1}$ verschieden sind.

- Ein Digraph G heißt kreisfrei oder azyklisch, wenn es in G keinen Kreis gibt, sonst heißt G zyklisch.
- Azyklische gerichtete Graphen: "Directed Acyclic Graphs", daher DAGs.

## 8.5. Starke Zusammenhangskomponenten in Digraphen
Zwei Knoten v und w in einem Digraphen G heißen äquivalent, wenn $v \rightarrow w$ und $w \rightarrow v$ gilt. – Notation: $v \leftrightarrow w$.

Die Äquivalenzklassen zur Relation $\leftrightarrow$ heißen starke Zusammenhangskomponenten von G.

- Trick 1: Führe DFS im "Umkehrgraphen“ $G^R$ durch, der durch Umkehren aller Kanten in G entsteht.
    - Beobachtung: G R hat dieselben starken Zusammenhangskomponenten wie G.
- Trick 2: Verwende die f-Nummern einer ersten DFS in G, um zu bestimmen, in welcher Reihenfolge die Knoten in der Hauptschleife der zweiten DFS (in $G^R$ ) betrachtet werden.

Strong Components(G) (von S. R. Kosaraju, 1978)
- Eingabe: Digraph G = (V, E)
- Ausgabe: Starke Zusammenhangskomponenten von G
- (1) Berechne die f-Nummern mittels DFS(G);
- (2) Bilde "Umkehrgraphen“ $G^R$ durch Umkehren aller Kanten in G;
- (3) Führe $DFS(G^R)$ durch; Knotenreihenfolge: f-Nummern aus (1) absteigend
- (4) Ausgabe: Die Knotenmengen der Tiefensuchbäume aus (3) .


# 9. Divide-and-Conquer-Algorithmen
## 9.1. Multiplikation ganzer Zahlen
Algorithmus Karatsuba(x, y)\
Eingabe: Zwei n-Bit-Zahlen x und y, nichtnegativ
```cpp
if n ≤ n 0 
  then return SM(x, y) // Schulmethode
else
  k ← dn/2e;
  zerlege x = A · 2 k + B und y = C · 2 k + D;
  E ← A − B und F ← C − D; // auf dn/2e Bits aufgefüllt
  G ← Karatsuba(A, C);   // Rekursion
  H ← Karatsuba(B, D);   // Rekursion
  I ← Karatsuba(|E|, |F |);   // Rekursion
  return G · 2 2k + (G + H − sign(E) · sign(F ) · I) · 2 k + H
```
## 9.2. Matrixmultiplikation
Eingabe: Zwei $n × n$-Matrizen A und B.
- Falls $n ≤ n_0$ : Berechne $A · B$ mit der direkten Methode. Kosten $n^3_0$ Multiplikationen.
- Falls $n > n_0$ , zerlege A, B in jeweils 4 quadratische $(n\ 2) ×(n\ 2)$-Teilmatrizen
$A=(\frac{C | D}{E | F}); B=(\frac{G | H}{K | L}); A*B=(\frac{C*G+D*K| C*H+D*L}{E*G+F*K| E*H+F*L})$
$\rightarrow$ Einfache Analyse ergibt: Dies führt zu $n^3$ Multiplikationen in R, kein Gewinn.

Mit "Straßentrick": 7 Multiplikationen genügen
- $P_1 = C · (H − L) $
- $P_5 = (C + F ) · (G + L)$
- $P_2 = (C + D) · L $
- $P_6 = (D − F ) · (K + L)$
- $P_3 = (E + F ) · G $
- $P_7 = (C − E) · (G + H)$
- $P_4 = F · (K − G)$
Dann:
$A x B = (\frac{P_5 + P_4 − P_2 + P_6 | P_1 + P_2}{ P_3 + P_4 | P_1 + P_5 − P_3 − P_7})$

## 9.3. Master Theorem
"Rekursionsbaum“: Veranschaulicht Kostenaufteilung
Wenn v ein Knoten auf Level i ist, dann gilt: $B(n/b_i ) ≤$ Summe der Einträge im Unterbaum unter v.

Es gelte $B(n) ≤ \begin{} g, falls n = 1; \ a · B(n/b) + f (n) , sonst, \end{}$
für ganzzahlige konstante $b > 1$ und $a > 0$. Dann gilt für $n = b^l$:
1. Fall: $f (n) = O(n^α )$ mit $α < log_b a$. Dann: $B(n) = O(n*log_b a )$
2. Fall: $f (n) = O(n^α )$ mit $α = log_b a$. Dann: $B(n) = O(n*log_b a * log n)$
3. Fall: $f (n) = Ω(n^α )$ mit $α > log_b a$ und $f(n/b) ≤ \frac{c}{a} * f (n)$, für c < 1 konstant.
    Dann gilt $B(n) = O(f (n))$.

## 9.4. Das Selektionsproblem
Gegeben ist eine Folge $(a_1 , . . . , a_n )$ von n Objekten aus einer totalen Ordnung $(D, <)$ (in Array oder als Liste), sowie eine Zahl $k, 1 ≤ k ≤ n$.
Aufgabe: Finde das Element x der Folge, das Rang k hat, d. h. das Objekt x in der Liste mit $|{i | a_i < x}| < k ≤ |{i | a_i ≤ x}|$.

```cpp
Prozedur rqSelect(a, b, k)
// Rekursive Prozedur im Quickselect-Algorithmus, 1 ≤ a ≤ b ≤ n , a ≤ k ≤ b .
// Vorbedingung: Alle Einträge vom Rang < a [ > b ] links [rechts] von A[ a..b ]
// Nachbedingung: Eintrag vom Rang k in A[ k ], kleinere links, größere rechts davon.
  if a = b (= k) then return;
  s ← ein zufälliges Element von {a, . . . , b};
  if (a < s) then vertausche A[a] und A[s];
  partition(a, b, p); // wie bei rqsort
  if k = p then return;
  if k < p then rqSelect(a, p − 1, k)
      else rqSelect(p + 1, b, k).
```


# 10. Greedy-Algorithmen: Prinzipien
Greedy-Algorithmen sind anwendbar bei Konstruktionsaufgaben, deren Ziel es ist, eine optimale Struktur zu finden, die aus mehreren Komponenten besteht. Sie finden eine Lösung, die sie schrittweise aufbauen.
In jedem Schritt wird eine "lokal“ oder aus der aktuellen Sicht optimale Entscheidung getroffen, ohne "an die Zukunft zu denken“. 
(Was dies konkret bedeutet, versteht man besser anhand der später betrachteten Beispiele.) 
Es werden dabei nicht mehr Teillösungen konstruiert als unbedingt nötig. 
Es werden nie Entscheidungen korrigiert oder zurückgesetzt. 

## 10.1. Beispiel 1: Hörsaalbelegung
Gegeben: Veranstaltungsort (Hörsaal), Zeitspanne $[T_0 , T_1 )$ (z. B. 7 Uhr bis 21 Uhr) und eine Menge von n Aktionen (Vorlesungen oder ähnliches), die durch Start- und Endzeit spezifiziert sind: $[s_i , f_i )$ mit $T_0 ≤ s_i < t_i ≤ T_1$ , für $1 ≤ i ≤ n$.

Gesucht: Belegung des Hörsaals, die möglichst viele Ereignisse mit disjunkten Zeitspannen stattfinden lässt.
$ A ⊆ {1, . . . , n}$ heißt zulässig, wenn alle $[s_i , f_i ), i ∈ A$, disjunkt sind.

Trick: Bearbeite Ereignisse in der Reihenfolge wachsender Schlusszeiten. O.B.d.A.: Veranstaltungen nach Schlusszeiten aufsteigend sortiert (Zeitaufwand $O(n log n)$ ) , also: $f_1 ≤ f_2 ≤ · · · ≤ f_n$
Wiederhole: Wähle die wählbare Aktion mit der kleinsten Schlusszeit und füge sie zum Belegungsplan hinzu. Eine Aktion ist wählbar, wenn ihre Startzeit mindestens so groß wie die Schlusszeit der letzten schon geplanten Veranstaltung ist.

Algorithmus Greedy Scheduling (GS)
Eingabe: Reelle Zahlen $T_0 < T_1$ , Paare $(s_1 , t_1 ), . . . , (s_n , f_n )$, mit $T_0 ≤ s_i < f_i ≤ T_1$ für $1 ≤ i ≤ n$
Ausgabe: Maximal großes $A ⊆ {1, . . . , n}$ mit $[s_i , f_i ), i ∈ A§, disjunkt
```cpp
Sortiere Paare // gemäß $f_1 , . . . , f_n$ , nummeriere um, so dass $f_1 ≤ · · · ≤ f_n$ ;
A ← {1};
f_last ← f_1 ;
for i from 2 to n do
  if s_i ≥ f_last then // [s i , f i ) wählbar
    A ← A ∪ {i};
    f_last ← f_i ;
return A
```

## 10.2. Beispiel 2: Fraktionales ("teilbares") Rucksackproblem
Veranschaulichung: Ein Dieb stiehlt Säckchen mit Edelmetallkrümeln (Gold, Silber, Platin) und Edelsteinen. Er hat einen Rucksack mit Volumen b dabei. Durch teilweises Ausleeren der Säckchen kann er beliebige Teilvolumina herstellen. Der Wert pro Volumeneinheit ist unterschiedlich für unterschiedliche Materialien. Was soll er in seinen Rucksack mit Volumen b packen, um den Wert der Beute zu maximieren?

Dazu: Benenne den Bruchteil $λ_i ∈ [0, 1]$, den er von Säckchen i mitnehmen soll.
Gegeben: ( n Objekte mit:)
  - Volumina $a_1 , . . . , a_n > 0$, 
  - Nutzenwerte $c_1 , . . . , c_n > 0$, 
  - Volumenschranke b
Gesucht: 
  - Vektor $(λ_1 , . . . , λ_n ) ∈ [0, 1]^n$ , so dass $λ_1 a_1 + . . . + λ_n a_n ≤ b$ ("zulässig") und $λ_1 c_1 + . . . + λ_n c_n$ maximal.
Kern der Lösungsidee: 
  - Berechne "Nutzendichten“: $d_i=\frac{c_i}{a_i}, 1 \leq i \leq n$,
  - und sortiere die Objekte gemäß $d_i$ fallend.
  - Nehme von vorne beginnend möglichst viele ganze Objekte, bis schließlich das letzte Objekt teilweise genommen wird, so dass die Volumenschranke vollständig ausgeschöpft wird.

```cpp
function Greedy_Fractional_Knapsack() //(GFKS)
  for i from 1 to n do
    d_i = c_i /a_i ;
    λ_i = 0;
  Sortiere Objekte gemäß d i fallend;
  i = 0;
  r = b; // Inhalt r ist das verfügbare Rest-Volumen
  while r > 0 do
    i++;
    if a_i ≤ r
      then λ_i = 1; r = r − a_i ;
      else λ_i = r/a_i ;
        r = 0;
```
Der Algorithmus GFKS ist korrekt (liefert eine zulässige Lösung mit maximalem Gesamtnutzen) und hat Rechenzeit $O(n log n)$.

Charakteristika der Greedy-Methode:
1. Der erste Schritt der Greedy-Lösung ist nicht falsch. Es gibt eine optimale Lösung, die als Fortsetzung des ersten Schrittes konstruiert werden kann.
2. "Prinzip der optimalen Substruktur“: Kombiniert man das Ergebnis des ersten "Greedy-Schritts“ mit einer beliebigen optimalen Lösung für die reduzierte Instanz (Wegnehmen des Teils, der durch den ersten Schritt erledigt ist), dann ergibt sich eine optimale Lösung für die Originaleingabe.
3. Der Algorithmus löst das verbleibende Teilproblem rekursiv (oder mit einem zur Rekursion äquivalenten iterativen Verfahren).

## 10.3. Huffman-Codes
Gegeben: Alphabet A mit $2 ≤ |A| < ∞$ und "Wahrscheinlichkeiten“ oder relativen Häufigkeiten“ $p(a) ∈ [0, 1]$ für jedes $a ∈ A$.
Also: $\sum_{a \in A} p(a) = 1$

Gesucht: ein "guter" binärer Präfixcode für (A, p)
Definition Präfixcode: Jedem $a ∈ A$ ist "binärer Code“ $c(a) ∈ {0, 1}^∗$ (Menge aller Binärstrings) zugeordnet, mit Eigenschaft Präfixfreiheit: Für $a, b ∈ A, a \not= b$ ist $c(a)$ kein Präfix von $c(b)$.


Kompakte Repräsentation des Codes als Binärbaum. Blätter sind mit Buchstaben markiert; Weg von der Wurzel zum Blatt gibt das
Codewort wieder (links: 0, rechts: 1).

Decodierung: Laufe Weg im Baum, vom Codewort gesteuert, bis zum Blatt. 
Wiederhole mit dem Restwort, bis nichts mehr übrig ist.
Präfixeigenschaft ⇒ keine Zwischenräume nötig.

1. Idee: Mache alle Codewörter $c(a)$ gleich lang. Am besten ist dann eine Länge von $\lceil log_2 |A| \rceil$ Bits. ⇒ $c(a_1 . . . a_m)$ hat Länge $\lceil log 2 |A| \rceil · m$.
2. Idee: Einsparmöglichkeit: Häufige Buchstaben mit kürzeren Wörtern codieren als seltenere Buchstaben. Ein erster Ansatz zur Datenkompression (platzsparendes Speichern, zeitsparendes Übermitteln)! Hier: verlustfreie Kompression“ – Information ist unverändert vorhanden

Ein Codierungsbaum für A ist ein Binärbaum T , in dem
- die Kante in einem inneren Knoten zum linken bzw. rechten Kind (implizit) mit 0 bzw. 1 markiert ist
- jedem Buchstaben $a ∈ A$ ein Blatt (externer Knoten) von T exklusiv zugeordnet ist.
- Der Code $c_T (a)$ für a ist die Kanteninschrift auf dem Weg von der Wurzel zum Blatt mit Inschrift a.
- Die Kosten von T unter p sind definiert als: $B(T, p) = \sum_{a \in A} p(a) · d_T (a)$, $a∈A$ wobei $d_T (a) = |c_T (a)|$ die Tiefe des a-Blatts in T ist.
- Ein Codierungsbaum T für A heißt optimal oder redundanzminimal für p, wenn für alle Codierungsbäume $T_0$ für A gilt: $B(T, p) ≤ B(T_0 , p)$.

Aufgabe: Gegeben (A, p), finde einen optimalen Baum. Methode: "Greedy“
Es seien $a, a_0$ zwei Buchstaben mit $p(a) ≤ p(a_0 ) ≤ p(b)$ für alle $b ∈ A − {a, a_0 }$. ($a , a_0$ sind zwei "seltenste“ Buchstaben.) Dann gibt es einen optimalen Baum, in dem die Blätter für $a$ und $a_0$ "Geschwister“ sind, also Kinder desselben inneren Knotens.

Damit ist der erste Schritt zur Realisierung eines Greedy-Ansatzes getan!
Man beginnt den Algorithmus mit "Mache die beiden seltensten Buchstaben zu Geschwistern“. Dann ist sicher, dass dies stets zu einer optimalen Lösung ausgebaut werden kann. Dann werden diese beiden Buchstaben "zusammengeklebt“, so dass man ein Alphabet erhält, das eine um 1 kleinere Größe hat. Konzeptuell wendet man dann Rekursion an.

Huffman-Algorithmus (rekursiv):
Wir bauen "bottom-up“ einen Baum auf.
- Wenn |A| = 1: Baum hat nur einen (externen) Knoten. (Code für den einen Buchstaben ist das leere Wort. Seltsam, aber als Rekursionsbasis geeignet.) Die Kosten sind 0. (Optimalität ist klar.)
- Wenn |A| > 1, werden zwei "seltenste“ Buchstaben a, a 0 aus A zu benachbarten Blättern gemacht.

Man könnte nach dem angegebenen Muster eine rekursive Prozedur programmieren.
- PQ: Datenstruktur Prioritätswarteschlange,
  - Einträge: Buchstaben und Kunstbuchstaben;
  - Schlüssel: die Gewichte p(b), b (Kunst-)Buchstabe.
- Operationen:
  - PQ.insert: Einfügen eines neuen Eintrags;
  - PQ.extractMin: Entnehmen des Eintrags mit kleinstem Schlüssel.
  - Beide Operationen benötigen logarithmische Zeit (s. Kap. 6).
  - Anfangs in PQ: Buchstaben a ∈ A mit Gewichten p(a) als Schlüssel.
  - Ermitteln und Entfernen der beiden seltensten“ Buchstaben a, a 0 durch zwei Aufrufe ”PQ.extractMin";
  - Einfügen des neuen Kunstbuchstabens b durch PQ.insert(b).
- Resultierende Rechenzeit: $O(n log n)$, für $|A| = n$.



Iterative Implementierung mit ein paar Tricks wird viel effizienter.

Algorithmus Huffman($p[ 1 .. n ]$)
Input: Gewichts-/Wahrscheinlichkeitsvektor $p[ 1 .. n ]$, sortiert: $p [1] ≤ · · · ≤ p [n]$.
Output: Optimaler Baum T , dargestellt als $pred[1..2n − 2]$ und $mark[1..2n − 2]$
```cpp
Erweitere den Vektor p[ 1 .. n ] auf Länge 2n − 1 ;
pred[1] ← n + 1; 
pred[2] ← n + 1;
mark[1] ← 0; 
mark[2] ← 1;
p[n + 1] ← p[1] + p[2] ;
k ← 3 // erster nicht verarbeiteter Knoten in [ 1..n ]
h ← n + 1 // erster nicht verarbeiteter Knoten in [ n + 1..2n − 2 ]
for b from n + 2 to 2n − 1 do // Die folgenden beiden Zeilen finden, in i und j, die Positionen der beiden noch nicht verarbeiteten Buchstaben mit kleinsten Gewichten
  if k ≤ n and p[k] ≤ p[h] 
    then i ← k; 
    k++ 
  else 
    i ← h;
    h++;
  if k ≤ n and (h = b or p[k] ≤ p[h]) 
    then j ← k; 
    k++ 
  else 
    j ← h; 
    h++;
  pred[i] ← b; 
  pred[j] ← b;
  mark[i] ← 0 ; 
  mark[j] ← 1 ;
  p[b] ← p[i] + p[j];
```
Ausgabe: $pred[ 1 .. 2n − 2 ]$ und $mark[ 1 .. 2n − 2 ]$.

Aus $pred[1..2n−2]$ und $mark[1..2n−2]$ baut man den optimalen Huffman-Baum wie folgt:
Alloziere ein Array leaf[1..n] mit Blattknoten-Objekten
und ein Array inner[n + 1..2n − 1] mit Objekten für innere Knoten.
```cpp
for i from 1 to n do
  leaf[i].letter ← Buchstabe a_i
  if mark[i] = 0
    then inner[pred[i]].left ← leaf[i]
  else inner[pred[i]].right ← leaf[i]
for i from (n + 1) to (2n − 2) do
  if mark[i] = 0
    then inner[pred[i]].left ← inner[i]
  else inner[pred[i]].right ← inner[i]
return inner[ 2n − 1 ] // Wurzelknoten
```
Der Algorithmus Huffman ist korrekt und hat Laufzeit $O(n log n)$, wenn n die Anzahl der Buchstaben des Alphabets A bezeichnet.

# 11. Greedy-Algorithmen für Graphprobleme
## 11.1. Kürzeste Wege mit einem Startknoten: Der Algorithmus von Dijkstra
1. Ein gewichteter Digraph $G = (V,E, c)$ besteht aus einem Digraphen $(V,E)$ und einer Funktion $c: E \rightarrow \R$, die jeder Kante $(v,w)$ einen Wert $c(v,w)$ zuordnet.
2. Ein gerichteter Kantenzug $p=(v_0, v_1,...,v_k)$ in G hat Kosten/länge/Gewicht $c(p)=\sum_{1\leq i \leq k} c(v_{i-1}, v_i)$
3. Der (gerichtete) Abstand von $v,w \in V$ ist $d(v,w) :=$ min{c(p) | p Kantenzug von v nach w}
    ($=\infty$ , falls kein Kantenzug von v nach w existiert; $=-\infty$, falls es von v nach w Kantenzüge mit beliebig stark negativen Kosten gibt.)

Hier betrachten wir einen Algorithmus für das Problem "Single-Source-Shortest-Paths (SSSP) (Kürzeste Wege von einem Startknoten aus).
Gegeben: Gewichteter Digraph $G = (V, E, c)$ mit Kantenkosten $c(v, w) ≥ 0$ und $s ∈ V$ .
Gesucht: Für jedes $v ∈ V$ der Abstand $d(s, v)$ und im Fall $d(s, v) < \infty$ ein Weg von s nach v
der Länge $d(s, v)$.
$\rightarrow$ Der Algorithmus von Dijkstra löst dieses Problem.

Algorithmus Dijkstra-Distanzen(G, s)
Eingabe: gewichteter Digraph $G = (V, E, c)$, Startknoten $s ∈ V$
Ausgabe: Länge der kürzesten Wege von s zu den Knoten in G
```cpp
S = ∅;
dist[s] = 0;
for w ∈ V − {s} 
  do dist[w] = ∞;
while ∃u ∈ V − S: dist[u] < ∞ do // "Runde"
  u = ein solcher Knoten u mit minimalem dist[u];
  S = S ∪ {u};
  for w mit (u, w) ∈ E und w $\not ∈$ S do // Nachfolger von u, nicht bearbeitet
    dist[w] = min{dist[w], dist[u] + c(u, w)};
Ausgabe: das Array dist[1..n].
```
Der Algorithmus Dijkstra-Distanzen gibt in $dist[v]$ für alle $v ∈ V$ den Wert $d(s, v) aus.

Wir wollen aber eigentlich nicht nur die Distanzen $d(s, v)$, sondern kürzeste Wege berechnen.
Idee: Für jeden Knoten v merken wir uns, über welche Kante $(u, v)$ Knoten $v$ erreicht wurde.

Algorithmus Dijkstra(G, s)
Eingabe: gewichteter Digraph $G = (V, E, c)$, Startknoten $s ∈ V$
Ausgabe: Länge $d(s, v)$ der kürzesten Wege, Vorgängerknoten $p(v)$
```cpp
S = ∅;
dist[s] = 0; 
p[s] = −2;
for w ∈ V − {s} 
  do dist[w] = ∞; p[w] = −1;
while ∃u ∈ V − S: dist[u] < ∞ do
  u = ein solcher Knoten u mit minimalem dist[u];
  S = S ∪ {u};
  for (u, w) ∈ E mit w $\not ∈$ S do // Nachfolger von u, nicht bearbeitet: update ( u , w )
  dd = dist[u] + c(u, w);
  if dd < dist[w] then
    dist[w] = dd;
    p[w] = u;
Ausgabe: dist[1..n] und p[1..n].
```

Nach dem Algorithmus ist klar, dass $p[v]\not = −1$ ("undefiniert“) genau dann gilt, wenn $dist[v] < \infty$.
Ein (einfacher) Weg $(s = v_0 , v_1 , . . . , v_t )$ in G heißt ein S-Weg, wenn alle Knoten außer eventuell $v_t$ in S liegen.

Ergebnis:
Wenn der Algorithmus von Dijkstra anhält, führen die $p[v]$-Verweise von jedem Knoten v aus entlang eines kürzesten Weges (zurück) zu s. Da die $p[v]$-Verweise keinen Kreis bilden können (mit dem Schritt $S ← S ∪ {u}$ wird der Verweis vom neuen S-Knoten u auf den S-Knoten $p[u]$ endgültig fixiert), bilden die Kanten ($p[v], v$) einen Baum, den sogenannten Baum der kürzesten Wege.

Implementierungsdetails:
Noch zu klären: Wie findet man effizient einen Knoten u mit kleinstem Wert dist[u]?
Verwalte die Knoten $w ∈ V −S$ mit Werten $dist[w] < ∞$ mit den $dist[w]$-Werten als Schlüssel in einer Prioritätswarteschlange PQ. Wenn $dist[w] = ∞$, ist $w$ (noch) nicht in PQ. $extractMin$ liefert den nächsten Knoten u, der zu S hinzugefügt werden soll.

Dijkstra(G, s) // (Vollversion mit Prioritätswarteschlange)
Eingabe: gewichteter Digraph $G = (V, E, c) , V = {1, . . . , n}$ , Startknoten s ;
Ausgabe: Länge $d(s, v)$ der kürzesten Wege, Vorgängerknoten p(v)
Hilfsdatenstrukturen: PQ: eine (anfangs leere) Prioritäts-WS; inS, p, dist: s.o.
```cpp
for w from 1 to n do
  dist[w] = ∞; 
  inS[w] = false; 
  p[w] = −1;
dist[s] = 0; 
p[s] = −2; 
PQ.insert(s);
while not PQ.isempty do
  u = PQ.extractMin; 
  inS[u] = true; // u wird bearbeitet
  for Knoten w mit (u, w) ∈ E and not inS[w] do
    dd = dist[u] + c(u, w);
    if p[w] ≥ 0 and dd < dist[w] then
      PQ.decreaseKey(w,dd); 
      p[w] = u; 
      dist[w] = dd;
    if p[w] = −1 then // w wird soeben entdeckt
      dist[w] = dd; 
      p[w] = u; 
      PQ.insert(w);
Ausgabe: dist[1..n] und p[1..n].
```

Aufwandsanalyse:
Die Prioritätswarteschlange realisieren wir als (binären) Heap.
Maximale Anzahl von Einträgen: n.
Initialisierung: Zeit $O(1)$ für PQ, $O(n)$ für den Rest.
Es gibt maximal $n$ Durchläufe durch die while-Schleife mit Organisationsaufwand jeweils $O(1)$, zusammen also Kosten $O(n)$ für die Schleifenorganisation.
In Schleifendurchlauf Nummer t, in dem $u_t$ bearbeitet wird: PQ.extractMin kostet Zeit $O(log n)$.
Durchmustern der $deg(u_t )$ Nachbarn von $u_t$: Jedes $PQ.insert$ oder $PQ.decreaseKey$ kostet Zeit $O(log n)$.

Der Algorithmus von Dijkstra mit Verwendung einer Prioritätswarteschlange, die als Binärheap realisiert ist, ermittelt kürzeste Wege von Startknoten s aus in einem Digraphen $G = (V, E, c)$ in Zeit $O((n + m) log\ n)$.
Wobei $n = |V |$ (Knotenzahl), $m = |E|$ (Kantenzahl).

Resultierende Rechenzeit für Algorithmus von Dijkstra: $O(m + n\ log\ n)$.
Lineare Rechenzeit für Graphen mit $m = Ω(n log n)$ Kanten.

## 11.2. Minimale Spannbäume: Der Algorithmus von Jarnı́k +Prim
Ein Graph G heißt ein freier Baum (oder nur Baum), wenn er zusammenhängend und kreisfrei ist. Kreisfreie Graphen heißen auch (freie) Wälder.

Wenn $G = (V, E)$ ein Graph mit n Knoten und m Kanten ist, dann sind folgende Aussagen äquivalent:
1. G ist ein Baum.
2. G ist kreisfrei und $m ≥ n − 1$.
3. G ist zusammenhängend und $m ≤ n − 1$.
4. Zu jedem Paar u, v von Knoten gibt es genau einen einfachen Weg von u nach v .
4. G ist kreisfrei, aber das Hinzufügen einer beliebigen weiteren Kante erzeugt einen Kreis (G ist maximal "kreisfrei“).
5. G ist zusammenhängend, aber das Entfernen einer beliebigen Kante erzeugt einen nicht zusammenhängenden Restgraphen ( G ist minimal "zusammenhängend“).

Aus dem Fundamental-Lemma für Bäume folgt, für einen Baum G mit n Knoten:
1. G hat $n − 1$-Kanten.
2. Wenn man zu G eine Kante $(u, w)$ hinzufügt, entsteht genau ein Kreis (aus $(u, w)$ und dem eindeutigen Weg von u nach w in G).
3. Wenn man aus G eine Kante (u, w) streicht, zerfällt der Graph in 2 Komponenten (U und W)

Es sei $G = (V, E)$ ein zusammenhängender Graph. Eine Menge $T ⊆ E$ von Kanten heißt ein Spannbaum für G, wenn $(V, T )$ ein Baum ist.

Es sei $G = (V, E, c)$ ein gewichteter Graph, d.h. $c: E → R$ ist eine "Gewichtsfunktion“ oder "Kostenfunktion“.

Jeder Kantenmenge E ⊆ E wird durch $c(E'):= \sum_{e \in E'} c(e)$ ein Gesamtgewicht zugeordnet. Sei G zusammenhängend. Ein Spannbaum $T ⊆ E$ für G heißt ein minimaler Spannbaum, wenn er minimale Kosten unter allen Spannbäumen hat, d. h. wenn $c(t) = min{c(T') | $ T' Spannbaum für G}. Abkürzung : MST ("Minimum Spanning Tree“).

## 11.3. Algorithmus von Jarnı́k/Prim:
S: Menge von Knoten. Enthält die bisher "erreichten“ Knoten.
R: Menge von Kanten. Enthält die bisher "gewählten“ Kanten.
1. Wähle einen beliebigen (Start-)Knoten $s ∈ V$ . $S ← {s}; R ← ∅;$
2. Wiederhole $(n − 1)$-mal: Wähle eine billigste Kante $(v, u)$, die ein $v ∈ S$ mit einem $u ∈ V − S$ verbindet, d.h. finde $v ∈ S$ und $u ∈ V − S$, so dass $c(v, u)$ minimal unter allen Werten $c(v', u'), v' ∈ S, u' ∈ V − S$, ist.
    $S ← S ∪ {u};$
    $R ← R ∪ {(v, u)};$
3. Ausgabe: R.

### 11.3.1. Schnitteigenschaft
Für den Korrektheitsbeweis des Algorithmus von Jarnı́k/Prim: "Cut property“ – Schnitteigenschaft. Eine Partition $(S, V − S)$ von V mit $∅ = S \not= V$ heißt ein Schnitt.
Eine Menge $R ⊆ E$ heißt erweiterbar (zu einem MST), wenn es einen MST T mit $R ⊆ T$ gibt.

Sei $R ⊆ E$ erweiterbar und sei $(S, V − S)$ ein Schnitt, so dass es keine R-Kante von S nach V − S gibt, und sei $e = (v, w), v ∈ S, w ∈ V −S$ eine Kante, die den Wert $c((v', w')), v' ∈ S, w'∈ V − S$, minimiert; Dann ist auch $R ∪ {e}$ erweiterbar.

### 11.3.2. Implementierungsdetails im Algorithmus von Jarnı́k/Prim:
Wir nehmen an, dass $G = (V, E, c)$ mit $V = {1, . . . , n}$ in Adjazenzlistendarstellung gegeben ist. Die Kantengewichte $c(e)$ stehen in den Adjazenzlisten bei den Kanten. Für jeden Knoten $w ∈ V − S$ wollen wir immer wissen:
1. die Länge der billigsten Kante $(v, w) , v ∈ S,$ falls es eine gibt: in $dist[ w ]$ ("Abstand von S“), für Array $dist[ 1..n ]$.
2. den (einen) Knoten $p(w) ∈ S$ mit $c(p(w), w) = dist[ w ]$, falls ein solcher existiert: in $p[ w ]$ ("Vorgänger in S“), für Array $p[ 1..n ]$.

Solange es von S keine Kante nach w gibt, gilt $dist[ w ] = ∞$ und $p[ w ] = − 1$ .
Verwalte die Knoten $w ∈ V − S$ mit Werten $dist[ w ] < ∞$ mit den $dist[ w ]$-Werten als Schlüssel in einer Prioritätswarteschlange PQ. Wenn $dist[ w ] = ∞$ , ist w (noch) nicht in der PQ.

Eingabe: gewichteter Graph $G = (V, E, c) , V = {1, . . . , n}$ , Startknoten $s ∈ V$ (ist beliebig);
Ausgabe: Ein MST für G.
Hilfsstrukturen: PQ: eine (anfangs leere) Prioritäts-WS; inS, p: wie oben
```cpp
for w from 1 to n do
  dist[w] ← ∞ ; inS[w] ← false; p[w] ← −1 ;
dist[ s ] ← 0 ; p[ s ] ← −2 ; PQ.insert( s );
while not PQ.isempty do
  u ← PQ.extractMin; inS[u] ← true;
  for Knoten w mit ( u , w ) ∈ E and not inS[w] do
    dd ← c( u , w ) ; // einziger Unterschied zu Dijkstra!
    if p[w] ≥ 0 and dd < dist[w] then
      PQ.decreaseKey(w,dd); p[w] ← u; dist[w] ← dd;
    if p[w] = −1 then // w vorher nicht zu S benachbart
      dist[w] ← dd; p[w] ← u; PQ.insert(w);
Ausgabe: T = {(w, p[ w ] ) | inS[ w ] = true , w 6 = s} . // Menge der gewählten Kanten
```
Der Algorithmus von Jarnı́k/Prim mit Verwendung einer Prioritätswarteschlange, die als Binärheap realisiert ist, ermittelt einen minimalen Spannbaum für $G = (V, E, c)$ in Zeit $O((n + m) log\ n)$.

## 11.4. Algorithmus von Kruskal
Starte mit $R = ∅$. Dann folgen $n − 1$ Runden. In jeder Runde:
Wähle eine Kante $e ∈ E − R$ von kleinstem Gewicht, die mit $(V, R)$ keinen Kreis schließt, und füge e zu R hinzu.

Eine offensichtlich korrekte Methode, dies zu organisieren: Durchmustere Kanten in aufsteigender Reihenfolge des Kantengewichts, und nimm eine Kante genau dann in R auf, wenn sie mit R keinen Kreis bildet.

## 11.5. Hilfsstruktur: Union-Find
Union-Find-Datenstrukturen dienen als Hilfsstruktur für verschiedene Algorithmen, insbesondere für den Algorithmus von Kruskal. Zwischenkonfiguration im Algorithmus von Kruskal: Menge $R i−1 ⊆ E$, die Wald bilden, und Folge $e_i , . . . , e_m$ von noch zu verarbeitenden Kanten.

Ansatz: Repräsentiere die Knotenmengen, die den Zusammenhangskomponenten von $(V, R)$ entsprechen, in einer Datenstruktur.
Es soll schnell zu ermitteln sein, ob zwei Knoten in derselben Komponente/Menge liegen. Wenn wir einen Schritt des Kruskal-Algorithmus ausführen, bei dem eine Kante akzeptiert, also in R aufgenommen wird, müssen wir zwei der disjunkten Mengen vereinigen.

Eine Partition (In der Mathematik heißt die gesamte Aufteilung Partition, die Teile Klassen) von ${1, 2, . . . , n}$ ist eine Zerlegung in Mengen (hier: Klassen“) ${1, 2, . . . , n} = S_1 ∪ S_2 ∪ · · · ∪ S_l$, wobei $S_1 , S_2 , . . . , S_l$ disjunkt sind.

Operationen:
- $init(n)$: Erzeugt zu $n ≥ 1$ die diskrete Partition“ mit den n einelementigen Klassen ${1}, {2}, . . . , {n}$, also $K_i = {i}$.
- $find(i)$: Gibt zu $i ∈ {1, . . . , n}$ den Namen $r(i)$ der Klasse $K_{r(i)}$ aus, in der sich i (gegenwärtig) befindet.
- $union(s, t)$: Die Argumente s und t müssen Repräsentanten verschiedener Klassen $K_s$ bzw. $K_t$ sein. Die Operation ersetzt in der Partition $K_s$ und $K_t$ durch die Vereinigung $K_s ∪ K_t$. Als Repräsentant von $K_s ∪ K_t$ kann ein beliebiges Element verwendet werden. (Meistens: s oder t.)

Algorithmus von Kruskal mit Union-Find
Input: Gewichteter zusammenhängender Graph $G = (V, E, c)$ mit $V = {1, . . . , n}$.
1. Schritt: Sortiere Kanten $e_1 , . . . , e_m$ nach Gewichten $c_1 = c(e_1), . . . , c_m = c(e_m )$ aufsteigend. Resultat: Kantenliste $(v_1 , w_1 , c_1 ), . . . , (v_m , w_m , c_m ), c_1 ≤ · · · ≤ c_m$.
2. Schritt: Initialisiere Union-Find-Struktur für ${1, . . . , n}$.
3. Schritt: Für $i = 1, 2, . . . , m$ tue folgendes:
   - $s = find(v_i )$;$ t ← find(w_i )$;
   - $if s \not= t$ then begin $R ← R ∪ {e_i}$; $union(s, t)$ end; 
   - // Optional: Beende Schleife, wenn $|R| = n − 1$.
4. Schritt: Die Ausgabe ist R.

1. Der Algorithmus von Kruskal in der Implementierung mit Union-Find ist korrekt.
2. Die Rechenzeit des Algorithmus ist $O(m\ log\ n)$, wenn man die Union-Find-Datenstruktur mit Arrays implementiert.
3. Die Rechenzeit des Algorithmus ist $O(m\ log\ n)$, wenn man die Union-Find-Datenstruktur mit mit wurzelgerichteten Bäumen (mit Pfadkompression) implementiert.

```cpp
Prozedur init(n) // Initialisierung einer Union-Find-Struktur
Erzeuge r, size, next: Arrays der Länge n für int-Einträge
for i from 1 to n do
  r[i] = i;
  size[i] = 1;
  next[i] = 0.
```
Zeitaufwand: $Θ(n)$.

```cpp
Prozedur find(i)
  return r[i]
```
Zeitaufwand: $O(1)$

```cpp
Prozedur union(s, t)
// Ausgangspunkt: s, t sind verschiedene Repräsentanten
if size[s] > size[t] then vertausche s, t; // nun: size[s] ≤ size[t]
  z = s;
  r[z] = t;
  while next[z] 6 = 0 do // durchlaufe L_s , setzt r-Werte um
    z = next[z];
    r[z] = t;
  // nun: z enthält letztes Element von L s ; next[z] = 0
  // L s nach dem ersten Eintrag in L t einhängen:
next[z] = next[t]; next[t] = s;
size[t] = size[t] + size[s].
```
Aufwand: $O$(Länge der kürzeren der Listen $L_s , L_t$ ) .

In der Implementierung der Union-Find-Struktur mit Arrays hat jede find-Operation Rechenzeit $O(1), n − 1$ union-Operationen haben Rechenzeit $O(n\ log\ n)$.

Union-find Prozedur mit Baumimplementierung
```cpp
j = i ;
jj = p[j];
while jj != j do //verfolge Vorgängerzeiger bis zur Wurzel
  j ← jj;
  jj ← p[j] ;
return j
```
Ein $find(i)$ für jedes $i ∈ {1, . . . , n}$ führt zu Gesamtkosten $Θ(n^2)$!

## 11.6. Pfadkompression
Eine interessante Variante der Union-Find-Datenstruktur, die mit einem wurzelgerichteten Wald implementiert ist, ist der Ansatz der "Pfadkompression“ (oder Pfadverkürzung). Bei einem $find(i)$ muss man den ganzen Weg von Knoten i zu seiner Wurzel $r(i)$ ablaufen; Aufwand $O(depth(i))$.
Ein gutes strategisches Ziel ist also, diese Wege möglichst kurz zu halten.
Idee: Man investiert bei $find(i)$ etwas mehr Arbeit, jedoch immer noch im Rahmen $O(depth(i))$, um dabei einige Wege zu verkürzen und damit spätere finds billiger zu machen.
Jeder Knoten $i = i_0 , i_1 , . . . , i_{d−1}$ auf dem Weg von i zur Wurzel $i_d = r(i)$ wird direkt als Kind an die Wurzel gehängt. Kosten pro Knoten/Ebene: $O(1)$, insgesamt also $O(depth(i))$.

```cpp
Prozedur find (i) // Pfadkompressions-Version
  j = i ;
  // verfolge Vorgängerzeiger bis zur Wurzel r(i) :
  jj = p[j];
  while jj != j do
    j = jj;
    jj = p[j] ;
  r = j; // r enthält nun Wurzel r(i)
  // Erneuter Lauf zur Wurzel, Vorgängerzeiger umhängen:
  j = i ;
  jj = p[j];
  while jj != j do
    p[j] = r;
    j = jj;
    jj = p[j];
  return r
```

# 12. Dynamische Programmierung
Algorithmenparadigma für Optimierungsprobleme. Typische Schritte:
- Definiere (viele) "Teilprobleme" (einer Instanz)
- Identifiziere einfache Basisfälle
- Formuliere eine Version der Eigenschaft: **Substrukturen optimaler Strukturen sind optimal**
- Finde Rekursionsgleichungen für Werte optimaler Lösungen: **Bellmansche Optimalitätsgleichungen**
- Berechne optimale Werte (und Strukturen) iterativ.

## 12.1. Das All-Pairs-Shortest-Paths-Problem
Das "APSP-Problem" ist zentrales Beispiel für die Strategie "Dynamische Programmierung“.
Kürzeste Wege zwischen allen Paaren von Knoten.

Der im Folgenden beschriebene Algorithmus von Floyd–Warshall kann auch mit negativen Kantengewichten umgehen.

Es gibt keine Kreise mit (strikt) negativer Gesamtlänge, d.h. $v=v_0,v_1,...,v_r \Rightarrow \sum_{1\leq s \leq r} c(v_{s-1}, v_s) \leq 0$
1.  Wenn p Kantenzug von v nach w ist, dann existiert auch ein (einfacher) Weg $p_0$ von v nach w mit $c(p_0 ) ≤ c(p)$.
2.  Wenn es einen Kantenzug von v nach w gibt, dann auch einen mit minimaler Länge (einen kürzesten Weg“).

Für Digraphen $G = (V, E, c)$ definieren wir: $S(v, w) :=$ die Länge eines kürzesten Weges von v nach w.

Bellmansche Optimalitätsgleichungen\
Knoten k kommt im Inneren von p entweder einmal oder gar nicht vor.
- Falls k in p nicht vorkommt, ist p kürzester $(k − 1)$-Weg von v nach w
- Falls k im Inneren von p vorkommt, zerfällt p in zwei Teile die beide kürzeste $(k − 1)$-Wege sind.
Die Bellmanschen Optimalitätsgleichungen für den Algorithmus von Floyd-Warshall lauten dann:
  $S(v,w,k) = min{S(v,w,k-1), S(v,k,k-1)+ S(k,w,k-1)}$, für $1 \leq v, w\leq n, 1 \leq k \leq n$
```cpp
S[v,v,0] = 0;
S[v,w,0] = c(v, w);
for k from 1 to n do
  for v from 1 to n do
    for w from 1 to n do
      S[v,w,k] = min{ S[v,w,k-1] , S[v,k,k-1] + S[k,w,k-1] }
```

Algorithmus Floyd-Warshall(C[ 1 .. n , 1 .. n ])
Eingabe: C[ 1 .. n , 1 .. n ]: Matrix der Kantenkosten/-längen c(v, w) in R ∪ {+∞}
Ausgabe: S[ 1 .. n , 1 .. n ]: Kosten S(v, w) eines kürzesten v - w -Weges
I[ 1 .. n , 1 .. n ]: minimaler maximaler Knoten auf einem kürzesten v - w -Weg
```cpp
for v from 1 to n do
  for w from 1 to n do
    if v = w then S[v,v] ← 0 ; I[v,v] ← 0
    else S[v,w] ← C[v,w];
      if S[v,w] < ∞ then I[v,w] ← 0 else I[v,w] ← −1 ;
for k from 1 to n do
  for v from 1 to n do
    for w from 1 to n do
      if S[v,k] + S[k,w] < S[v,w] then
        S[v,w] ← S[v,k] + S[k,w]; I[v,w] ← k;
```
Ausgabe: S[ 1 .. n , 1 .. n ] und I[ 1 .. n , 1 .. n ].
Der Algorithmus von Floyd-Warshall löst das All-Pairs-Shortest-Paths-Problem in Rechenzeit $O(n^3)$ und Speicherplatz $O(n^2 )$.
Das Ergebnis ist eine Datenstruktur der Größe $O(n^2 )$, mit der sich zum Argument $(v, w)$ mit Algorithmus printPath ein kürzester Weg von v nach w in Zeit $O$(#(Kanten auf dem Weg)) ausgeben lässt.

## 12.2. Der Bellman–Ford-Algorithmus
Zweck: Kürzeste Wege von einem Startknoten s aus in gewichtetem Digraphen $(V, E, c)$. (SSSP: "Single Source Shortest Paths“). Anders als beim Algorithmus von Dijkstra sind negative Kantenkosten zugelassen.

Grundoperation, schon aus dem Dijkstra-Algorithmus bekannt:
```cpp
update(u, v) // für (u, v) ∈ E
  if dist[u] + c(u, v) < dist[v] then
    p[v] ← u;
    dist[v] ← dist[u] + c(u, v) ;
```

Algorithmus Bellman-Ford( $((V, E, c), s)$ )
Eingabe: $(V, E, c)$ : Digraph mit Kantengewichten in $R , s ∈ V$: Startknoten
Ausgabe: Wenn G keine Kreise mit negativem Gewicht hat:
  - In $dist[ v ]$: Abstand $d(s, v)$;
  - In $p[ 1 .. n ]$: Baum von kürzesten Wegen (wie bei Dijkstra);
```cpp
Initialisierung:
  for v from 1 to n do
    dist[v] ← ∞ ; p[v] ← −1 ;
  dist[ s ] ← 0 ; p[ s ] ← −2 ; // wird nie geändert, wenn kein negativer Kreis existiert
Hauptschleife:
  for i from 1 to n − 1 do // heißt nur: wiederhole (n − 1) -mal
    forall (u, v) ∈ E do update (u, v) ; // beliebige Reihenfolge
Zyklentest:
  forall (u, v) ∈ E do
    if dist[ u ] + c(u, v) < dist[ v ] then return "negativer Kreis";
Ergebnis:
  return dist[ 1 .. n ], p[ 1 .. n ]
```

Der Bellman-Ford-Algorithmus hat folgendes Verhalten:
1. Wenn es keinen von s aus erreichbaren Kreis mit negativer Gesamtlänge gibt ("negativer Kreis"), steht am Ende des Algorithmus in dist[v] die Länge eines kürzesten Weges von s nach v, und die Kanten $(p[w], w)$ (mit p[w] > 0) bilden einen Baum der kürzesten Wege von s aus zu den erreichbaren Knoten.
2. Der Algorithmus gibt "negativer Kreis“ aus genau dann wenn es einen von s aus erreichbaren negativen Kreis gibt.
3. Die Rechenzeit ist $O(nm)$

## 12.3. Editierdistanz
Problemstellung: Sei A ein Alphabet. (Bsp.: Lat. Alphabet, ASCII-Alphabet, { A,C,G,T } .)
Wenn $x = a_1 . . . a_m ∈ A$ und $y = b_1 . . . b_n ∈ A$ zwei Zeichenreihen über A sind, möchte man herausfinden, wie ähnlich (oder unähnlich) sie sind. Wie können wir Ähnlichkeit“ messen?
Wir definieren Elementarschritte (Editier-Operationen), die einen String verändern:
- Lösche einen Buchstaben aus einem String: Aus uav wird uv ($u, v ∈ A, a ∈ A$).
    Beispiel: Haut → Hut.
- Füge einen Buchstaben in einen String ein: Aus uv wird uav ($u, v ∈ A , a ∈ A$).
    Beispiel: Hut → Haut.
- Ersetze einen Buchstaben: Aus uav wird ubv ($u, v ∈ A, a, b ∈ A$).
    Beispiel: Haut → Hast.
Der "Abstand" oder die Editierdistanz $d(x, y)$ von x und y ist die minimale Anzahl von Editieroperationen, die benötigt werden, um x in y zu transformieren.

Man schreibt Strings aus Buchstaben und dem Sonderzeichen - untereinander, wobei die beiden Zeilen jeweils das Wort x bzw. y ergeben, wenn man die -’s ignoriert. Die Kosten einer solchen Anordnung: Die Anzahl der Positionen, an denen die oberen und unteren Einträge nicht übereinstimmen. Die Kosten, die eine solche Anordnung erzeugt, sind gleich der Anzahl der Editierschritte in einer Transformation.


Das Problem "Editierdistanz" wird folgendermaßen beschrieben:
Input: Strings $x = a_1 . . . a_m , y = b_1 . . . b_n$ aus A.
Aufgabe: Berechne $d(x, y)$ (und eine Editierfolge, die x in y transformiert).
Ansatz: Dynamische Programmierung
Unser Beispiel: x = Exponentiell und y = Polynomiell.
1. Schritt: Relevante Teilprobleme identifizieren! Betrachte Präfixe $x[1..i] = a_1 . . . a_i$ und $y[1..j] = b_1 . . . b_j$ , und setze $E(i,j):=d(x[1...i],y[1...j])$, für $0\leq i \leq m, 0\leq j \leq n$

Die Zahlen E(i, j) berechnen wir iterativ, indem wir sie in eine Matrix $E[0..m,0..n]$ eintragen. Dies liefert den DP-Algorithmus für die Editierdistanz.
Initialisierung:
$$E[i,0] = i, für i = 0, . . . , m$$
$$E[0,j] = j, für j = 0, . . . , n$$
Dann füllen wir die Matrix (z. B.) zeilenweise aus, genau nach den Bellmanschen
Optimalitätsgleichungen:
```cpp
for i from 1 to m do
  for j from 1 to n do
    E[i,j] = min{E[i-1,j-1] + diff(a_i, b_j), E[i-1,j] + 1, E[i,j-1] + 1};
return E[m,n]
```
Rechenzeit: $O(m * n)$

## 12.4. Optimale Matrizenmultiplikation
Multiplikation von zwei Matrizen über einem Ring R: Gegeben $A_1$ und $A_2$ berechne Product $C:= A_1*A_2$
Standardmethode benötigt $r_0 r_1 r_2$ R-Multiplikationen, $r_0(r_1 − 1)r_2) R-Additionen. Gesamtrechenzeit: $Θ(r_0 r_1 r_2 )$.

Die Matrizenmultiplikation ist assoziativ. Gesucht wird eine ("optimale") Klammerung, die bei der Berechnung von $A_1 ·· · ··A_k$ die Gesamtkosten (= Anzahl aller R-Multiplikationen) minimiert.

Optimale Klammerung für $A_i · · · A_j$ ist $(A_i · · · A_l)(A_{l+1} · · · A_j )$, wobei die Klammerungen in den beiden Teilen optimal sein müssen. "Bellmansche Optimalitätsgleichungen“:
$$c(r_{i-1},...,r_j)= min{c(r_{i-1,...,r_l}) +c(r_l,...,r_j) +r_{i-1}r_l r_j | i \leq l < j }$$

MatrixOptimal($(r_0, . . . , r_k )$)
Eingabe: Dimensionsvektor $(r_0, . . . , r_k )$
Ausgabe: Kosten $c(r_0 , . . . , r_k )$ bei der optimalen Klammerung $l[1 .. k , 1 .. k ]$: Plan zur Ermittlung der optimalen Unterteilung;
Datenstruktur: Matrizen $C[ 1 .. k , 1 .. k ], l[ 1 .. k , 1 .. k ]$
Ziel: 
  - $C[ i , j ]$ enthält $c(r_{i−1} , . . . , r_j )$
  - $l[ i , j ]$ enthält Index zur Unterteilung der Multiplikation bei $A_i · · · A_j$
```cpp
for i from 1 to k 
  do C[i,i] = 0;
for i from 1 to k−1 
  do C[i,i+1] = r_i − 1 * r_i * r_i + 1;
for d from 2 to k−1 do
  for i from 1 to k − d do
    bestimme das l, i ≤ l < i+d, das C=C[i,l]+ C[l+1,i+d] + r_{i-1}*r_l*r_{i+d} minimiert;
    l[i,i+d] = dieses l;
    C[i,i+d] = das minimale C;
Ausgabe: C[1..k, 1..k] und l[1..k, 1..k]
```
Laufzeit: Die Minimumssuche in Zeilen (5)–(6) kostet Zeit $O(k)$; mit den geschachtelten Schleifen (3)–(8) und (4)–(8) ergibt sich eine Rechenzeit von $Θ(k^3)$.


# 13. Prüfung
Prüfungsstoff: Vorlesung + Übungsaufgaben.
Prüfungsklausur: 150 Minuten, 150 Punkte.
max. 15 Bonuspunkte über Zwischenklausur (40 Minuten)

- [1. Vorbereitung](#1-vorbereitung)
  - [1.1. O-Notation](#11-o-notation)
  - [1.2. Spezifkationstechnik für Datentypen](#12-spezifkationstechnik-für-datentypen)
  - [1.3. Implementierungen fundamentaler Datentypen](#13-implementierungen-fundamentaler-datentypen)
  - [1.4. Auswahlkriterien für elementare Datenstrukturen kennen und anwenden](#14-auswahlkriterien-für-elementare-datenstrukturen-kennen-und-anwenden)
  - [1.5. Kenntnis grundlegender Entwurfsstrategien](#15-kenntnis-grundlegender-entwurfsstrategien)
  - [1.6. Kenntnis grundlegender Algorithmen und ihrer Eigenschaften](#16-kenntnis-grundlegender-algorithmen-und-ihrer-eigenschaften)
  - [1.7. Auswahlkriterien für Algorithmen, insbesondere Ressourcenverbrauch, kennen und anwenden](#17-auswahlkriterien-für-algorithmen-insbesondere-ressourcenverbrauch-kennen-und-anwenden)
  - [1.8. Standard-Analysemethoden für Ressourcenverbrauch (Rechenzeit, Speicherplatz)](#18-standard-analysemethoden-für-ressourcenverbrauch-rechenzeit-speicherplatz)
  - [1.9. Korrektheitsbeweise für Algorithmen verstehen und darstellen](#19-korrektheitsbeweise-für-algorithmen-verstehen-und-darstellen)
- [2. Einführung und Grundlagen](#2-einführung-und-grundlagen)
  - [2.1. Beispiel: Sortieren](#21-beispiel-sortieren)
    - [2.1.1. Ist dieser Algorithmus Korrekt?](#211-ist-dieser-algorithmus-korrekt)
    - [2.1.2. Wie lange dauern Berechnungen mit diesem Algorithmus?](#212-wie-lange-dauern-berechnungen-mit-diesem-algorithmus)
  - [2.2. Was ist ein Algorithmus](#22-was-ist-ein-algorithmus)
    - [2.2.1. Was ist mit nicht abbrechenden Berechnungen?](#221-was-ist-mit-nicht-abbrechenden-berechnungen)
  - [2.3. Merkmale eines Algorithmus](#23-merkmale-eines-algorithmus)
  - [2.4. Erweiterung des Algorithmusbegriffs](#24-erweiterung-des-algorithmusbegriffs)
      - [2.4.0.1. Varianten](#2401-varianten)
      - [2.4.0.2. Spezikation des Sortierproblems](#2402-spezikation-des-sortierproblems)
      - [2.4.0.3. Alternative Formulierung des Sortierproblems:](#2403-alternative-formulierung-des-sortierproblems)
      - [2.4.0.4. Löst Insertionsort das Sortierproblem?](#2404-löst-insertionsort-das-sortierproblem)
    - [2.4.1. Laufzeitanalysen](#241-laufzeitanalysen)
      - [2.4.1.1. Kosten Rechenzeiten](#2411-kosten-rechenzeiten)
        - [2.4.1.1.1. "Worst Case" Kosten allgemein](#24111-worst-case-kosten-allgemein)
        - [2.4.1.1.2. "Best Case" Kosten allgemein](#24112-best-case-kosten-allgemein)
        - [2.4.1.1.3. "Average Case" auf Insertionsort](#24113-average-case-auf-insertionsort)
        - [2.4.1.1.4. "Average Case" Kosten allgemein](#24114-average-case-kosten-allgemein)
      - [2.4.1.2. Analyse von Kosten/Rechenzeit](#2412-analyse-von-kostenrechenzeit)
- [3. Fundamentale Datentypen und Datenstrukturen](#3-fundamentale-datentypen-und-datenstrukturen)
  - [3.1. Stacks und dynamische Arrays](#31-stacks-und-dynamische-arrays)
    - [3.1.1. Spezikation des Datentyps "Stack über D"](#311-spezikation-des-datentyps-stack-über-d)
      - [3.1.1.1. Spezikation des Datentyps (ADT) "Stack über D" - Alternative](#3111-spezikation-des-datentyps-adt-stack-über-d---alternative)
      - [3.1.1.2. Implementierung von Stacks](#3112-implementierung-von-stacks)
        - [3.1.1.2.1. Listenimplementierung von Stacks](#31121-listenimplementierung-von-stacks)
        - [3.1.1.2.2. Arrayimplementierung von Stacks](#31122-arrayimplementierung-von-stacks)
        - [3.1.1.2.3. Vergleich Listen-/Arrayimplementierung](#31123-vergleich-listen-arrayimplementierung)
      - [3.1.1.3. Datentyp "Dynamische Arrays"](#3113-datentyp-dynamische-arrays)
  - [3.2. Queues (Warteschlangen, FIFO-Listen)](#32-queues-warteschlangen-fifo-listen)
    - [3.2.1. Spezifikation des Datentypes "Queue" über D](#321-spezifikation-des-datentypes-queue-über-d)
    - [3.2.2. Implementierung von Queues](#322-implementierung-von-queues)
        - [3.2.2.0.1. TODO](#32201-todo)
- [4. Binärbaume](#4-binärbaume)
  - [4.1. Grundlagen](#41-grundlagen)
  - [4.2. Definition](#42-definition)
  - [4.3. Operationen](#43-operationen)
  - [4.4. Terminologie](#44-terminologie)
  - [4.5. TIPL und TEPL](#45-tipl-und-tepl)
    - [4.5.1. Totale innere Weglänge (Total internal path length)](#451-totale-innere-weglänge-total-internal-path-length)
    - [4.5.2. Totale äußere Weglänge (Total external path length)](#452-totale-äußere-weglänge-total-external-path-length)
  - [4.6. Baumdurchläufe](#46-baumdurchläufe)
    - [4.6.1. Inorder Durchlauf](#461-inorder-durchlauf)
    - [4.6.2. Präorder Durchlauf](#462-präorder-durchlauf)
    - [4.6.3. Postorder Durchlauf](#463-postorder-durchlauf)
    - [4.6.4. Kombi Durchlauf](#464-kombi-durchlauf)
    - [4.6.5. Zeitanalyse für Baumdurchlauf](#465-zeitanalyse-für-baumdurchlauf)
- [5. Hashverfahren](#5-hashverfahren)
  - [5.1. Hashing mit Verketteten Listen](#51-hashing-mit-verketteten-listen)
    - [5.1.1. Wir implementieren die Wörterbuchoperationen: Algorithmen](#511-wir-implementieren-die-wörterbuchoperationen-algorithmen)
    - [5.1.2. Verdoppelungsstrategie](#512-verdoppelungsstrategie)
  - [5.2. Hashfunktionen](#52-hashfunktionen)
    - [5.2.1. Einfache Hashfunktionen](#521-einfache-hashfunktionen)
      - [5.2.1.1. Fall: Schlüssel sind natürliche Zahlen: $U \subseteq \N$](#5211-fall-schlüssel-sind-natürliche-zahlen-eqmathsemanticsmrowmiumimomomi-mathvariantdouble-strucknmimrowannotation-encodingapplicationx-texu-subseteq-nannotationsemanticsmathuneq)
        - [5.2.1.1.1. Divisionsrestmethode](#52111-divisionsrestmethode)
        - [5.2.1.1.2. Diskrete Multiplikationsmethode](#52112-diskrete-multiplikationsmethode)
      - [5.2.1.2. Fall: Schlüssel sind Strings/Wörter: $U \subseteq Seq(\sum)$](#5212-fall-schlüssel-sind-stringswörter-eqmathsemanticsmrowmiumimomomismimiemimiqmimo-stretchyfalsemomomomo-stretchyfalsemomrowannotation-encodingapplicationx-texu-subseteq-seqsumannotationsemanticsmathuseqeq)
        - [5.2.1.2.1. Lineare Funktionen über Körper $\Z_p = [p] = {0,...,p-1}$](#52121-lineare-funktionen-über-körper-eqmathsemanticsmrowmsubmi-mathvariantdouble-struckzmimipmimsubmomomo-stretchyfalsemomipmimo-stretchyfalsemomomomrowmn0mnmo-separatortruemomi-mathvariantnormalmimi-mathvariantnormalmimi-mathvariantnormalmimo-separatortruemomipmimomomn1mnmrowmrowannotation-encodingapplicationx-texz_p--p--0p-1annotationsemanticsmathzpp0p1eq)
    - [5.2.2. Anspruchsvolle Hashfunktionen](#522-anspruchsvolle-hashfunktionen)
  - [5.3. Geschlossenes Hashing](#53-geschlossenes-hashing)
    - [5.3.1. Lineares Sondieren](#531-lineares-sondieren)
    - [5.3.2. Quadratisches Sondieren](#532-quadratisches-sondieren)
    - [5.3.3. Doppel Hashing](#533-doppel-hashing)
    - [5.3.4. Uniformes Sondieren / Ideales Hashing](#534-uniformes-sondieren--ideales-hashing)
  - [5.4. Löschen](#54-löschen)
  - [5.5. Cuckoo Hashing](#55-cuckoo-hashing)
- [6. Sortierverfahren](#6-sortierverfahren)
  - [6.1. Mergesort](#61-mergesort)
  - [6.2. Quicksort](#62-quicksort)
  - [6.3. Heapsort](#63-heapsort)
    - [6.3.1. Heap reparieren](#631-heap-reparieren)
    - [6.3.2. Heap sortieren](#632-heap-sortieren)
    - [6.3.3. Heap aufbauen](#633-heap-aufbauen)
      - [6.3.3.1. HeapSort](#6331-heapsort)
  - [6.4. Datentyp: Prioritätswarteschlange (oder Vorrangwarteschlangen)](#64-datentyp-prioritätswarteschlange-oder-vorrangwarteschlangen)
    - [6.4.1. Technisches Problem, noch zu klären:](#641-technisches-problem-noch-zu-klären)
  - [6.5. Untere Schranke für Sortieren](#65-untere-schranke-für-sortieren)
  - [6.6. Sortieren in Linearzeit](#66-sortieren-in-linearzeit)
    - [6.6.1. Countingsort – Sortieren durch Zählen](#661-countingsort--sortieren-durch-zählen)
    - [6.6.2. Bucketsort – Fachsortieren](#662-bucketsort--fachsortieren)
    - [6.6.3. Radixsort – Mehrphasen-Counting-/Bucketsort](#663-radixsort--mehrphasen-counting-bucketsort)
- [7. Graphen, Digraphen und Breitensuche](#7-graphen-digraphen-und-breitensuche)
  - [7.1. Datenstrukturen für Digraphen und Graphen](#71-datenstrukturen-für-digraphen-und-graphen)
  - [7.2. Breitensuche in Digraphen](#72-breitensuche-in-digraphen)
    - [7.2.1. Breitensuche von einem Knoten $v_0$ aus:](#721-breitensuche-von-einem-knoten-eqmathsemanticsmrowmsubmivmimn0mnmsubmrowannotation-encodingapplicationx-texv_0annotationsemanticsmathv0eq-aus)
    - [7.2.2. Globale Breitensuche in G](#722-globale-breitensuche-in-g)
- [8. Tiefensuche](#8-tiefensuche)
  - [8.1. einfache Tiefensuche in Digraphen](#81-einfache-tiefensuche-in-digraphen)
  - [8.2. Volle Tiefensuche in Digraphen](#82-volle-tiefensuche-in-digraphen)
  - [8.3. Tiefensuche in ungerichteten Graphen](#83-tiefensuche-in-ungerichteten-graphen)
  - [8.4. Kreisfreiheitstest und topologische Sortierung](#84-kreisfreiheitstest-und-topologische-sortierung)
  - [8.5. Starke Zusammenhangskomponenten in Digraphen](#85-starke-zusammenhangskomponenten-in-digraphen)
- [9. Divide-and-Conquer-Algorithmen](#9-divide-and-conquer-algorithmen)
  - [9.1. Multiplikation ganzer Zahlen](#91-multiplikation-ganzer-zahlen)
  - [9.2. Matrixmultiplikation](#92-matrixmultiplikation)
  - [9.3. Master Theorem](#93-master-theorem)
  - [9.4. Das Selektionsproblem](#94-das-selektionsproblem)
- [10. Greedy-Algorithmen: Prinzipien](#10-greedy-algorithmen-prinzipien)
  - [10.1. Beispiel 1: Hörsaalbelegung](#101-beispiel-1-hörsaalbelegung)
  - [10.2. Beispiel 2: Fraktionales ("teilbares") Rucksackproblem](#102-beispiel-2-fraktionales-teilbares-rucksackproblem)
  - [10.3. Huffman-Codes](#103-huffman-codes)
- [11. Greedy-Algorithmen für Graphprobleme](#11-greedy-algorithmen-für-graphprobleme)
  - [11.1. Kürzeste Wege mit einem Startknoten: Der Algorithmus von Dijkstra](#111-kürzeste-wege-mit-einem-startknoten-der-algorithmus-von-dijkstra)
  - [11.2. Minimale Spannbäume: Der Algorithmus von Jarnı́k +Prim](#112-minimale-spannbäume-der-algorithmus-von-jarnı́k-prim)
  - [11.3. Algorithmus von Jarnı́k/Prim:](#113-algorithmus-von-jarnı́kprim)
    - [11.3.1. Schnitteigenschaft](#1131-schnitteigenschaft)
    - [11.3.2. Implementierungsdetails im Algorithmus von Jarnı́k/Prim:](#1132-implementierungsdetails-im-algorithmus-von-jarnı́kprim)
  - [11.4. Algorithmus von Kruskal](#114-algorithmus-von-kruskal)
  - [11.5. Hilfsstruktur: Union-Find](#115-hilfsstruktur-union-find)
  - [11.6. Pfadkompression](#116-pfadkompression)
- [12. Dynamische Programmierung](#12-dynamische-programmierung)
  - [12.1. Das All-Pairs-Shortest-Paths-Problem](#121-das-all-pairs-shortest-paths-problem)
  - [12.2. Der Bellman–Ford-Algorithmus](#122-der-bellmanford-algorithmus)
  - [12.3. Editierdistanz](#123-editierdistanz)
  - [12.4. Optimale Matrizenmultiplikation](#124-optimale-matrizenmultiplikation)
- [13. Prüfung](#13-prüfung)