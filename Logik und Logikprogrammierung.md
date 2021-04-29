# Logik
Die Logik 
- versucht, gültige Argumentationen von ungültigen zu unterscheiden,
- hat Anwendungen in der Informatik,
- formalisiert die zu untersuchenden Aussagen und
- beschränkt sich auf einen wohldefinierten Teil der möglichen Aussagen => es gibt verschiedene "Logiken", z.B. "Aussagen-" und "Prädikatenlogik"
    - daneben: 
      - temporale Logiken (Mastervorlesung "Verifikation")
      - modale Logiken
      - epistemische Logiken
      - ...


## Syllogismen
Aristoteles (384-322 v.Chr.) untersuchte das Wesen der Argumentation und des logischen Schließens mit dem Ziel, korrekte von inkorrekten Argumenten zu unterscheiden.
Verschiedene Werke, u.a. Analytica priora, Analytica posteriora.

Aristoteles nennt die logischen Schlußfolgerungen Syllogismen (griechisch: "Zusammenrechnung").

Ein Syllogismus ist eine Aussage, in der bestimmte Dinge [die Prämissen] behauptet werden und in der etwas anderes [die Konsequenz], unumgänglich aus dem Behaupteten folgt. Mit dem letzten Satz meine ich, dass die Prämissen die Konsequenz zum Resultat haben, und damit meine ich, dass keine weitere Prämisse erforderlich ist, um die Konsequenz unumgänglich zu machen.

#### Beispiele
```
Wenn alle Menschen sterblich sind und
Sokrates ein Mensch ist,
dann ist Sokrates sterblich.
```
```
Wenn eine Zahl gerade und größer als zwei ist,
dann ist sie keine Primzahl.
```
```
Wenn die Leitzinsen hoch sind,
dann sind die Börsianer unzufrieden.
```

Aristoteles identifizierte einige zulässige Syllogismen, die Scholastiker fügten weitere hinzu:

(Barbara)
```
Alle Dackel sind Hunde                  Alle P sind M
Alle Hunde sind Tiere                   Alle M sind S
Dann sind alle Dackel Tiere             Alle P sind S
```

(Cesare)
```
Keine Blume ist ein Tier                Kein P ist M
Alle Hunde sind Tiere                   Alle S sind M
Dann ist keine Blume ein Hund           Kein P ist S
```

(Darapti)
```
Alle Delfine leben im Meer              Alle M sind P
Alle Delfine sind Säugetiere            Alle M sind S
Dann leben einige Säugetiere im Meer    Einige S sind P
```

### Kalküle
Gottfried Wilhelm Leibniz (1646-1716) wollte korrekte von inkorrekten Argumentationsketten unterscheiden. Hierzu sollte ein Kalkül entwickelt werden, in dem alle korrekten Argumentationsketten ermöglicht sind (und keine inkorrekten).

David Hilbert (1862-1943) entwickelte solche Kalküle.
Diese "Hilbertkalküle" sind sehr verschieden von üblichen Argumentationsmustern.

Gerhard Gentzen (1909-1945) entwickelte Kalküle des "natürlichen Schließens", die übliche Argumentationsmuster formalisieren.

### Die Aussagenlogik
George Boole (1815 - 1864) entwickelte einen Kalkül zum Rechnen mit atomare Aussagen, die entweder wahr oder falsch sein können.

Verknüpfung durch Operatoren(und, oder, nicht, wenn-dann... ).

### Die Prädikatenlogik (Ende des 19. Jahrhunderts)
Gottlob Frege (1848-1925), Giuseppe Peano (1858-1932) und Bertrand Russell (1872-1970)entwickelten die Logik zur Grundlage der Mathematik, als formale Basis für die Vermeidung von Widersprüchen.
Entwicklung der Prädikatenlogik, die erlaubt:
- Beziehungen zwischen "Objekten" zu beschreiben
- existentielle Aussagen zu treffen: "es gibt ein x, so dass... "
- universelle Aussage zu treffen: "für jedes x gilt, dass... "


## Logik in der Informatik
Claude Shannon (1916 - 2001) benutzt die Aussagenlogik 1937, um elektromechanische Schaltkreise zu beschreiben und zu optimieren.

Allen Newell (1927-1992), Herbert Simon (1916-2001) und Alan Robinson (1930-2016) entwickelten 1950-1960 die ersten Systeme für die Automatisierung des logischen Schließens als Werkzeug der Künstlichen Intelligenz.

- Schaltkreisentwurf: Schaltkreise lassen sich durch logische Formeln darstellen -> Entwurf und Optimierung von Schaltungen
- Modellierung und Spezifikation: Eindeutige Beschreibung von komplexen Systemen
- Verifikation: Beweisen, dass ein Programm das gewünschte Verhalten zeigt
- Datenbanken: Formulierung von Anfragen an Datenbanken -> Abfragesprache SQL (Structured Query Language)
- (klassische) Künstliche Intelligenz:
    - Planung
    - Mensch-Maschine Kommunikation
    - Theorembeweiser: Der Computer beweist mathematische Sätze -> automatischer Beweis von wichtigen Sätzen im Bereich der Booleschen Algebren
- Logische Programmiersprachen


Außerdem: Logik ist ein Paradebeispiel für Syntax und formale Semantik

Edsger W. Dijkstra (1920-2002): Informatik = VLSAL (Very large scale application of logics)

Die Logik
- versucht, gültige Argumentationen von ungültigen zu unterscheiden,
- hat Anwendungen in der Informatik,
- formalisiert die zu untersuchenden Aussagen 

### Probleme mit natürlicher Sprache
1. Problem: Zuordnung von Wahrheitswerten zu natürlichsprachigen Aussagen ist problematisch.
    - Beispiele:
      - Ich habe nur ein bißchen getrunken.
      - Sie hat sich in Rauch aufgelöst.
      - Das gibt es doch nicht!
      - Rache ist süß.
2. Problem: Natürliche Sprache ist oft schwer verständlich.
    - Beispiel: Auszug aus der "Analytica Priora" von Aristoteles
    - Die Aussage: Wenn der Mittelbegriff sich universell auf Ober- oder Untersatz bezieht, muss ein bestimmter negativer Syllogismus resultieren, immer wenn der Mittelbegriff sich universell auf den Obersatz bezieht, sei es positiv oder negativ, und besonders wenn er sich auf den Untersatz bezieht und umgekehrt zur universellen Aussage.
    - Der Beweis: Denn wenn M zu keinem N gehört, aber zu einem O, ist es notwendig, dass N zu einem O nicht gehört. Denn da die negative Aussage umsetzbar ist, wird N zu keinem M gehören: Aber es war erlaubt, dass M zu einem O gehört: Deshalb wird N zu einem O nicht gehören: Denn das Ergebnis wird durch die erste Figur erreicht. Noch einmal: Wenn M zu allen N gehört, aber nicht zu einem O, ist es notwendig, dass N nichtzu einem O gehört: Denn wenn N zu allen O gehört und M auch alle N-Eigenschaften zugeschrieben werden, muss M zu allen O gehören: Aber wir haben angenommen, dass M zu einem O nicht gehört. Und wenn M zu allen N gehört, aber nicht zu allen O, können wir folgern, dass N nicht zu allen O gehört: Der Beweis ist der gleiche wie der obige. Aber wenn M alle O-Eigenschaften zugeschrieben werden, aber nicht alle N-Eigenschaften, wird es keinen Syllogismus geben.
3. Problem:Natürliche Sprache ist mehrdeutig.
    - Beispiel: "Ich sah den Mann auf dem Berg mit dem Fernrohr."
        - (((Ich sah den Mann) auf dem Berg) mit dem Fernrohr)
        - ((Ich sah (den Mann auf dem Berg)) mit dem Fernrohr)
        - ((Ich sah den Mann) (auf dem Berg mit dem Fernrohr))
        - (Ich sah ((den Mann auf dem Berg) mit dem Fernrohr))
        - (Ich sah (den Mann (auf dem Berg mit dem Fernrohr)))
4. Problem:Natürliche Sprache hängt von Kontext ab.
```
Die Beatles sind Musiker
Paul McCartney ist ein Beatle
Paul McCartney ist ein Musiker
```
```
Die Beatles sind vier
Paul McCartney ist ein Beatle
Paul McCartney ist vier
```

# Kapitel 1: Aussagenlogik
Beispiel

Ein Gerät besteht aus einem Bauteil A, einem Bauteil B und einem roten Licht. Folgendes ist bekannt:
1. Bauteil A oder Bauteil B (oder beide) sind kaputt.
2. Wenn Bauteil A kaputt ist, dann ist auch Bauteil B kaputt.
3. Wenn Bauteil B kaputt ist und das rote Licht leuchtet, dann ist Bauteil A nicht kaputt.
4. Das rote Licht leuchtet.

Zur Formalisierung verwenden wir folgende Abkürzungen:
- RL (rotes Licht leuchtet),
- AK (Bauteil A kaputt),
- BK (Bauteil B kaputt),
- $\vee$ (oder),
- $\rightarrow$ (wenn, dann),
- $\wedge$ (und) und
- $\lnot$ (nicht).

Damit können wir unser Wissen kompakter hinschreiben:
1. $AK \vee BK$
2. $AK \rightarrow BK$
3. $(BK \wedge RL)\rightarrow \lnot AK$
4. $RL$

Aus den vier Aussagen lassen sich weitere Aussagen neue Aussagen bilden
5. Falls $AK$ gilt, so folgt aus $AK\rightarrow BK$, dass $BK$ gilt.
6. Falls $BK$ gilt, so gilt natürlich $BK$.
7. Da $AK \vee BK$ gilt, folgt aus (5) und (6), dass $BK$ in jedem Fall gilt.
8. Es gilt auch $RL$.
9. Also gilt $BK\wedge RL$ (aus (7) und (8)).
10. Es gilt auch $(BK \wedge RL)\rightarrow\lnot AK$.
11. Also gilt $\lnot AK$ (aus (9) und (10)).

Damit sind wir überzeugt, dass das Bauteil A heil ist.

Den Beweis, dass das Teil A heil ist, werden wir als "Beweisbaum" formalisieren:

```
      [AK]       AK→BK
AK∨BK         BK      [BK]
          BK              RL
               BK∧RL         (BK∧RL)→ ¬AK
                            ¬AK
```

In der Aussagenlogik gehen wir von "Aussagen" aus, denen wir (zumindest prinzipiell) Wahrheitswerte zuordnen können.

## Beispiele
- Die Summe von 3 und 4 ist 7.
- Jana reagierte aggressiv auf Martins Behauptungen.
- Jede gerade natürliche Zahl>2 ist Summe zweier Primzahlen.
- Alle Marsmenschen mögen Pizza mit Pepperoni.
- Albert Camus était un écrivain français.
- In theory, practically everything is possible.

Für diese Aussagen verwenden wir dieatomaren Formeln $p,q,r$ bzw. $p_0,p_1,...$

Die Aussagen werden durch "Operatoren" verbunden. Beispiele
- ... und...
- ... oder...
- nicht...
- wenn... dann...
- entweder... oder... , aber nicht beide.
- mehr als die Hälfte der Aussagen ... gilt.

Für solche zusammengesetzten Aussagen verwenden wir $\varphi,\psi$ usw.

Durch die Wahl der erlaubten Operatoren erhält man unterschiedliche "Logiken".

Da der Wahrheitswert einer zusammengesetzten Aussage nur vom Wahrheitswert der Teilaussagen abhängen soll, sind Operatoren wie "weil" oder "obwohl" nicht zulässig.


## Syntax der Aussagenlogik
Eine atomare Formel hat die Form $p_i$ (wobei $i\in\mathbb{N}=\{0,1,...\}$). 
Formeln werden durch folgenden induktiven Prozess definiert:
1. Alle atomaren Formeln und $\bot$ sind Formeln.
2. Falls $\varphi$ und $\psi$ Formeln sind, sind auch $(\varphi\wedge\psi),(\varphi\wedge\psi)$($\varphi \rightarrow\psi$)und $\lnot\varphi$Formeln.
3. Nichts ist Formel, was sich nicht mittels der obigen Regeln erzeugen läßt.
   
Beispielformel: $\lnot((\lnot p_4 \vee p_1)\wedge\bot)$

Bezeichnungen:
- Falsum: $\bot$
- Konjunktion: $\wedge$
- Disjunktion: $\vee$
- Implikation: $\rightarrow$
- Negation: $\lnot$

Abkürzungen
$p,q,r...$ statt $p_0,p_1,p_2...$

$(\bigvee_{i=1}^n \varphi_i$ statt $(...((\varphi_1\vee\varphi_2)\vee\varphi_3)\vee...\vee\varphi_n)$

$(\bigwedge_{i=1}^n \varphi_i)$ statt $(...((\varphi_1\wedge\varphi_2)\wedge\varphi_3)\wedge...\wedge\varphi_n)$

$(\varphi \leftrightarrow \psi)$ statt $((\varphi\rightarrow\psi)\wedge(\psi\rightarrow\varphi))$


Präzedenz der Operatoren:
- $\leftrightarrow$ bindet am schwächsten
- $\rightarrow$...
- $\vee$...
- $\wedge$...
- $\lnot$ bindet am stärksten

Es gilt also z.B.: $(\alpha\leftrightarrow\beta\vee\lnot\gamma\rightarrow\sigma\wedge\lnot\eta) = (\alpha\leftrightarrow ((\beta\vee\lnot\gamma)\rightarrow(\sigma\wedge\lnot\eta)))$

Dennoch: Zu viele Klammern schaden i.A. nicht.


## Natürliches Schließen
Ein (mathematischer) Beweis zeigt, wie die Behauptung aus den Voraussetzungen folgt.  
Analog zeigt ein "Beweisbaum" (= "Herleitung" = "Deduktion"), wie eine Formel der Aussagenlogik aus Voraussetzungen (ebenfalls Formeln der Aussagenlogik) folgt.  
Diese "Deduktionen" sind Bäume, deren Knoten mit Formeln beschriftet sind: 
- an der Wurzel steht die Behauptung (= Konklusion $\varphi$) 
- an den Blättern stehen Voraussetzungen (= Hypothesen oder Annahmen aus $\Gamma$) 
- an den inneren Knoten stehen "Teilergebnisse" und "Begründungen" 

![](Assets/Logik-deduktionsbaum.png)

## Konstruktion von Deduktionen
Aus der Annahme der Aussage $\varphi$ folgt $\varphi$ unmittelbar: eine triviale Deduktion

$\varphi$ mit Hypothesen $\{\varphi\}$ und Konklusion $\varphi$.  

Folgend werden wir 
- überlegen, wie aus "einfachen mathematischen Beweisen" umfangreichere entstehen können und 
- parallel dazudefinieren, wie aus einfachen Deduktionen umfangreichere konstruiert werden können. 

### Konjunktion
#### Konjunktionseinführung in math. Beweisen
Ein mathematischer Beweis einer Aussage "$\varphi$ und $\psi$" sieht üblicherweise so aus: 
- "Zunächst zeige ich $\varphi$: ... (hier steckt die eigentliche Arbeit)  
- Jetzt zeige ich $\psi$: ... (nochmehr eigentliche Arbeit)  
- Also haben wir "$\varphi$ und $\psi$" gezeigt. qed" 

#### Konjunktionseinführung (ausführlich)
Ist D eine Deduktion von $\varphi$ mit Hypothesen aus $\Gamma$ und ist E eine Deduktion von $\psi$ mit Hypothesen aus $\Gamma$, so ergibt sich die folgende Deduktion von $\varphi\wedge\psi$ mit Hypothesen aus $\Gamma$:

![](Assets/Logik-konjunktionseinführung.png)

Kurzform: $\frac{\varphi\quad\psi}{\varphi\wedge\psi} (\wedge I)$ 

#### Konjunktionselimination (ausführlich)
Ist D eine Deduktion von $\varphi\wedge\psi$ mit Hypothesen aus $\Gamma$, so ergeben sich die folgenden Deduktionen von $\varphi$ bzw. von $\psi$ mit Hypothesen aus $\Gamma$:

![](Assets/Logik-Konjunktionselimination.png)

Kurzform: $\frac{\varphi\wedge\psi}{\varphi} (\wedge E_1) \quad\quad \frac{\varphi\wedge\psi}{\psi} (\wedge E_2)$

#### Beispiel
Wir zeigen $\varphi\wedge\psi$ unter der Hypothese $\psi\wedge\varphi$:...

![](Assets/Logik-Deduktionsbeispiel.png)

Dies ist eine Deduktion mit Konklusion $\varphi\wedge\psi$ und Hypothese $\psi\wedge\varphi$ (zweimal verwendet).

### Implikation
#### Implikationseinführung in math. Beweisen
Ein mathematischer Beweis einer Aussage "Aus $\varphi$ folgt $\psi$" sieht üblicherweise so aus:  
- "Angenommen, $\varphi$ gilt.
- Dann ... (hier steckt die eigentliche Arbeit).  
- Damit gilt $\psi$.  
- Also haben wir gezeigt, dass $\psi$ aus $\varphi$ folgt. qed"

Die Aussage $\varphi$ ist also eine "temporäre Hypothese". 

#### Implikationseinführung (ausführlich)
Ist D eine Deduktion von $\psi$ mit Hypothesen aus $\Gamma\cup\{\varphi\}$, so ergibt sich die folgende Deduktion von $\varphi\rightarrow\psi$ mit Hypothesen aus $\Gamma$:

![](Assets/Logik-Implikationseinführung.png)

Kurzform 
$$[\varphi]$$ 
$$\vdots$$ 
$$\frac{\psi}{\varphi\rightarrow\psi} (\rightarrow I)$$

Beispiel: ... Dies ist eine Deduktion von $\varphi\rightarrow\varphi$ ohne Hypothesen. 

#### Implikationselimination in math. Beweisen
Ein mathematischer Beweis einer Aussage "$\psi$ gilt" über eine Hilfsaussage sieht so aus:
- "Zunächst zeigen wir, dass $\varphi$ gilt: ...
- Dann beweisen wir, dass $\psi$ aus $\varphi$ folgt: ...
- Also haben wir $\psi$ gezeigt. qed"

#### Implikationselimination oder modus ponens (ausführlich)
Ist D eine Deduktion von $\varphi$ mit Hypothesen aus $\Gamma$ und ist E eine Deduktion von $\varphi\rightarrow\psi$ mit Hypothesen aus $\Gamma$, so ergibt sich die folgende Deduktion von $\psi$ mit Hypothesen aus $\Gamma$:

![](Assets/Logik-Implikationselimination.png)

Kurzform: $\frac{\varphi\quad \varphi\rightarrow\psi}{\psi} (\rightarrow E)$

#### Beispiel
![](Assets/Logik-Implikationseleimination-beispiel.png)

Bemerkung: die Indizes 1, 2 und 3 machen deutlich, welche Hypothese bei welcher Regelanwendung gestrichen wurde. Deduktionen können recht groß werden.

Diese Deduktion hat keine Hypothesen!


### Disjunktion
#### Disjunktionselimination oder Fallunterscheidung in math. Beweisen
Ein mathematischer Beweis einer Aussage "$\sigma$ gilt" mittels Fallunterscheidung sieht üblicherweise so aus:
- "Zunächst zeigen wir, dass $\varphi\vee\psi$ gilt: ...
- Gilt $\varphi$, so gilt $\sigma$, denn ...
- Gilt $\psi$, so gilt ebenfalls $\sigma$, denn ...
- Also haben wir gezeigt, dass $\sigma$ gilt. qed"  

Die Aussagen $\varphi$ und $\psi$ sind also wieder "temporäre Hypothesen".

#### Disjunktionselimination oder Fallunterscheidung (ausführlich)
Ist D eine Deduktion von $\varphi\vee\psi$ mit Hypothesen aus $\Gamma$, ist E eine Deduktion von $\sigma$ mit Hypothesen aus $\Gamma\cup\{\varphi\}$und ist F eine Deduktion von $\sigma$ mit Hypothesen aus $\Gamma\cup\{\psi\}$, so ergibt sich die folgende Deduktion von $\sigma$ mit Hypothesen aus $\Gamma$:

![](Assets/Logik-Disjunktionselimination.png)

Disjunktionselimination Kurzform: 
$$\quad [\psi] \quad[\varphi]$$
$$\quad \vdots \quad\vdots$$
$$\frac{\varphi\vee\psi \quad\sigma \quad\sigma}{\sigma} (\vee E)$$

Disjunktionseinführung (Kurzform)
$$\frac{\varphi}{\varphi\vee\psi} (\vee I_1) \quad \frac{\psi}{\varphi\vee\psi} (\vee I_2)$$

### Negation
#### Negationseinführung in math. Beweisen
Ein mathematischer Beweis einer Aussage "$\varphi$ gilt nicht" sieht so aus:  
- "Angenommen,$\varphi$gilt.  
- Dann folgt $0=1$, denn .... Mit anderen Worten, dies führt zu einem Widerspruch.
- Also haben wir gezeigt, dass $\varphi$ nicht gilt. qed"  
- 
Die Aussage $\varphi$ ist also wieder eine "temporäre Hypothese". 

#### Negationseinführung (ausführlich)
Ist D eine Deduktion von $\bot$ mit Hypothesen aus $\Gamma\cup\{\varphi\}$, so ergibt sich die folgende Deduktion von $\lnot\varphi$ mit Hypothesen aus $\Gamma$:  

![](Assets/Logik-Negationseinführung.png)

Kurzform:
$$[\varphi]$$
$$\vdots$$
$$\frac{\bot}{\lnot\varphi} (\lnot I)$$

#### Negationselimination (ausführlich)
Ist D eine Deduktion von $\lnot\varphi$ mit Hypothesen aus $\Gamma$ und ist E eine Deduktion von $\varphi$ mit Hypothesen aus $\gamma$, so ergibt sich die folgende Deduktion von $\bot$ mit Hypothesen aus $\Gamma$:

![](Assets/Logik-Negationselimination.png)

Kurzform: $\frac{\lnot\varphi \quad \varphi}{\bot} (\lnot E)$

### Falsum
Hat man "$0=1$" bewiesen, so ist man bereit, alles zu glauben: ex falso sequitur quodlibet

ausführlich: Ist D eine Deduktion von $\bot$ mit Hypothesen aus $\Gamma$, so ergibt sich die folgende Deduktion von $\varphi$ mit Hypothesen aus $\Gamma$: 

![](Assets/Logik-Falsumeinführung.png)

Kurzform: $\frac{\bot}{\varphi} (\bot)$

#### math. Widerspruchsbeweis
Ein indirekter Beweis einer Aussage "$\varphi$ gilt" sieht üblicherweise so aus:
- "Angenommen, $\varphi$ gilt nicht, d.h. $\lnot\varphi$ gilt.
- Dann folgt $0=1$, d.h. ein Widerspruch.  
- Also haben wir gezeigt, dass $\varphi$ gilt. qed"
 
Die Aussage $\lnot\varphi$ ist also wieder eine "temporäre Hypothese".

#### reductio ad absurdum (ausführlich)
Ist D eine Deduktion von $\bot$ mit Hypothesen aus $\Gamma\cup\{\lnot\varphi\}$, so ergibt sich die folgende Deduktion von $\varphi$ mit Hypothesen aus $\Gamma$:

![](Assets/Logik-reductio-ad-absurdum.png)

Kurzform: 
$$[\lnot\varphi]$$
$$\vdots$$
$$\frac{\bot}{\varphi} (raa)$$

## Regeln des natürlichen Schließens
> Definition
> 
> Für eine Formelmenge $\Gamma$ und eine Formel $\varphi$ schreiben wir $\Gamma\vdash\varphi$ wenn es eine Deduktion gibt mit Hypothesen aus $\Gamma$ und Konklusion $\varphi$. Wir sagen "$\varphi$ ist eine syntaktische Folgerung von $\Gamma$".
> 
> Eine Formel $\varphi$ ist ein Theorem, wenn $\varnothing\vdash\varphi$ gilt.

### Bemerkung
$\Gamma\vdash\varphi$ sagt (zunächst) nichts über den Inhalt der Formeln in $\Gamma\cup\{\varphi\}$ aus, sondern nur über die Tatsache, dass $\varphi$ mithilfe des natürlichen Schließens aus den Formeln aus $\Gamma$ hergeleitet werden kann.

Ebenso sagt "$\varphi$ ist Theorem" nur, dass $\varphi$ abgeleitet werden kann, über "Wahrheit" sagt dieser Begriff (zunächst) nichts aus.

### Satz
Für alle Formeln $\varphi$ und $\psi$ gilt $\{\lnot(\varphi\vee\psi)\}\vdash\lnot\varphi\wedge\lnot\psi$.

Beweis: Wir geben eine Deduktion an...
- $\{\lnot\varphi\wedge\lnot\psi\}\vdash\lnot(\varphi\vee\psi)$
    ![](Assets/Logik-beispiel-1.png)
- $\{\lnot\varphi\vee\lnot\psi\}\vdash\lnot(\varphi\wedge\psi)$
    ![](Assets/Logik-beispiel-2.png)
- $\{\varphi\vee\psi\} \vdash \psi\vee\varphi$
    ![](Assets/Logik-beispiel-3.png)

### Satz
Für jede Formel $\varphi$ ist $\lnot\lnot\varphi\rightarrow\varphi$ ein Theorem.

Beweis: Wir geben eine Deduktion mit Konklusion $\lnot\lnot\varphi\rightarrow\varphi$ ohne Hypothesen an...

### Satz
Für jede Formel $\varphi$ ist $\varphi\vee\lnot\varphi$ ein Theorem.

Beweis: Wir geben eine Deduktion mit Konklusion $\varphi\vee\lnot\varphi$ ohne Hypothesen an...

Bemerkung: Man kann beweisen, dass jede Deduktion der letzten beiden Theoreme die Regel (raa) verwendet, sie also nicht "intuitionistisch" gelten. 

### Satz
$\{\lnot(\varphi\wedge\psi)\}\vdash\lnot\varphi\vee\lnot\psi$

![](Assets/Logik-beispiel-4.png)

