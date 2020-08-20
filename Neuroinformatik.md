# NeuroInformatik
Die Lehrveranstaltung vermittelt das erforderliche Methodenspektrum aus theoretischen Grundkenntnissen und praktischen Fähigkeiten zum Verständnis, zur Implementierung und zur Anwendung neuronaler und probabilistischer Techniken des Wissenserwerbs durch Lernen aus Erfahrungsbeispielen sowie zur Informations- und Wissensverarbeitung in massiv parallelen Systemen. Sie vermittelt sowohl Faktenwissen, begriffliches und algorithmisches Wissen.

Inhaltsübersicht
- Intro: Begriffsbestimmung, Literatur, Lernparadigmen, Haupteinsatzgebiete, Historie
- Neuronale Basisoperationen und Grundstrukturen:
  - Neuronenmodelle
  - Netzwerkmodelle
- Lernparadigmen und deren klassische Vertreter:
  - Unsupervised Learning
  - Reinforcement Learning
  - Supervised Learning
- Moderne Verfahren für große Datensets
  - Deep Neural Networks

Exemplarische Software-Implementationen neuronaler Netze für unüberwachte und überwachte Lern- und Klassifikationsprobleme (Fokus auf Python). Die Studierenden erwerben somit auch verfahrensorientiertes Wissen, indem für reale Klassifikations- und Lernprobleme verschiedene neuronale Lösungsansätze theoretisch behandelt und praktisch umgesetzt werden. Im Rahmen des Pflichtpraktikums werden die behandelten methodischen und algorithmischen Grundlagen der neuronalen und probabilistischen Informationsverarbeitungs- und Lernprozesse durch die Studierenden mittels interaktiver Demo-Applets vertieft und in Gesprächsgruppen aufgearbeitet.


[comment]: <> (Vorlesung 1)
# Intro
## Was ist Künstliche Intelligenz (KI) ?
- Künstliche Intelligenz (KI, englisch Artificial intelligence - AI) ist ein Teilgebiet der Informatik, welches sich mit der Automatisierung intelligenten Verhaltens und dem Maschinellen Lernen befasst. Der Begriff ist nicht eindeutig abgrenzbar, da es bereits an einer genauen Definition von „Intelligenz“ mangelt. (Quelle: Wikipedia)
 -bezeichnet den Versuch, bestimmte Entscheidungsstrukturen des Menschen nachzubilden, indem z. B. ein Computer so programmiert wird, dass er relativ eigenständig komplexe Probleme bearbeiten kann.
- Begriff wurde erstmals 1956 vom amerikanischen Informatiker John McCarthy verwendet, der ihn im Projektantrag für die Dartmouth-Konferenz 1956 gebrauchte (Präsentation von Programmen, die Schach und Dame spielten, Theoreme bewiesen sowie Texte interpretierten)

## Starke vs. Schwache KI
- Schwache KI (Narrow AI):
  - zielt darauf ab, konkrete Anwendungsprobleme des menschlichen Denkens und Handelns zu lösen
  - Fähigkeit aus Beobachtungen zu lernen ist integraler Bestandteil
  - zielt auf die Simulation intelligenten Verhaltens mit Mitteln der Mathematik & Informatik, aber NICHT auf die Schaffung von Bewusstsein oder auf ein tieferes Verständnis von Intelligenz
- Starke KI:
  - zielt auf die Schaffung von eigenständigem, maschinellem Bewusstsein und Gewinnung eines Verständnisses von Intelligenz
  - muss nicht Gemeinsamkeiten mit dem Menschen haben, wird vermutlich eine andersartige kognitive Architektur aufweisen (Quelle: Wikipedia)

## Wesentliche Methoden / Konzepte:
- Symbolische Verfahren: Top-down Ansatz (von begrifflicher Ebene): expertenwissen in system packen
- Subsymbolische/Neuronale Verfahren: Bottom-up Ansatz von Daten: nutzt daten in denen "wissen" steckt und lasst durch viele daten richtige entscheidungen (beobachten) enstehen
- Simulationsmethode: simuliert kognitive Prozesse des Menschen
- Phänomenologische Methode: arbeitet rein ergebnisorientiert

## Techniken der KI
1. **Suchverfahren** z.B. zur Wegfindung (Dijkstra, A*, D*, E*, …)
2. **Planungsverfahren** zur Erstellung optimaler Aktionsfolgen zum Ziel
3. **Optimierungsverfahren** z.B. Hill Climbing, Evolutionäre Algorithmen, Partikelschwarmoptimierung
4. **Logisches Schließen**
    − formalisiertes menschliches Wissen (z.B. in Ontologien)
    − Induktion: Verallgemeinerung von Beispielen zu Regeln, häufig mit Maschinellem Lernen
      - In symbolischen Systeme: Beispiele als auch die induzierten Regeln sind explizit repräsentiert
      - In subsymbolischen Systemen: berechenbares Verhalten wird „antrainiert“, erlaubt jedoch keinen/nur schwer Einblick in die erlernten Lösungswege
5. **Approximationsmethoden** aus einer Menge von Daten eine allgemeine Regel ableiten (z.B. Neuronale Netze, Deep Learning)

## Was ist Maschinelles Lernen?
- Oberbegriff für die „künstliche“ Generierung von Wissen aus Erfahrung
  - Ein künstliches System lernt dabei aus Trainingsbeispielen und kann nach Beendigung der Lernphase verallgemeinern.
  - Es lernt also nicht einfach die Beispiele auswendig, sondern erkennt Gesetzmäßigkeiten (Regularitäten) in den Lerndaten.
  - So kann das System dann auch unbekannte Daten beurteilen.
- Breites Spektrum möglicher Anwendungen in: Diagnoseverfahren, Aktienkursanalyse, Bild- und Sprachverarbeitung, Robotik, Spielstrategien,…
- Art und Mächtigkeit der Wissensrepräsentation:
  - symbolisch: Wissen (Beispiele, induzierten Regeln) explizit repräsentiert
  - subsymbolisch: Wissen implizit repräsentiert - berechenbares Verhalten wird antrainiert, erlaubt aber kaum Einblick in die erlernten Lösungswege

## Wichtige Paradigmen des Maschinellen Lernens
Informationsverarbeitungsniveau zu Systemwissen
| \                                            | **symbolisch** | **subsymbolisch (numerisch)** |
| -------------------------------------------- | :------------: | :---------------------------: |
| explizit strukturiert (regelbasiert)         |   KI-Systeme   |         Fuzzy Systeme         |
| implizit unstrukturiert (durch lernprozesse) |       -        |       Neuronale Systeme       |


## Was ist Neuroinformatik
Neuroinformatik – das interdisziplinäre Forschungsgebiet zu den
- am biologischen Vorbild orientierten,
- nicht explizit programmierten aber
- lernfähigen und sich adaptierenden Systemen, die
- ihre eigenen, internen „Algorithmen“
- in Reaktion auf und in Wechselwirkung mit ihrer sensorisch (visuell, taktil, akustisch, usw.) vermittelten Umwelt entwickeln.
= Neural Computing, Konnektionismus, New AI, Brain-like Computing, Deep Learning
*Ziel*: Entwicklung von Maschinenintelligenz durch Nachbildung biologischer Informationsverarbeitungs- und Lernprozesse auf neuronalem Niveau

[comment]: <> (Vorlesung 2)
## Erste wichtige Grundlagen
### Lernparadigmen
#### Unsupervised Learning (Unüberwachtes Lernen)
Für eine gegebene Menge von Daten wird ohne Lehrer ein Modell, gelernt, das die Daten in kompakter Weise beschreibt . Wichtiges Teilgebiet: Cluster-Verfahren, die die Daten in mehrere Kategorien einteilen, die sich durch charakteristische Muster unterscheiden.

#### Reinforcement Learning (Verstärkungslernen)
Algorithmus lernt durch Belohnung und Bestrafung eine Taktik, wie in potenziell auftretenden Situationen zu handeln ist, um den Nutzen für den Agenten (Steuerung, Roboter, Spielprogramm) zu maximieren.

#### Supervised Learning (Lernen mit Lehrer)
Erlernen einer Abbildungsfunktion aus gegebenen Paaren von Ein- und Ausgaben. Während des Lernens stellt ein „Lehrer“ den korrekten
Sollwert zu einer Eingabe bereit. Wichtiges Teilgebiet: automatische Steuerung oder Klassifizierung

### Einsatzgebiete
#### Klassifikation/Kategorisierung
Zweck: auf Basis von diskret gelabelten Trainingsdaten $x = {(x_1, y_1), (x_2,y_2), ...,(x_n, y_n)}$ soll eine unbekannte, meist nichtlineare Beziehung zwischen den Inputdaten $x_i$ und den Klassenlabeln $y_i$ gelernt werden. Daten entstammen einer unbekannten, Daten generierenden Funktion, deren Funktionsoutput nur diskrete Werte annehmen kann. 
  Zu beachten! prinzipielle Separierbarkeit des Klassifikationsproblems linear nichtlinear nicht separabel  
  Einsatzfelder:  
- Detektionprobleme (Personen, Gesichter, ...)
- Klassifikationsprobleme (Handschrift, Posen, Gesten, Mimik, Krankheiten, Pflanzen, Tiere, ...)
- Übung: Schwertlilie

#### Funktionsapproximation / Regression
- Zweck: auf Basis von reelwertig gelabelten Trainingsdaten $x = {(x_1, y_1), (x_2,y_2), ...,(x_n, y_n)}$ soll eine unbekannte, Daten generierende Funktion approximiert werden, deren Funktionsoutput kontinuierlich (reell) ist.
- Lösungsansatz (Idee): jede stetige, mehrdimensionale und nichtlineare Funktion ist durch Überlagerung von Aktivierungsfunktionen mehrerer Neuronen beliebig genau approximierbar
- Einsatzfelder:
  - Abbildung hochdimensionaler Inputs auf niedrig-dimensionale kontinuierliche Outputs (z.B. Navigation bei ALVINN)
  - Zeitreihenprognose
  - Neurocontrol
  - Übung: Regression von Wohnhauspreisen
    - Trainingsziel: Erlernen der durchschnittlichen Wohnungspreise aus 13 hinterlegten Merkmalen
    - Grundlage bildet Sinusfunktion mit überlagertem Rauschen
    - 40 Datenpunkte aus Sinusfunktion y=sin x; diese wurden mit Rauschen überlagert y=sin x + noise
    - nach Training: reellwertige Ausgabe für beliebige Inputs x möglich

#### Clusterung bzw. Clusteranalyse
Zweck: strukturentdeckende Analyseverfahren zur Ermittlung von Gruppen (Clustern) von Daten, deren Eigenschaften markante Ähnlichtkeiten aufweisen. Variante des Klassifikationsproblems, nur schwieriger, da die Trainingsdaten hierbei ungelabelt sind.
Hauptanwendungsfelder:
- Gruppenbildung über Daten allgemein
- Datenvisualisierung
- Suche in Datenbanken und Web
- Bildsegmentierung (Video, CT, MRI, …)
- Clustering von Genom Daten
Typ. Vertreter:
- k-Means Algorithmus
- SOFM, Neural Gas
- Expectation-Maximization (EM)-Algorithmus
- Fuzzy C-Means, Mean Shift

### Einordnung in das Mustererkennungsparadigma
Wichtiger Hinweis: Dies ist das klassische Mustererkennungsparadigma.
Messdaten (Signale, Bilder) aus Sensorik kommt in Problemabhängige und Netzwerkbezogene Datenaufbereitung:
1. Problemspezifische
  - Vorverarbeitung
  -Schwellwertoperationen
  - Filterung
  - Inter- /Extrapolation
  - Normierungen & Korrekturen
  - Segmentierung
2. Merkmalsextraktion
  - Merkmalsgewinnung
  - Merkmalstransformation
    - Skalierung/Normierung
    - Unterraumprojektion (Dimensionsreduktion)
    - Quellenseparierung
  - Merkmalsselektion
    - Signifikanzanalyse
3. Netzwerkein- und ausgabekodierung
Die Ausgabe wird auf Klassifikation, Funktionsapproximation oder Clusterung übertragen

## Historische Entwicklungen
### Nachweis von Einzelneuronen (1905)
Der spanische Neuroanatom Santiago Ramon y Cajal konnte mittels der Golgi-Färbung erstmals nachweisen, dass das Gehirn aus einzelnen, getrennten Zellen (Neuronen) besteht.
Danach wurde eine strukturelle Vielfalt der Neuronentypen entdeckt (30-40 versch Zelltypen), unter anderem Purkinje-, Pyramiden- oder spindelförmige Zellen.

### Das Hebb'sche Korrelationslernen (1949)
Die synaptische Kopplung zwischen zwei Neuronen ist plastisch und ändert sich proportional zur Korrelation der Aktivitäten des Sender- und des Empfängerneurons, d.h. der prä- und postsynaptischen Aktivitäten.

$w_{ij}(t+1) = w_{ij}(t) + \Delta w_{ij}(t)$ (Lernen über die Zeit)
$\Delta w_{ij} = \eta * y_i(t)*x_{ij}(t)$ (Das $x_ij$ ist Aktivität des Eingangsneuron, $y_i$ die Aktivität des Empfängerneurons)

| $y_i/y_j$ | 0 | 1 |
| 0 | 0 | 0 |
| 1 | 0 | + |

### Erste einfache Neuronenmodelle
In Knoten laufen Informationsprozesse verschiedener Synapsen ein. Diesen Synapsen sind Gewichtungen vorgegeben. Der Knoten bildet aus den gewichteten Eingängen über eine Gesamteingabe und Transferfunktion die Ausgabeakivitäten. Synapsen können Signale nicht verstärken, nur schwächen!

### Grundstruktur und Lernprinzip eines Multi Layer Perzeptons (MLP)
- Input Layer nehmen Grundfunktion hne Bias auf
- Hidden Layer (1.Schicht) verknüpfen die Input Layer und bewerten mit Bias (bildet Scalarprodukt seiner gewichteten Eingangsinputs). Ermöglicht mathematische Operationen. Wird als Synaptische Matrix bezeichnet
- Output-Layer (2. Schicht) verknüft Ausgangsprodukte der Hidden Layer mit einem eigenem Bias und erstellt selbst Vektoren 

Bsp: 5 Hidden Neuronen + 1 Hidden Bias Neuron + 2 Output Neuronen + 1 Output Bias Neuron = 12 Neuronen/Gewichte
Teach Vektor t: $d = t -y$
Abbildungsfelder (als skalare Größe): $E=||d||^2$ wird verwendet um Fehler zu minimieren oder zu verhindern
Skalarer Abbildungsfehler (Loss Funktion) wird nach fälschlichen Gewichten abgeleitet: $\frac{\delta E}{\delta w_{ij}} \rightarrow \Delta W^1$

### Erlernen der Navigation mittels Expert Cloning
- Kopieren der situationsabhängigen Fahrstrategie eines/mehrerer geübter Fahrer in ein Neuronales Netz
- Nutzung der Approximations und Verallgemeinerungsfähigkeit des Netzes zur Navigation in unbekannten Situationen
- realisiert eine hochkomplexe, nicht explizit algorithmisch fassbare neuronale Funktionsapproximation $\rightarrow$ End-to-End Learning

$\phi = f(x(t))$

#### ALVINN – Prinzipielle Vorgehensweise
1. Vorführphase:
  - Experte(n) steuert Fahrzeug entlang einer Anzahl repräsentativer Trajektorien, die die gewünschte Fahrstrategie implizit beschreiben (Beachte: nur mittels der Kamerabilder) $\rightarrow$ bei untersch. Witterungs-, Beleuchtungs- & Straßenverhältnissen
  - Synchrone Aufzeichnung der aktuellen Szenenansichten $x(t)$ und des vom Experten gewählten Lenkwinkels $\phi(t)$
  - Vorteil: Datensatz enthält auch die durch Fahrzeugkinematik und sonstige Einflüsse (Straßen-/Reifenzustand) bestimmten Restriktionen während der Fahrt
2. Trainingsphase:
  - Approximation der Abbildungsfunktion $\phi (t)=f(x(t))$ mittels Supervised Learning
  - Generalisierung von bekannten Trainingssituationen auch auf unbekannte neue Straßenverläufe
3. Recallphase: 
  - Nachahmung der vom Experten in der Vorführphase verfolgten Fahrweise $\rightarrow$ Experten-Cloning
  - topologische Ausgabekodierung $\rigtharrow$ Fuzzyfikation des Lenkwinkels

- Neuronen fungieren als Detektoren für ganze Straßenverläufe mit verschiedenen Orientierungen oder für die linke bzw. rechte Straßenkante.
- Ein Einzelneuron allein kann die Lenkung nicht korrekt steuern, erst die kollektive Aktivierung aller Neuronen (mit richtigen und falschen lokalen Hypothesen) ermöglicht die feinabgestimmte Steuerung des Fahrzeugs.

### Überwachtes Lernen als Optimierungsproblem – die „Support Vector Machine“
- aus der statistischen Lerntheorie hervorgegangenes Lernverfahren
- zur Lösung von Klassifikationsproblemen entwickelt (Vapnik, 1995)
- später auch für Funktionsapproximation/Regression eingesetzt (Vapnik et al., 1997)
- allgemein bessere Generalisierungsfähigkeiten als damals bekannte neuronale Netze, weil ...

| Neuronales Netz                                         | Support Vector Machine (SVM)                                                             |
| ------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| Training – als Gradientenabstieg über dem Fehlergebirge | Training – als Lösung eines quadratischen Optimierungsproblems mit konvexer Zielfunktion |
| $\rightarrow$ kann in lokalem Minimum enden             | $\rightarrow$ sichert Konvergenz zum globalen Minimum                                    |

#### SVM Grundidee
- Trainingsmuster in Form von Vektoren, die einer von zwei Klassen angehören
- Ermittlung einer optimalen Hyperebene H (Trenngerade, Trennebene), so dass diese
  1. die Trainingsmuster korrekt trennt und dabei
  2. einen möglichst großen Abstand zu den äußeren Datenpunkten der jeweiligen Klasse aufweist
- Der minimale Abstand zwischen der Trennebene und dem nächsten Trainingssample wird als Margin bezeichnet und soll maximal werden $\rigtharrow$ Forderung zur Erzielung guter Generalisierungsleistungen
- Ziel des Algorithmus: Finden einer optimal gelegenen Hyperebene H, bei der der Margin maximal wird $\rightarrow$ erfordert Lösung eines Optimierungsproblems

[comment]: <> (Vorlesung 3)
### Deep Learning
Konzept und Lernverfahren, das seit etwa 2010 alle Rekorde (Computervision, Sprachverstehen, Robotik, Spielstrategien) in der künstlichen Intelligenz bricht. Kombiniert eigentlich alte Verfahren (neuronale Netze) mit 
1. gewaltigen Datenmengen und
2. massiv paralleler Rechenpower $\rightarrow$ Schlüssel zum Erfolg
Im Kern ein unüberwachtes Verfahren für tiefe neuronale Netze zum Lernen von hierarchischen Features der Eingabedaten für schwierigste Klassifikationsaufgaben.

#### Typische Netzwerkstruktur
Neuronales Netzwerk für Schadstellendetektion
- bis zu 1000 Schichten
- mehrere Mio. freie Parameter (Gewichte), die alle zu trainieren sind
- Einsatz neuartiger Techniken beim Training: Regularisierung, Dropout, Weight Decay, Batch Normalization, usw.

#### Motivation für Deep Learning
> „Hunderte von Entwicklern und Studenten verbrachten Jahrzehnte damit, per Hand all
die Regeln einzutippen, die Computer brauchen könnten, um Gegenstände anhand ihrer
Merkmale zu unterscheiden“
> „Sich Merkmalssätze auszudenken, ist schwierig, zeitaufwändig und verlangt nach viel
Fachwissen, da muss man sich natürlich die Frage stellen: Gibt es keinen besseren
Weg?„ (A. Ng, Stanford Univ. / Baidu Research / Coursera )

Probleme:
- Design des Merkmalsraumes per Hand:
  - erfordert viel Hintergrundwissen über das Klassifikationsproblem und ist zeitintensiv
  - Wiederkehrendes Problem: neue Objektklassen benötigen eventuell neue Merkmalsräume
- Meist nur ungelabelte Bilder verfügbar:
  - viele Anwendungen haben keine oder kaum gelabelte Daten (z.B. Facebook-Fotos)
  - Bilder haben hohen Informationsgehalt $\rightarrow$ auch ohne Label ist viel Information über die betreffende Klasse enthalten

Ausweg: Deep Learning
- Wesen:
  - Lernen von hierarchischen Features der Eingabedaten
  - Jede Schicht lernt immer komplexere Features ausgehend von den Features der letzten Schicht
- Vorab-Design der Features ist damit nicht mehr erforderlich
- Direkte Ausnutzung von ungelabelten Daten durch unüberwachtes Lernen
- Bekannte Netzwerkarchitekturen:
  - Covolutional Neural Networks (CNN)
  - Stacked Auto-Encoder (SAE), Long Short-term Memories (LSTM), ...
- Netzwerkarchitekturen unterstützen auch überwachtes Lernen $\rightarrow$ damit auch Kombination von unüberwachtem mit überwachtem Lernen möglich

#### Grundidee von Deep Learning
- Phase 1: Unüberwachtes Lernen der Feature-Hierarchie über den Bildern aller Kategorien (unüberwacht – da noch ohne Klassenlabels!)
- Phase 2: Überwachtes Fein-Tuning des Netzes – nun mit gelabelten Daten

- erste Schicht: orientierte Kanten
- zweite Schicht: Objektteile
- Höhere Schichten: Ganze Objekte

#### Deep Learning auf GPUs
- CPU: spezialisierte Kerne, für serielle Verarbeitung optimiert
- GPU: einfache Kerne, für parallele Verarbeitung optimiert
- Deep-Learning-Operationen sind meist einfache und leicht parallelisierbare Rechenoperationen (Add. und Mult.)
$\rightarrow$ Nutzung der GPU (z.B. Faltungen in CNN)
Beschleunigung des Lernens um Faktor 20-100 (statt 4 Wochen auf CPU $\rightarrow$ 1 Tag)

#### “Challenges” beim Deep Learning
- Rolle der verwendeten Daten - gelernte Modelle können “biased” sein
  - Beispiel: Gesichtserkenner von Microsoft, IBM, Face++
  - Männl. Gesichter (8,1 % Fehlerrate (FR)) besser erkannt als weibliche (20,6 % FR); Gesichter mit heller Hautfarbe besser erkannt (11,8 % FR) als Personen mit dunkler (19,2 % FR) $\rightarrow$ funktionierten am besten mit männl. Personen heller Haut
  - Vermutung: Trainingsdatensatz bestand überproportional aus männlichen Gesichtern mit heller Hautfarbe
- Instabilität bei speziellen Rauschmustern - ”Adversarial Attacks”
  - Adversarial Examples sind manipulierte Eingaben (Bilder, Sprache) mit der Fähigkeit, ein Deep Neural Network (DNN) zu täuschen, so dass das DNN die Eingabe falsch kategorisiert.
  - Manipulation der Eingabe erfolgt meist durch spezielle Rauschmuster.
  - Für den menschlichen Betrachter ist das Rauschen aber völlig irrelevant, hat keinen Einfluss auf die Erkennung.

##### Adversial Attacks
Motivation: korrekt klassifizierte Bilder so verändern, dass das DNN das veränderte Bild einer falschen Klasse zuordnet, die Veränderung aber für einen Menschen nicht sichtbar ist. Böswilliger Einsatz:
- Täuschung sicherheitskritischer Systeme
- Google Bildersuche: Platzieren von eigenen Angeboten bei beliebten Suchbegriffen
- Manipulation von Assistenzsystemen beim Autonomen Fahren (z.B. Stoppschild als Vorfahrtsschild erkannt)

# Neuronale Basisoperationen und Grundstrukturen
## Wichtige Neuronenmodelle
### Vorbild: Biologisches Neuron
Neuron: Erregungserzeugender, -leitender und –verarbeitender Grundbaustein des Nervensystems $\rightarrow$ elementarer cortikaler Prozessor. Kommunikation mittels elektr. Impulse (Aktionspotentiale, Spikes), die an Synapsen (Kontaktstellen zwischen zwei Neuronen) in Form chemischer Signale ( Neurotransmitter) weitergeleitet werden.
Wesentliche Informationen sind in
- der Spikerate (Dichte)
- dem Spikezeitpunkt (Phasenlage)
- der Effektivität der synaptischen Verbindung

#### Struktur und Funktion der wesentlichen Neuronenabschnitte
| Neuronenabschnitte |                                                                                                         Informationstechnische Funktion                                                                                                         |
| ------------------ | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| 1. Synapsen        |                                           Gerichtete Informationsübertragung & -speicherung <br> (Adaptive Analogschalter; D/A-Wandlung der präsynaptischen Spikefolgen in analoge Membranpotentiale)                                           |
| 2. Dendrit         | Räumlich-zeitliche Integration & Weiterleitung <br> (Nichtlineare räumlich-zeitliche Überlagerung der lokalen dendritischen Membranpotentiale; Weiterleitung der lokalen Membranpotentiale (mit Verlusten, Verzögerungen und Laufzeiteffekten)) |
| 3. Soma            |                                                               Globale räumlich-zeitliche Integration <br> (Integration aller dendritischen Potentiale zum Soma-Membranpotential)                                                                |
| 4. Axonhügel       |                                                       Störsichere Umkodierung <br> (A/D-Wandlung des Somapotentials in Spikefolgen; Informationskodierung in Spikerate & Spikezeitpunkt)                                                        |
| 5. Axon            |                                                   Informationsweiterleitung & -verteilung <br> (sichere, verlustfreie und energieoptimale Weiterleitung; aktive räuml.-zeitliche Umkodierung)                                                   |

#### Das biologische Neuron aus informationstechnischer Sicht
Räumliche Kodierung (Position) $\rightarrow$ Kodierung von Qualitäten (Reizarten)

Zeitliche Kodierung (Spikedichte, -phase) $\rightarrow$ Kodierung von Quantitäten (Reizintensität) und Synchronisation

| Axonendigung       | Synapse/Dendrit    | Soma               | Axonhügel/Axon     |
| ------------------ | ------------------ | ------------------ | ------------------ |
| zeitkontinuierlich | zeitkontinuierlich | zeitkontinuierlich | zeitkontinuierlich |
| wertediskret       | werteanalog        | werteanalog        | wertediskret       |

#### Abgeleitete Neuronenmodelle
- bislang zahlreiche Neuronenmodelle mit unterschiedlicher Biologietreue und Komplexität entwickelt
- wichtigste Vertreter mit abnehmendem Biologiebezug ↓ aber zunehmender Praxisrelevanz ↑ sind:
  1. Compartment Modell Neuronen (hier nicht weiter behandelt)
  2. Integrate & Fire Neuronen
  3. Dynamische Ratenneuronen (Leaky Integrator)
  4. Statische Ratenneuronen
- bei diesen Neuronenmodelle Vernachlässigung verschiedener biologisch relevanter Aspekte, wie z.B.:
  - reale Geometrie des Neurons (mit seinen Verästelungen im Dendriten/Axon)
  - Leitungsverzögerungen an den Synapsen und im Dendriten
  - nichtlineare Wechselwirkungen zwischen den postsynaptischen Potentialen (PSP)
  - der realen Form der präsynaptischen Aktionspotentiale $\rightarrow$ Annahme von Dirac-Impulsen ( δ(t)=1, wenn t = t spike ; δ(t)=0, wenn t ≠ t spike )
  - der realen zeitlichen Funktionalität des Neurons $\rightarrow$ wird komplett in die Synapse verlagert

### Das Integrate & Fire (I&F) Neuron
- Kommunikation zwischen Neuronen erfolgt über Spikes (zeitkontinuierlich, wertediskret)
- Verarbeitung innerhalb des Neurons erfolgt analog auf Potentialniveau (zeitkontinuierlich, wertekontinuierlich)
- Spikekodierung stellt die Zeit als zusätzliche Kodierungsdimension für neuronale Wahrnehmungsprozesse zur Verfügung:
  1. zeitlicher Abstand von Ereignissen in Bezug zu anderen Ereignissen $\rightarrow$ Phasenlage
  2. Häufigkeit der Ereigniswiederholung $\rightarrow$ Frequenz
  3. Zeitverlauf der Änderung von Aktivitätsparametern $\rightarrow$ Frequenzänderung

Zeitliche Synchronisation mit I&F-Neuronen
- Gehirn scheint zeitliche Synchronisationsprozesse von Einzelspikes oder Bursts (Spikepakete) als ein Attributierungsmittel zu nutzen
- „virtuelle“ Kopplung zusammengehöriger Neuronen durch zeitliche Phasensynchronisation ihrer Aktivitäten auch über große räumliche Entfernungen
- damit Kennzeichnung der Neuronen eines „Perzepts“ durch synchrones, korreliertes Feuern – Neuronen anderer „Perzepte“ feuern zu diesen unkorreliert $\rightarrow$ „Correlation Theory of Brain Function“

Technische Umsetzung von I&F-Neuronen
- präsynaptische Spikes erzeugen gewichtete postsynaptische Potentiale (PSP)
- PSPs werden zeitlich und räumlich integriert $\rightarrow$ Somapotential
- wenn Somapotential >= Schwelle $\rightarrow$ Generierung eines Spike (Aktionspotential)
- Afterhyperpolarisation (AHP) hemmt für bestimmte Zeit weiteres Feuern

Typische Einsatzfelder von I&F-Neuronen
- in der Computational Neuroscience, wo sie zur systematischen Untersuchung von Gehirnfunktionen verwendet werden 
- oft auch für mathematische Analysen von Gehirnfunktionen verwendet
- oft in Simulationen von Neuronalen Netzwerken eingesetzt, da sie durch ihre Einfachheit auch bei großen Netzen mit vielen Neuronen nur wenig Rechenzeit verbrauchen

[comment]: <> (Vorlesung 4)
### Das formale dynamische Ratenneuron (Leaky Integrator)
- Ein- und Ausgänge werden interpretiert als zeitveränderliche mittlere Spikefrequenzen bzw. Spikeraten -> dynamisches Ratenneuron
- „Leaky Integrator“ steht für einen verlustbehafteten Integrator
- Approximation der Vorgänge an der Synapse (Gewichtsfunktion) als einfache Exponentialfunktion

#### Aktivierungs- bzw Zustandsfunktion $z(t)$
- zeitliche Summationseffekte werden vollständig in die Synapsen verlagert
- Annahme identischer Gewichtsfunktionen g(t) in allen Synapsen
- Somapotential (Aktivierung/Zustand) z(t) ergibt sich durch räumliche Summation aller lokalen PSPs $z_i(t)=\sum_{j=1}^1 w_{ij}(x_j(t)*g(t))$
- Zeitverhalten des Neurons kann im einfachsten Fall beschrieben werden durch eine lineare DGL 1. Ordnung (ohne Herleitung hier): $\tau * z'_i(t)=-z_i(t) + \sum_{j=1}^1 w_{ij}x_j(t)$

#### Die Ausgabefunktion $y = f(z)$:
- dient der Umsetzung der internen Aktivierung zi(t) in eine mittlere Output-Spikefrequenz yi(t)
- erfolgt meist in einem nichtlinearen Zusammenhang, da Nachbildung
  - einer unteren Schwelle erforderlich, die überschritten werden muss, um ein Neuron überhaupt zum Feuern zu veranlassen
  - einer oberen Schwelle erforderlich, die eine maximale Spikefrequenz wegen der vorhandenen Refraktärzeiten modelliert
- Zusammenhänge werden durch nichtlineare Ausgabefunktionen, berücksichtigt, wie z.B. die Fermifunktion (-> Ausgabefunktionen)

#### Typeische Einsatzfelder
- **Neuronale Oszillatoren** zur zeitlichen Synchronisation von Erkennungsvorgängen
- **Rekurrente Neuronale** Netze zur Speicherung und Erkennung zeitlicher Zusammenhänge

### Das formale statische Ratenneuron
- Abgeleitet vom dynamischen Ratenmodell - vollständige Vernachlässigung der zeitlichen Funktionalität des Neurons, insbes. der dynamischen Übergangsvorgänge an den Synapsen
- formales statisches Neuron ist dynamisches Neuron im stationären Zustand, d.h. Vernachlässigung der zeitlichen Übergänge infolge Änderungen des Inputs
- Ein- und Ausgänge werden interpretiert als statische mittlere Spikefrequenzen bzw. Spikeraten -> Ratenneuron
  $$z_i = \sum_{j=1}^n w_{ji}*x_j$$
- Einsatz in vielen neuronalen Standardnetzen (z.B. Multilayer Perzeptron - MLP)
- Modell ist für eine biologienahe Modellierung allerdings zu grob

#### Die Aktivierungs- bzw. Zustandsfunktion
Definition: Lineare oder nichtlineare Abbildungsvorschriften des Eingabevektors x über den Gewichtsvektor $w_i$ auf die Aktivierung $z-i$ des Neurons i

##### Distanzbasierte Aktivierungen - lokal operierende Aktivierungsfunktionen
Vektornormen:
  - Allgemeine p- bzw L-Norm von d: $||d||_p = (\sum_{j=1}^n |d_j|^p)^{\frac{1}{p}}$
  - Betragssummennorm bzw. Manhatten-Norm (L = p = 1): $||d||_1 = \sum_{j=1}^n |d_i|$
  - Euklidische Norm (L = p = 2): $||d||_2 = \sqrt{\sum_{j=1}^n |d_j|^2}$
  - Maximumnorm (L = p = $\infty$): $||d||_{\infty} = max |d_j|$

- Euklidische Distanz $z_i(w_i,x)=||x-w_i||$
- Maximum Norm $z_i(w_i,x)=max|x_j - w_{ij}|$
- Minimum Norm $z_i(w_i,x)=min|x_j - w_{ij}|$
- Mahalanobis Distanz $z_i(x,w_i,C_i)= \sqrt{(x-w_i)^T * C_i^{-1} * (x-w_i)}$ mit $w_i=\frac{1}{N}\sum_{p=1}^N x^{(p)}$ und $C_i= \frac{1}{N}\sum_{p=1}^N (x^{(p)} - w_i)(x^{(p)}- w_i)^T$

**Mahalanobis Distanz**
- statistisch korrigierte Euklidische Distanz des Vektors x von einem Schätzmodell der Klasse (beschrieben durch w und C)
- w: Mittelwertvektor aller N zur Klasse gehörenden Inputvektoren x(p) der Lernstichprobe
- C: Kovarianzmatrix aller N zur Klasse gehörenden Inputvektoren x(p) der Lernstichprobe, (für mittelwertfreie Inputvektoren wird aus der Kovarianzmatrix die Korrelationsmatrix)

**Zusammenfassung** Wichtige Aktivierungsfunktionen für Neuronale Netze
- Skalarprodukt $z(x,w)=\sum_{j=1}^n x_jw_j$
- Euklidische Distanz $z(x,w)=\sum_{j=1}^n \sqrt{\sum_{j=1}^n |x_j - w_j|^2}$
- Maximum Distanz $z(x,w)=max|x_j-w_j|$
- Minimum Distanz $z(x,w)=min|x_j-w_j|$
- Mahalanobis Distanz $(x,w)=\sqrt{(x-w)^T * C^{-1} * (x-w)}$
- Manhatten Distanz $z(x,w)=\sum_{j=1}^n |x_j - w_j|$

#### Die Ausgabefunktion
Grundidee: Wie verhält sich die Ausgangsaktivität $y_i=f(x,w_i)$ (mittlere Spikerate) in Abhängigkeit von der internen Aktivierung $z_i$?

1. Identitätsfunktion $y_i=z_i$
2. Stufenfunktion $y_i = f(z_i) = \begin{cases} 0: z_i \leq T \\ 1: z_i > T \end{cases}$
3. Sigmoid Funktionen (Squashing functions, S-shaped functions)
    - Klasse nichtlinearer, kontinuierlicher, stetiger und stetig differenzierbarer Abbildungsfunktionen
    - modellieren gut neurophysiologisch beobachtbare Sättigungseffekte
    - erlauben parametrische Steuerung der Ausgabefunktion (Schwelle, Steilheit)
  - Fermifunktion $y_i=f(z_i,c)= \frac{1}{1+e^{-c*z_i}}$
    - Gut durch maximale Spikerate des biologischen Neurons motiviert -> bis vor wenigen Jahren sehr verbreitet
    - für $c > 0$ ist $f(z)$ im gesamten DB monoton wachsend
    - Vorteil
      + f(z) im gesamten Definitionsbereich $z \in (-\infty, \infty)$ stetig
      + f(z) ist stetig differenzierbar
    - Nachteil
      - Gradienten werden im "Sättigungsbereich" extrem klein
      - Ausgabefunktion ist nicht 0-zentriert -> bei nicht zentrierten Daten werden Gradienten der Eingabegewichte immer alle positiv oder alle negativ
      - Berechnung der e-Funktion ist rechenaufwändig 
  - Hyperbol. Tangens $y_i=tanh(z_i)=\frac{e^{z_i}-e^{-z_i}}{e^{z_i}+e^{-z_i}}$
    - f(z) im gesamten DB monoton wachsend
    - Vorteile
      + f(z) im gesamten Definitionsbereich $z \in (-\infty, \infty)$ stetig
      + f(z) ist stetig differenzierbar
      + Funktion ist 0-zentriert
    - Nachteil
      - Gradienten werden im „Sättigungsbereich“ extrem klein
      - Berechnung rechenaufwändig
4. Rectified Linear Unit (ReLU) $y_i = f(z_i) = max(0,z_i)$
  - Aktivierung z wird bei 0 gekappt
  - Effektive Berechnung: $y_i = f(z_i) = 0,5*z_i + 0,5 * |z_i|$
  - Vorteil
    + differenzierbar
    + beschleunigt die Konvergenz des Gradientenabstiegs im Vergleich zu Fermi-Funktionen um den Faktor 6 -> wegen des linearen, nicht gesättigten Verlaufs
    + lässt sich sehr leicht implementieren und schnell berechnen
  - Nachteil
    - Ausgabefunktion ist nicht 0-zentriert
    - ReLU Neuronen können während des Trainings “sterben” infolge eines starken Gradientenflusses, der zu einem solchen Gewichtsupdate führt, dass das Neuron durch keinen Input mehr aktiviert werden kann -> Ausgabe für alle Inputs 0 -> Lernen nicht mehr!
  4.1 Leaky ReLU $y_i=f(z_i)=max(0,01z_i,z_i)$
    + Neuronen können nicht „sterben“ 
5. Gaußfunkion $y_i=f(z_i)=e^{-\frac{z_i^2}{2\sigma ^2}}$ Ableitung: $/frac{dy_i}{dz_i}=-\frac{1}{\sigma ^2}* z_i * y_i$
6. Radiale Basisfunktion (RBF) $y_i=f_i(x,w_i,\sigma_i)= exp(-\frac{||x-w_i||^2}{2\sigma_i^2})=exp(-\frac{z_i^2}{2\sigma_i^2})$
  - $\sigma_i$: Breite (Standardabweichung) der Gaußverteilung des Neurons
  - $w_i^T$: Mittelwertvektor von i
  - Jede einzelne Radiale Basis Funktion $f_i$ definiert ein sphärisches rezeptives Feld im Merkmalsraum $R^n$
    - $w_i$ zentriert das rezeptive Feld
    - $\sigma_i^2$ lokalisiert das rezeptive Feld
7. Ellipsiodale Basisfunktion (EBF) $y_i=f_i(x,w_i,C_i)=exp(-\frac{1}{2}(x-w_i)^T * C_i^{-1} * (x-w_i))$
  - für beliebige Kovarianzmatrizen des Inputdatensatzes X
  - basiert auf der Mahalanobis-Distanz $d_m^2(x, w_i, C_i)$

[comment]: <> (Vorlesung 5)
### Das formale statische Neuron als linearer Klassifikator
**Ziel**: 
1. Suche nach einer Trenngeraden (Klassengrenze), die Punktemengen trennt
2. Automatische Klassifikation unbekannter Datenpaare durch Bestimmung ihrer Lage bezüglich der Klassengrenze

**Vorraussetzung**: Trennung der Klassen durch Gerade möglich -> lineare Seprarierbarkeit

**Bestimmung der Trenngeraden**:
1. Geometrische Bestimmung aus der Datenverteilung
2. Belehrung des Neurons mit kategorisierten Trainingsdaten -> Lernen

**Implementierungstrick**: zur Verschiebung der Trenngeraden aus dem Ursprung -> Einführung einer variablen Schwelle, die durch ein Bias-Neuron realisiert wird

**Begrifflichkeit**:
- für $R^2$ -> Trenngeraden
- für $R^3$ -> Trennebenen
- für $R^4$ -> Hyperebenen
- für $R^n$ -> (n-1)-dim. Hyperebenen

## Wesentliche Neuronentypen und deren Einsatz
1. Statisches Ratenneuron (-> Adaline Netz)
  - Skalaproduktaktivierung
  - Lineare Ausgabe
2. Statisches Ratenneuron (-> binäres Hopfielnetz)
  - Skalaproduktaktivierung
  - Binäre Ausgabe
3. Statisches Ratenneuron (-> MLP-Netzwerk)
  - Skalaproduktaktivierung
  - Ausgabe: Sigmoidfunktion
4. Statisches Ratenneuron (-> RBF-Netzwerk)
  - Distanz- /Normaktivierungsfunktion
  - Ausgabe: Gaussfunktion
5. Statisches Ratenneuron mit Zeitfenster (-> TDNN-Netzwerk)
  - Skalaproduktaktivierung
  - Ausgabe: Sigmoidfunktion
6. Dynamisches Ratenneuron (-> Jordan Netz)
  - Skalarproduktaktivierung
  - Leaky Integrator (PT1 - Verhalten)
  - Ausgabe: Sigmoidfunktion
7. Integrate-and-Fire (Spiking) Neuron
  - Skalarproduktaktivierung
  - Leaky Integrator (PT1 - Verhalten)
  - Ausgabe: Delta-Impulse (Spikes)
8. ReLu Neuron (-> Deep Neural Networks)
  - Skalarproduktaktivierung
  - ReLU Ausgabe

# Neuronale Netzwerkmodelle
**Aufgabe**: Verbinde die vorhandenen Neuronen in geeigneter Weise, um ein neuronales Netz zu erzeugen
## Typische Netzwerk-Topologien und Begriffe
- homogene oder strukturierte Netzwerke
- vollständige oder partiell-verkoppelte Netzwerke
- feed-forward oder rekurrente Netzwerke
- Netzwerke mit fester oder variabler Neuronenzahl

Fan-In: mittlere Anzahl der auf ein Neuron konvergierenden Verbindungen\
Fan-Out: mittlere Anzahl der von einem Neuron abgehenden (divergierenden) Verbind.

## Homogene vs. Strukturierte Netze
| Homogene Netze                                                                             | Strukturierte Netze                                                                                                                                  |
| ------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------- |
| sehr formaler und gleichmäßiger Aufbau                                                     | erlauben Integration von strukturellem Wissen über spezifische lokale Verschaltungen und lokale räumliche Zusammenhänge (z.B. bei Bildinformationen) |
| reguläre Netzwerkstruktur                                                                  | zeigen damit einen stark strukturierten Aufbau                                                                                                       |
| als feed-forward oder als rekurrente Netze                                                 | Gibt es als feed-forward oder auch als rekurrente Netze                                                                                              |
| spezielles strukturelles Wissen über lokale Verschaltungen wird darin nicht berücksichtigt |                                                                                                                                                      |
| es gibt kaum biologische Entsprechungen                                                    |                                                                                                                                                      |

## Vollständig vs partiell rekurrente Netze
|                               Vollständig rekurrente Netze                                |                                                          Partiell rekurrente Netze                                                          |
| :---------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------------: |
|             jedes Neuron ist mit jedem anderen Neuron des Netzes verschaltet              |                                    ein Teil der Neuronen des Netzes koppelt Aktivität in das Netz zurück                                    |
|      Einsatz als Autoassoziativspeicher (siehe Kap. B-3) zur Speicherung von Mustern      | typischerweise Einsatz zur Repräsentation und Verarbeitung zeitlicher Zusammenhänge in Datensequenzen (z.B. Signalverläufe, Videosequenzen) |
| erlaubt Wiedererkennung (Rekonstruktion) verrauschter oder unvollständiger Eingangsmuster |                                            Einsatz von dynamischen Neuronen als Kontextneuronen                                             |
|                                                                                           |                                                      Beispiele: Jordan/Elman Netzwerk                                                       |

## Netze mit fester oder variabler Neuronenzahl
|                            Feste Neuronenzahl                            |                                                            Variable Neuronenzahl                                                            |
| :----------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------------: |
| Netztopologie (Anzahl Schichten, Neuronen, Verbindungen) vorab definiert |                                      Netztopologie (Anzahl Neuronen und Verbindungen) vorab unbekannt                                       |
|            sehr formaler Aufbau mit typischer Schichtabfolge             | Netzwerk erhöht oder reduziert die Anzahl der Neuronen und Verbindungen in Abhängigkeit von datenabhängigen internen Repräsentationsfehlern |
|                als feed-forward oder als rekurrente Netze                |                                                      meist als als feed-forward Netze                                                       |

## Das Multi-Layer Perzeptron (MLP) als typisches vollständig verschaltetes Feed-forward Netz

siehe Bild

## Convolutional Neural Network (CNN) als typisches strukturiertes Netz
- Neuronen sind so angeordnet, dass sie auf überlappende Bereiche reagieren -> realisieren Faltungen (Convolutions)
- Jede Schicht eines Volumens basiert auf gelernten Faltungskernen -> bildet sogenannte Feature Maps
- Häufig Verwendung von Subsampling-Layern (Pooling (Bündelung)), die die Dimension des Outputs reduzieren und Invarianzleistungen realisieren

Was sind Faltungsoperationen zwischen den Schichten?
- Neuronen sind lokal verschaltet und teilen sich Gewichte
  - reagieren auf überlappende Bereiche des Inputs
  - kann als diskrete Faltung interpretiert werden
  - Faltung ersetzt Skalarproduktaktivierung
- bilden State-of-the-Art für viele Herausforderungen im Umgang mit Bildern, dafür:
  - Erweiterung auf dreidimensionale Datenstrukturen (Farbkanal, Höhe, Breite eines Bildes)
  -> lokaler Zusammenhang im Bild bleibt erhalten

### 1. Faltungs-Schichten
- Neuronen des Volumens (l) sind lokal begrenzt mit dem Vorgängervolumen (l-1) verschaltet
- Skalarproduktaktivierung -> Summe der Faltungsergebnisse über Volumen (l-1)
- Gewichte zwischen Neuronen der Feature-Map -> in Volumen (l) sind geteilt (shared)
- -> identische Verknüpfung für alle Neuronen in einer Feature-Map p
$$z^{l}(p,u,v)= \sum_{k=0}^{m^{l-1}} \sum_{i=0}{d_1-1} \sum_{j=0}^{d_2-1} o^{l-1} (k,u + i,v + j) * w^{(l)} (p,k,i,j)$$
$$Z^{(l)}(p)= \sum_{k=0}{m^{l-1}} O^{l-1}(k)** W^l(p,k)$$
"Teilbild I * Filter W"


Beispiel für Berechnung einer kompletten Output-Feature-Map
- in CNN: Summation einzelner Faltungsergebnisse
- zusätzlich: gemeinsames Bias-Gewicht 􀡮 für alle Elemente der gleichen Output-Feature-Map und lineare Ausgabe

**Padding**: Erweitern der Input-Feature-Maps um p Randpixel (z.B. Nullen)

### 2. Pooling-Schicht
- dient der Bündelung von mehreren semantisch ähnlichen Features zur:
  - Verbesserung der Robustheit der gelernten Repräsentationen (Invarianzen)
  - Reduzierung des Rechenaufwandes in den anschließenden Schichten
- Output-Volume wird sequentiell über die Ausgaben der einzelnen Feature-Maps bestimmt
- Ausgabe $O_p$ der p-ten Output-Feature-Map: $O^l_p = downsample(O_p^{l-1}, g_l)$ -> Reduktion erfolgt ohne zu lernende Parameter

Arten Pooling-Schichten
- Max-Pooling: Bestimmung des Maximums pro Pooling-Bereich
- Average-Pooling: Bestimmung der Mittelwerte des Pooling-Bereiches

- **Stride**: Größe der vertikalen bzw. horizontalen Verschiebung während Bündelung
- **Padding**: Erweitern des Input-Feature-Maps um p Randpixel (z.B. Nullen)


# Lernparadigmen und deren klassische Vertreter
## Unsupervised Learning
[comment]: <> (Vorlesung 6)
Wesen:
- Lernen ohne externe Überwachung, d.h. kein expliziter Lehrer
- Lernen erfolgt rein datengetrieben in Abhängigkeit von der Statistik der Inputdaten in der Lernstichprobe
- Beim Lernen wird der kontinuierliche Eingaberaum in eine endliche Anzahl von Zuständigkeitsgebieten (-> Voronoi-Regionen) unterteilt / geclustert.
- Dies erfolgt nicht uniform sondern in Abhängigkeit von der Wahrscheinlichkeitsdichteverteilung (WDV) der Inputdaten
$\rightarrow$ Vektorquantisierung des Eingaberaums

Ziel des Lernens: fehlerminimale Quantisierung des kontinuierlichen Eingaberaums mittels geeignet platzierter Referenzvektoren $w_r$ in eine endliche Anzahl von diskreten Zuständigkeitsgebieten

### Vektorquantisierung bzw. Voronoizerlegung
- Anzahl der über den Inputdaten zu positionierenden Referenzvektoren
- dichtere Platzierung in Gebieten mit hoher Inputdichte -> statistischer Lernprozess
- Verbindungslinien zwischen benachbarten Referenzvektoren -> Delaunay-Triangulation
- Regionengrenzen werden durch die Mittelsenkrechten auf diesen Verbindungslinien gebildet -> Voronoi-Tesselation
- Jedes Voronoi-Gebiet bildet eine konvexe Zuständigkeitsregion (abgeschlossen oder unbeschränkt) für den betreffenden Referenzvektor

#### Optimale Vektorquantisierung
Im $\R^2$ erlaubt nur ein hexagonales Raster fehlerminimale Quantisierung! Suche nach den optimal platzierten Referenzvektoren $w_r$ mit ihren zugehörigen Voronoi-Regionen, die eine Quantisierung des Eingaberaumes mit minimalem Quantisierungsfehler E ermöglichen
$E = \frac{1}{N} \sum_{p=1}^{N} || x-w_{r} ||$ mit r als zuständiges Neuron

Ermittlung der Lage der Referenzvektoren und der zugehörigen Voronoi-Regionen über unüberwachte Lernprozesse in Neuronalen Netzwerken und mit statistischen Algorithmen.

#### Typische Vertreter
- Self-Organizing Feature Maps (SOFM) bzw. Kohonen-Maps
– Neural Gas
– Growing Neural Gas (U)
– Learning Vector Quantization (U)
– k-Means-Algorithmus

### Topografische Merkmalskarten – wichtige Organisationsstrukturen des Gehirns
- Wesentliche Cortexregionen (visuell, auditorisch, somatosensorisch, sensomotorisch) zeigen topografische, d.h. nachbarschaftserhaltende Organisationsprinzipien, z.B.
  - Abbildung benachbarter Rezeptoren auf der Retina -> auf benachbarte Neuronen im primären visuellen Cortex
  - Abbildung benachbarter Rezeptoren auf der Basilarmembran des Innenohres -> auf benachbarte Neuronen im auditorischen Cortex
  - Abbildung benachbarter Rezeptoren auf der Hautoberfläche auf benachbarte Neuronen im somatosensorischen Cortex
- Wesen: räumlich benachbarte Rezeptoren sind mit räumlich benachbarten Neuronen im Cortex verbunden
- Grundprinzip topologischer Abbildungen: Umsetzung von Signalähnlichkeiten im Eingaberaum in Lagenachbarschaften der Neuronen des Ausgaberaumes

#### Die somatosensorische Projektion – Beispiel einer topologieerhaltende Abbildungen
- Darstellung der Somatotopie im somatosensorischen Cortex SI.
- eingezeichnete Symbole und Beschriftung sollen die räumliche Zuordnung zwischen Körperoberfläche und Cortex verdeutlichen, wie sie mit lokaler elektrischer Hirnreizung bei wachen Patienten ermittelt wurde.
- Das Grundprinzip einer topolgieerhaltenden Abbildung, die Nachbarschaftserhaltung, wird deutlich: Lagenachbarschaften auf der Körperoberfläche werden auf räumliche Nachbarschaften in den zuständigen cortikalen Bereichen abgebildet.

#### Vorteile nachbarschaftserhaltender Abbildungen
- Lagenachbarschaft ist ein Optimalitätsprinzip der Informationsverarbeitung
  - erzeugt den geringsten Kommunikationsaufwand
  - garantiert geringste Signallaufzeiten
  - damit ist räumliche Kooperation zwischen benachbarten Neuronen möglich -> Robustheit, kollektives, verteiltes „Rechnen“
- Optimale Ressourcenverteilung bei der Abbildung vom Ein- in den Ausgaberaum
- Ermöglichen bei begrenzten neuronalen Ressourcen eine optimale Quantisierung des Eingabesignalraumes (-> Voronoi-Parzellierung)
- Zuordnung der Voronoi-Regionen erfolgt durch unüberwachte, d.h rein datengetriebene Lernprozesse, die die Wahrscheinlichkeitsdichteverteilung der Inputdaten berücksichtigen.

### Self-Organizing Feature Maps (SOFM)
Ziel: Selbstorganisation einer topologieerhaltenden Abbildung des n-dimensionalen Eingangsraumes $R^n$ auf eine m-dimensionale neuronale Kohonenkarte $R^m$ mit einer vorgegebenen Gitterstruktur

#### Der Kohonen-Lernalgorithmus
- Bereitstellung des Trainingsdatensatzes $X = (x^{1}, x^p, ..., x^N)$ 
- Festlegung der Netztopologie und der Dimensionalität des Kohenengitters zur Abbildung $R^n \rightarrow R^m$, bestimmt Art der Gewichtsmatrix $W= (w_{rs})$ zwischen Eingangsraum und Kohonenkarte
  - a Empfänger-Sender-Schreibweise
    - r - Positionsvektor des Neurons in der Kohonenkarte (response)
    - s - Positionsvektor des Inputs im Eingangsraum (stimulus)
  - b Probleme durch Dimensionsreduktion  Topologiedefekte infolge falsch dimensionierter Kohonengitter (siehe später)
- Festlegung der Präsentationsart der Trainingsdaten (zufällig/ zyklisch)
- Bei Bedarf geeignete Neuzusammenstellung des Trainingsdatensatzes (Reihenfolge, Häufigkeit)
- Festlegung der maximalen Anzahl von Lernzyklen tzyk (bei vollständigen X-Präsentationen) bzw. von Lernschritten $t_{max} =N * t_{zyk}$
- Festlegung der Lernparameter und Abbruchkriterien

Ablauf:
1. Gewichtsinitialisierung der $w_rs$:
  - ohne a-priori-Wissen über Problem und Eingangsraum meist zufällige Anfangswerte, z.B. $w_{rs}\in [-0.1,+0.1]$
  - mit a-priori-Wissen definierte Anfangswerte (siehe späteres Beispiel TSP)
2. Stimulusauswahl:
  - Auswahl eines Inputvektors $x^p$ aus dem Inputdatensatz X
3. Response
  - Bestimmung des Best-maching Neurons r´ mit der geringsten euklidischen Distanz zwischen $w_{r´}$ und $x^p$
    $||w_{r'}-x^p|| = min||w_r-x^p||$
  - Festlegung des B-M-Neuron r´ als Zentrum einer lokalen Lernumgebung $h_{rr´}$, beschrieben durch eine geeignete Nachbarschaftsfunktion, z.B. $h_{rr'}=h_0 exp(\frac{||r-r'||^2}{2\sigma^2(t)})$
4. Stimulusgetriebene Adaption der Gewichte des B-M-Neurons und der Neuronen aus seiner lokalen Nachbarschaft: $w_r(t+1)=w_r(t)+\eta(t) * h_{rr'}(t)(x^p -w_r(t))$
5. Zeitliche Veränderung der Lernrate $\eta(t)$ und des Nachbarschaftsradius $\sigma(t)$ der Nachbarschaftsfunktion $h_{rr´}(t)$. 
  Zwei Varianten gebräuchlich:
  - konstante Lernrate $\eta(t)=konst.$
  - Verringerung der Lernrate (über Abkühlungsprozess)
  rekursives Verfahren sinnvoll: $\sigma(t)=\sigma(t-1)*\alpha$ mit $\alpha=(\frac{\sigma_E}{\sigma_A})^{\frac{1}{t_max}}$
6. Datensatz X vollständig präsentiert? Nein: next p($p=p+1$ oder $p=rand(N)$) => 2.
7. Abbruchkriterium $t\geq t_{max}$ erfüllt? Nein: next p ($p=1$ oder $p=rand(N)$) => 2.
8. Ende

Geometrisch interpretiert ist eine 1-D Kohonenkarte zum Ring geschlossen.
Die Neuronen des Kohonengitters sind auf einer 2D-Karte angeordnet. Sie sind mit ihren lokalen Nachbarschaften auch über Kartengrenzen hinweg voll vernetzt, indem die Verbindungen an den Enden umschlagen. Dadurch ergibt sich die Topologie eines Torus.

##### Visualisierung des SO-Prozesses
- Gewichtungen $w_{rs}$ jedes Neurons (Referenzvektoren) werden als Punkte im Inputraum $R^n$ interpretiert
- unmittelbar im Kohonen-Gitter benachbarte Neuronen können ihre Referenzvektoren im Inputraum durch eine Gerade verbinden
- Abbildungsprobleme bei Dimensionsreduktion $R^n \rightarrow R^m$ mit $m<n$

##### Abbildungsprobleme bei Dimensionsreduktion
- Bei Dimensionsreduktion keine Eineindeutigkeit der nachbarschaftserhaltenden Abbildung mehr gegeben
- Erhaltung der Abbildung von der Kohonenkarte in den Inputraum gesichert – nicht aber umgekehrt
- Polygonzug zwischen den Referenzvektoren ähnelt der "Peano-Kurve"

[comment]: <> (Vorlesung 7)
##### Einsatzgebiete topologieerhaltender SOFM
Lösung von Optimierungsproblemen – das Traveling Salesman Problem (TSP)
  - Gesucht: kürzeste geschlossene Tour durch M vorgegebene Städte
  - bei M Städten – durch Permutation (Anordnung der Städte innerhalb der Tour unter Beachtung der Reihenfolge) -> maximal M! verschiedene Touren
  - da
    - a jede Stadt Ausgangspunkt einer Tour sein kann und
    - b jede Tour in zwei verschiedenen Richtungen zurückgelegt werden kann
    ergeben sich 2*M Touren mit gleicher Weglänge
  - $(M-1)/2$ verschiedene geschlossene Routen
  - Rechenaufwand: steigt mit der Fakultät der Problemgröße (Anzahl der Städte) -> wächst damit noch viel stärker als exponentieller Rechenaufwand (für n>6), z.B.
    - bei 10 Städten: 181 440 Touren
    - bei 20 Städten: 6,08 1016 Touren (selbst auf einer 1 GFLOPS Maschine ca. 35 Tage)
    - bei 30 Städten: 4,4 1030 Touren (auf einer 1 GFLOPS Maschine ca. 4000 Mrd. Jahre) (Core i7, 3.4 GHz, 4 Kerne ca. 100 GFLOPS)
  - Fazit: TSP ist ein NP-vollständiges Problem, da es exponentiell wachsenden Rechenaufwand hat, für eine Beispiellösung aber schnell, d.h. mit polynomialem Rechenaufwand verifiziert werden kann
  - Lösungsansatz mit SOFM:
    - Suche nach kürzester Route durch selbstorganisierende Platzierung der Referenzvektoren einer zu einem Ring verschalteten 1D-Neuronenkette im 2D-Inputraum
    - Städte fungieren als Inputdaten, die die Verteilung der Voronoi-Regionen sowie der zugehörigen Referenzvektoren bestimmen
    - Grundprinzip und Ablauf:
      - Jedes Neuron mit 2 Gewichten -> Ortskoordinaten in der Ebene
      - Initialisierung der Gewichtsvektoren mit definierten Anfangswerten (Kreisring) mit Anzahl der Neuronen
      $$w_{rx}=0,35*cos(\frac{2\pi r}{N})+0,5$$
      $$w_{ry}=0,35*cos(\frac{2\pi r}{N})+0,5$$
      - pro Lernschritt zufällige Auswahl einer Stadt als Input
      - Selektion des B-M-Neurons -> Gewichtsadaption für B-M-Neurons & Nachbarn

Visualisierung semantischer Beziehungen – die semanto-topografische Abbildung
  - Grundidee: Nachbildung kognitiver Fähigkeiten durch Erzeugung von neuronalen Karten, die auch semantische Beziehungen zwischen Objektbegriffen widerspiegeln können
  - Beispiel:
    - Erlernen von Ähnlichkeitsbeziehungen zwischen Tierarten
    - Eingabekodierung: Beschreibung der Tierarten über charakteristische Merkmale mittels einer Merkmalsmatrix
  - Probleme der SOFM
    - Kriterium: Optimalität der Verteilung der Gewichtsvektoren im Eingangssignalraum
      Quantisierungsfehler: $E=\frac{1}{N}\sum_{p=1}{N}||x-w_{r'}||$
    - Nachteile des Algorithmus
      1. Lernphase erfordert zunächst erhebliche Zahl von Lernschritten zur Entfaltung des Kohonengitters – Herausbildung einer topologischen Grundordnung des Netzwerkes (-> Zeitaufwand, Kosten)
      2. Topologische Struktur des Kohonengitters muss der topologischen Struktur der zu repräsentierenden „Untermannigfaltigkeit“ des Eingabesignalraumes entsprechen 
        -> erfordert a priori Informationen (nicht immer vorhanden) über Verteilung der Eingabesignale, z.B. in Häufungsgebieten
        -> Struktur des Eingabesignalsraumes kann topologisch derart kompliziert sein, dass Netzdesign praktisch unmöglich ist
    - Repräsentationsprobleme bei inhomogen strukturierter Untermannigfaltigkeit des Inputraumes (Verknüpfung von voneinander separierten Unterräumen verschiedener Dimensionalität)
    - tritt auf, wenn Topologie des Kohonennetzes von der Topologie der Datenpunktmannigfaltigkeit abweicht -> erzeugt suboptimale Verteilung der Referenzvektoren
      - wegen Gitterorganisation des Kohonennetzes ist Positionierung im Raum zwischen den Teilmannigfaltigkeiten möglich -> damit ungenutzte Kodierungsressourcen
    - Abbildung weit vom Optimum entfernt, da unvollständige Verwendung des verfügbaren Satzes von Referenzvektoren

### Das "Neural Gas" Lernparadigma
Unterschiede zum Kohonen-Lernalgorithmus:
- anstatt Verwendung der Nachbarschaftsrelationen der Gewichtsvektoren im externen Kohonengitter – Verwendung der Nachbarschaftsrelationen der Gewichtsvektoren im Eingangssignalraum zur Adjustierung der $w_i$
- anstatt Verwendung der Distanz des Gewichtsvektors $w_i$ zum Input $x^p$–Bestimmung des „Distanzranges“ des Gewichtsvektors $w_i$ unter Berücksichtigung aller anderen Gewichtsvektoren $w_j$
Grundprinzip: 
- ausschließliche Berücksichtigung von Nachbarschaftsrelationen im Eingangssignalraum -> „gasähnliche“ Dynamik der Gewichtsvektoren (ohne Verankerung in einem festen Gitter)
- Bestimmung einer Distanz- oder Nachbarschaftsrangfolge
- Adjustierung des dem Input ähnlichsten Gewichtsvektors $w_{i0}$ sowie der in der Distanzrangfolge nächsten Gewichtsvektoren -> ergibt eine wesentlich effizientere Quantisierung des Eingabesignalraumes
- Wertung: ermöglicht Generierung einer perfekt topologieerhaltenden Gewichtsverteilung zur Vektorquantisierung des Eingangssignalraumes

#### "Neural Gas" Lernalgorithmus
1. Initialisierung der Gewichtsvektoren $w_i(i = 1, ..., m)$
2. Stimulusauswahl: Auswahl eines Inputvektors $x^p$ aus X
3. Response:
   Bestimmung der Distanz- oder Nachbarschaftsrangfolge aller m Gewichtsvektoren wi bezüglich des aktuellen $x^p$
   \rightarrow $k_i(x^p, W)$ – Distanzrang von $w_i$ bezüglich $x^p$ ($k_i = 0$ für $w_i^0; k_i = 1$ für $w_i^1$) 
   \rightarrow jedes $k_i(x^p, W)$ hängt neben $x^p$ von allen anderen aktuellen Referenzvektoren $w_i$ ab -> während des Lernens damit ständige Umordnung der Rangfolge (auch bei gleichen Inputs)
4. Adaption der Referenzvektoren
  $$\delta w_i = \eta(t)* h_{\lambda}*(x^p - w_i)$$
5. Datensatz X vollständig präsentiert? Nein: next $p(p=p+1$ oder p=rand(N)) => 2.
6. Abbruchkriterium $t\geq t_{max\$ erfüllt? Nein: next $p(p=1$ oder p=rand(N)) => 2.
7. Ende

##### Quantisierung komplexer Inputräume mit NG
Wesen: Lernvorgang zeigt eine gasähnliche Dynamik, d.h. ein Verhalten wie das von Molekülen im Schwerefeld der Untermannigfaltigkeiten mit untereinander abstoßender Kraftwirkung

Vorteil: gridfreie Netzwerkstruktur und topologische Struktur der Untermannigfaltigkeit passen optimal zusammen -> ergibt eine optimale Verteilung der Referenzvektoren, kein Referenzvektor bleibt ungenutzt

#### Vergleich zwischen SOFM- und Neural Gas Lernverfahren

|              Kriterien               |                                                                SOFM                                                                 |                                            Neural Gas                                             |
| :----------------------------------: | :---------------------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------: |
|    Definition der Nachbarschaften    |                                        innerhalb des vordefinierten Neuronengitters (n-dim.)                                        |                                    innerhalb des Eingaberaumes                                    |
|           Einschränkungen            |                                                      Dimensionalität des Grids                                                      |                                               Keine                                               |
| Probleme bei der Dimensionsreduktion |                                                        möglich, recht häufig                                                        |                                         prinzipiell keine                                         |
|               Wertung                | adaptiver Vektorquantisierer, der eine Abbildung von Inputähnlichkeiten auf das Neuronengitter (n-dim.) erzeugt (-> Visualisierung) | perfekter adaptiver Vektorquantisierer, der direkt im Eingaberaum arbeitet (ohne eine Projektion) |

### Der k-Means Algorithmus als klassischer VQ
Ziel: den Datensatz so in k Partitionen zu teilen, dass die Summe der quadrierten Abweichungen von den Cluster-Schwerpunkten minimal ist. Mathematisch entspricht dies der Optimierung der Funktion $J = \sum_{i=1}^k \sum_{x\in S} || x_j - \mu_i ||^2$
- Diese Zielfunktion basiert auf der Methode der kleinsten Quadrate, man spricht auch von Clustering durch Varianzminimierung, da die Summe der Varianzen der Cluster minimiert wird.
- Da zudem die quadrierte Euklidische Distanz ist, ordnet k-Means effektiv jeden Datenpunkt dem nächstgelegenen (nach Euklidischer Distanz) Clusterschwerpunkt zu.
- Da die Suche nach der optimalen Lösung schwer ist (NP-schwer), wird im Normalfall ein approximativer Algorithmus verwendet.
- Der am häufigsten verwendete approximative k-Means-Algorithmus ist der Lloyd-Algorithmus, der oft als "der" k-means Algorithmus bezeichnet wird, obwohl Lloyd diesen Namen nicht verwendet hat.
- Lloyd’s Algorithmus besteht aus drei Schritten:
  1. Initialisierung: Wähle k zufällige Mittelwerte (Means) $m_1,..., m_k$ aus dem Datensatz.
  2. Zuordnung: Jedes Datenobjekt $x_j$ wird demjenigen Cluster $S_j$ zugeordnet, bei dem die Cluster-Varianz am wenigsten erhöht wird.
    $S_i^{(t)}= {x_j: ||x_j -m_i^{(t)}||^2 \leq ||x_j - m_{i*}^{(t)}||^2 }$ für alle $i*=1,...,k$
  3. Aktualisierung: Berechne die Mittelpunkte der Cluster neu:
  - Die Schritte 2-3 werden dabei so lange wiederholt, bis sich die Zuordnungen nicht mehr ändern.


## Reinforcement Learning
[comment]: <> (Vorlesung 8)
### Einordnung und Wesen
- Überbegriff für eine Reihe von Methoden des Maschinellen Lernens, bei denen ein Agent den Nutzen von Aktionsabfolgen in einer Welt bestimmt
- dient dem völlig selbständigen Erlernen komplexer Wahrnehmungs-Handlungs-Zusammenhänge auf Basis einer Handlungsbewertung nur durch ein unspezifisches Leistungsbewertungssignal (Belohnung/Bestrafung)
- zwischen überwachtem und unüberwachtem (datengetrieben) Lernen
- Unterschied zum Supervised Learning: Leistungsbewertungssignal ist nicht instruktiv (spezifisch mit konkreten Hinweisen zur Verbesserung der Abbildung), sondern ausschließlich evaluativ (bewertend)

$\rightarrow$ „Learning with critic instead of learning with teacher.“

Haupteinsatzgebiete: Robotik, optimale Steuerungen, Spielsteuerungen, ....

### Grundidee
- Entscheidungsmodul (Agent) muss wiederholt Aktionen auswählen, um ein System in gewünschter Weise zu beeinflussen und in einen Zielzustand zu überführen.
- Bei jeder Entscheidung erhält der Agent eine direkte Belohnung / Bestrafung (Reinforcement), wobei sich die erhaltenen Belohnungen über die Zeit akkumulieren.
- Reinforcement Lernen (RL) beschäftigt sich mit dem Problem, durch Lernen solche Entscheidungsstrategien zu finden, die bezüglich dieser akkumulierten Reinforcements optimal sind.
- Ziel ist es, nur mittels lokal optimaler Entscheidungen eine global optimale Strategie zu erhalten.

### Wo steckt das Wissen im RL-Agenten ?
- In so genannten State-Action Values (Q-Werten), die kodieren, welches long-term Return R erhalten werden kann, wenn man in einem bestimmten State s j eine bestimme Aktion a i ausführt
- Einfachste Form: Tabelle Q( s , a )
- Fragen und Probleme:
  1. Woher bekommt man die Q-Werte? -> Lernverfahren
  2. Exponentielles Wachstum der Tabellengröße mit der Anzahl der Dimensionen d des State Spaces

## Q-Learning – der bekannteste RL Algorithmus
On-line Lernverfahren nach [Watkins and Dayan, 1992], das auf einer inkrementellen Verbesserung der Schätzung Q(s,a) mittels “stochastischer Approximation” basiert


## Supervised Learning
### Kurzcharakteristik
- Lernverfahren, bei dem gelabelte Daten-Samples $X = {(x_1 , y_1 ), (x_2 ,y_2 ), ...,(x_n , y_n )}$ bzw. $X = {(x_1 , t_1 ), (x_2 ,t_2 ), ...,(x_n , t_n )}$ zur Approximation einer unbekannten, Daten generierenden Funktion genutzt werden.
- Das Labeln der Trainingsdaten erfolgt durch Lehrer meist offline.
- Soll eine unbekannte Funktion approximiert werden, deren Funktionsoutput y nur diskrete Klassen/Kategorien besitzt, dann müssen die Daten-Samples diskret gelabelt werden mit t. -> Klassifikation / Kategorisierung
- Soll eine unbekannte, Daten generierende Funktion approximiert werden, deren Funktionsoutput y kontinuierlich (reell) ist, dann müssen die Daten Samples auch reellwertig gelabelt werden mit t -> Funktionsapproximation / Regression

### Erlernen von Abbildungen – Das Konzept der Assoziativspeicher
- Wesen: Erlernen von Abbildungen zwischen zu assoziierenden Musterpaaren (x, t) aus der Lernstichprobe
- Wesen: $t=x(Vorr. m=n)$
- Zweck: Ausgabe des korrekten, ungestörten Inputs (Outputs) x bei Präsentation eines gestörten oder unvollständigen Inputs X*
- Einsatz: Mustervervollständigung, Rauschunterdrückung, Feature Learning in Deep Neural Nets
- Einfachstes Lernverfahren: Hebb‘sches Lernen (Steinbuch‘sche Lernmatrix

### Der Error-Backpropagation Algorithmus
- Erlaubt eine Verallgemeinerung der auf einschichtige Netze beschränkten Delta-Lernregel auf mehrschichtige Netze mit beliebiger Anzahl von Schichten.
- Problem: Ein direktes Fehlersignal zwischen Teach-Vektor und Output-Vektor des Netzes existiert nur für die Output-Schicht.
- Für alle Hidden-Schichten muss das Fehlersignal von der Output-Schicht zurückpropagiert und rückwirkend aufakkumuliert werden (daher der Name Error-Backpropagation) -> fungiert dann als „internes Fehlersignal“
- Fehlerakkumulation erfolgt gewichtet mit den vorhandenen „alten“ Gewichten der betreffenden Verbindung.
- erlaubt damit eine rekursive Berechnung der notwendigen Gewichtsänderungen vom Output zum Input.
- Implementierung: damit stets 2 Sätze von Gewichtsparametern erforderlich:
  - Satz „alter Gewichte“ zum Generieren der aktuellen, internen Netzaktivität und zum Zurückpropagieren der Fehlersignale
  - Satz „neuer Gewichte“, die die Gewichte nach dem Lernschritt kodieren; kommen erst im nächsten Zyklus zum Einsatz, dann wieder als „alte Gewichte“

## Verallgemeinerte Delta-Lernregel
### der Error Backpropagation Algorithmus
1. Betrachtung für die Ausgabeschicht L (entspricht Betrachtung nach Delta-Regel)
2. Betrachtung für zwei beliebige Schichten l und l-1
    -> erlaubt rekursive Berechnung für l-schichtige Netze vom Ausgang auf den Eingang

### Fazit
- verallgemeinerte Delta-Lernregel lässt sich auf beliebige Anzahl von Schichten erweitern
- Fehlerterme berechnen sich rekursiv aus der gewichteten Summe der Delta-Fehler der nachfolgenden Schicht l, multipliziert mit der Ableitung der Ausgabefunktion der aktuellen Schicht l-1 -> ist gut vektorisierbar
- Die zwei prinzipiellen Trainingsmodi können auch hier unterschieden werden:
    - Direct Learning: berechnete Gewichtsänderung wird sofort nach der Verarbeitung des Trainingsmusterpaares ausgeführt
    - Batch Learning: berechnete Gewichtsänderung wird über alle Musterpaare des Trainingssets akkumuliert und erst nach Verarbeitung aller Musterpaare ausgeführt

## Ausgabekodierung bei der Klassifikation
- Häufig verwendet: Bei Klassifikationsproblemen Umwandlung der reelwertigen Netzausgaben in eine binäre Ausgabe durch einfache Bestimmung des Maximums zur Markierung der am stärksten aktivierten (und damit erkannten) Klasse/Kategorie
- Häufig benötigt: Klassenzugehörigkeiten, die nicht nur die einzelne Ausgabe (Klasse) sondern auch alle anderen Ausgaben (Klassen) mit berücksichtigen
-> Softmax Ausgabe

### Softmax Ausgabe
- Spezielle Ausgabefunktion der ganzen Ausgabeschicht statt der bisherigen Ausgabefunktion pro Einzelneuron
- ermöglicht die Schätzung von Klassenzugehörigkeiten 
- dazu Abbildung (“Quetschen”) eines N-dimensionalen Vektors von beliebigen reelwertigen Ausgabeaktivitäten auf einen N-dimensionalen Vektor von positiv reelwertigen Ausgaben im Bereich (0, 1), die sich alle zu 1 addieren.

# Moderne Verfahren für große Datensets

## Deep Neural Networks

## Anwendungsbeispiele


[comment]: <> (Vorlesung 9)
[comment]: <> (Vorlesung 10)
[comment]: <> (Vorlesung 11)
[comment]: <> (Vorlesung 12)