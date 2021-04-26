# Softwareprojekt 2021 - Übersicht

# Themen
| Nr. | Thema                                                                                | Fachgebiet                                    |
| --- | ------------------------------------------------------------------------------------ | --------------------------------------------- |
| 1   | Abwehr von Denial-of-Service-Angriffen durch effiziente User-Space Paketverarbeitung | Telematik / Rechnernetze                      |
| 2   | Robustes Load-Balancing durch Software Defined Networking                            | Telematik / Rechnernetze                      |
| 3   | 6DOF-Simulator                                                                       | Virtual Worlds and Digital Games Group        |
| 4   | Ground station to manage experiments with multiple UAVs                              | Fachgebiet Integrierte Kommunikationssysteme  |
| 5   | Prüfungsgenerator                                                                    | Virtual Worlds and Digital Games Group        |
| 6   | Visualize Neural Networks                                                            | Virtual Worlds and Digital Games Group        |
| 7   | Remote AR                                                                            | Virtual Worlds and Digital Games Group        |
| 8   | Optimierte Visualisierung von Entwicklungskomponenten                                | System- und Software-Engineering CARIAD SE    |
| 9   | REST-API für Metamodelldatenbanken                                                   | System- und Software-Engineering              |
| 10  | ? to be defined??                                                                    | Softwarearchitekturen und Produktlinien       |
| 11  | Smart City Ilmenau                                                                   | Datenbanken und Informationssysteme           |
| 12  | Android-App zur 3D-Kopfvermessung für die Biomedizintechnik                          | Biomedizinische Technik                       |
| 13  | E-AVR – Emulator für die ATmega µC-Familie zur Einbettung in verteilte Lernszenarien | Fachgebiet Integrierte Kommunikationssysteme  |
| 14  | Standard-Bibliothek für ausführbare UML-Modelle                                      | System- und Software-Engineering              |
| 15  | Ball and Hoop                                                                        | Regelungstechnik                              |
| 16  | Simulation framework for autonomous driving on small-scale vehicle                   | Prozessoptimierung                            |
| 17  | Real time representation and visualization of distributed software systems           | System- und Software-Engineering REWE digital |

## 1. Abwehr von Denial-of-Service-Angriffen durch effiziente User-Space Paketverarbeitung
### Szenario
SwitchDenial-of-Service-Angriffe (DoS-Angriffe) stellen eine ernstzunehmende Bedrohung dar. Motive für solche Angriffe sind finanzielle oder auch politische Gründe. Das Ungleichgewicht zwischen Einfachheit bei der Erzeugung von Angriffsverkehr gegenüber komplexer und ressourcenintensiver DoS-Abwehr verschärft das Problem zusätzlich. Obwohl gelegentlich Erfolge im Kampf gegen DoS-Angriffe erzielt werden (z.B. Stilllegung einiger großer „DoS-for-Hire“ Webseiten), vergrößert sich das Datenvolumen durch DoS-Angriffe stetig weiter. Allein zwischen 2014 und 2017 hat sich die Frequenz von DoS-Angriffen um den Faktor 2,5 vergrößert und das Angriffsvolumen verdoppelt sich fast jährlich. Die Schäden werden weltweit zwischen 20.000 und 40.000 US-Dollar pro Stunde geschätzt.

Im Bereich kommerzieller DoS-Abwehr haben sich einige Ansätze hervorgetan (z.B. Project Shield, Cloudflare, AWS Shield). Der Einsatz kommerzieller Lösungen birgt einige Probleme, etwa (mitunter erhebliche) Kosten. Auch wenn finanzielle Hürden irrelevant sind, so bleibt das Problem des notwendigen Vertrauens, welches dem Betreiber einer DoS-Abwehr entgegengebracht werden muss. Folglich ist eine effiziente Abwehr von DoS-Angriffen mit eigens errichteten und gewarteten Mechanismen ein verfolgenswertes Ziel – insbesondere wenn sich durch eine Maßnahme mehrere Systeme zugleich schützen lassen.

### Aufgabe
Im Softwareprojekt soll ein System zur Abwehr von DoS-Angriffen entstehen, welches lokal administriert werden kann und zwischen Internet-Uplink und dem zu schützenden System (oder einer Menge von Systemen) platziert wird (siehe Abbildung 1).
Dabei entstehen zwei signifikante Herausforderungen:
1. Das Verkehrsvolumen von sowohl Angriffsverkehr als auch Nutzdatenverkehr ist extrem hoch und
2. eine Unterscheidung zwischen den beiden Verkehrsarten ist nicht trivial.

Eine Verarbeitung des eingehend angesprochenen Verkehrsvolumens mit konventioneller Paketverarbeitung ist unmöglich.
Daher soll das Framework „Data Plane Development Kit“ (DPDK) zum Einsatz kommen, welches den üblichen Verarbeitungspfad von Datenpaketen im Kernel des Betriebssystems durch effiziente Verarbeitung im User-Space ersetzt.
Die im Projekt anvisierte Datenrate liegt bei 20-25 Gbit/s.

Bezüglich der Unterscheidung von Angriffs- und Nutzdatenverkehr ist zunächst eine Einschränkung auf gewisse Angriffstypen vorzunehmen.
Grundlage hierfür ist die Beobachtung des eingehenden Verkehrs – je nach entworfener Architektur können dabei auch die Kommunikationsendpunkte aktiv Feedback liefern.
Im Fokus werden TCP SYN Flood, TCP Small Window, sowie klassische Erschöpfung der Bandbreite mit kleinen Paketen sein.
Die Geschwindigkeit von Klassifikation und Filterung des Verkehrs hängt maßgeblich von effizienten Datenstrukturen und einer effizienten Umsetzung in C++ ab.
Außerdem darf das vor dem DoS-Angriff schützende System wiederum keine Angriffsfläche erzeugen.

### Lernziele
Neben den Kernzielen des Softwareprojekts, wie dem Erlernen von effektiver Gruppenarbeit, der strukturierten Analyse von Problemen und natürlich der Schulung praktischer Fähigkeiten, wird in diesem Projekt Wissen zu IT-Security, moderner Netzwerkprogrammierung und Paketverarbeitung im User-Space vermittelt.

### Entwicklung
- C++
- Nutzung des Frameworks DPDK

### Koordination
Vom Fachgebiet zur Verfügung gestellt: Zulip, Jitsi, Gitlab


## 2. Robustes Load-Balancing durch Software Defined Networking   
### Szenario
Software-Defined Networking (SDN) erlaubt es das Verhalten von Switches sehr genau zu steuern. Insbesondere können einzelne TCP-Flows im Netzwerk umgeleitet werden. Die Steuerung der Switches erfolgt hierbei in der Regel durch sogenannte Controller, die zentrales Routing durchführen und "erweiterte" Forwarding-Tabellen auf die Switches verteilen.
Ein rein zentrales Vorgehen hat jedoch einige Nachteile. Neben möglichen Robustheits- und Latenzproblemen, müssen zentrale Controller auch viele Daten sammeln, um korrekte Entscheidungen zu treffen, und bringen eine erhebliche Komplexität mit sich. In einigen Anwendungsfällen ist es jedoch auch möglich SDN lokal einzusetzen, beispielsweise indem Server sich gegenseitig Verkehr auf einem Switch zuteilen.

### Aufgabe
Im Rahmen des Softwareprojektes soll eine Implementierung des OpenFlow-Protokolls entstehen, mit der Verkehr lokal gesteuert werden kann. Diese Steuerung erfolgt wie erwähnt normalerweise über zentrale Controller. In diesem Fall sollen jedoch die Server oder Netzübergangspunkte selbst die Steuerung übernehmen, sodass ein Framework entwickelt werden muss, über welches dies einfach geschehen kann. Beispielsweise könnten neu aufgebaute TCP-Flüsse auf den Server mit der niedrigsten Last geleitet werden, während alle existierenden Flüsse auf dem Server belassen werden, auf dem sie initial terminiert wurden.
Herausforderungen sind bei diesem Vorgehen liegen in der Robustheit und Sicherheit des Konstruktes, bei gleichzeitiger Wahrung niedriger Latenzen. Daher soll das Framework in der Programmiersprache Rust entwickelt werden, welche sich auf diese Anforderungen spezialisiert hat. Architekturelle Inspirationen können Projekte wie Ryu (siehe https://ryu-sdn.org) bieten.

### Lernziele
Neben den Kernzielen des Software-Projektes, wie dem Erlernen von effektiver Gruppenarbeit, der strukturierten Analyse von Problemen und natürlich der Schulung praktischer Fähigkeiten, wird in diesem Projekt Wissen zu sicherer und effizienter Netzwerkprogammierung sowie Prinzipien und Protokollen für Software Defined Networking vermittelt.

### Entwicklung
- Rust

### Koordination
Zulip, Gitlab, Jitsi

## 3. 6DOF-Simulator
### Beschreibung:
Für Virtual Reality und Augmented Reality sind Trackingdaten essenziell. Diese bestehen aus Positions- und Rotationsdaten einzelner Objekte. Objekte können hier zum Beispiel das Smartphone, spezielle Hardware wie der HTC Vive Tracker, aber auch einzelne Körperteile wie der Kopf (Head-Tracking) oder Hände bzw. Finger (Hand-Tracking) sein.

Diese Trackingdaten liegen werden üblicherweise in 6 Freiheitsgraden benötigt, drei für die Position (x,y,z) und drei für die Orientierung bzw. Rotation (Eulerwinkel; Yaw, Pitch, und Roll).

Je nach Anwendung werden diese Trackingdaten dann entweder einzeln (z.B. im Fall des Telefons oder eines Trackers) genutzt oder in komplexe Datenstrukturen wie z. B. Ganzkörper-Skellete oder Hände integriert um die korrekte Darstellung und Interaktion überhaupt zu ermöglichen.  

In diesen Anwendungsbeispielen werden die Trackingdaten - also Position und Orientierung - live generiert. Das erschwert allerdings häufig die Entwicklung, da man die Hardware vor Ort haben muss und reproduzierbare Tests oft schwer sind. Daher ist es wünschenswert, eine Tool zu haben, welches unterschiedliche Trackingdaten simulieren kann.

### Aufgabe
Short: Implementierung einer GUI-Anwendung die Positions (x,y,z) und Orientierung (Yaw, Pitch, Roll) generiert bzw. simuliert und in untersch. Formaten per Netzwerk versendet um z.B. Roboternavigation zu testen (z.B. Python).

Um die Entwicklung für Anwendungen zu erleichtern, die solche Daten nutzen, soll im Softwareprojekt ein System entstehen, das es ermöglicht Trackingdaten zu erstellen und dann per Netzwerk in unterschiedlichen Formaten zur Verfügung zu stellen. Das System besteht aus zwei Komponenten. Einer selbstständigen Anwendung die Trackingdaten versendet und einer Bibliothek, die in andere Programme eingebunden werden kann und die Trackingdaten empfängt.

Bestandteile der finalen Anwendung sind unter anderem:
- Auswahl unterschiedlicher Typen von Trackingdaten (Ganzkörper, Hand, Objekt)
- Auswahl unterschiedlicher Koordinatensysteme
- Einstellmöglichkeiten zur Sendegeschwindigkeit
- Möglichkeit zum Senden von sich Verändernden Daten (z. B. Handbewegung, Objektdrehung)
- Möglichkeiten zur Fehlersimulation (Lag, Loss, Jitter)

### Lernziele
Neben den Kernzielen des Software-Projektes, wie dem Erlernen von effektiver Gruppenarbeit, der strukturierten Analyse von Problemen und natürlich der Schulung praktischer Fähigkeiten, wird in diesem Projekt Wissen über Tracking für z.b. Robotik, und insb. Virtual Reality (VR) und Augmented Reality (AR) erworben. Darüber hinaus wird auch allgemeines Domänenwissen in diesen Bereichen erworben um den Kontext der Aufgabe zu verstehen. Möglichkeiten zum Testen von AR/VR Hardware besteht um auch einen praktischen Einblick zu erhalten.

### Entwicklung:
- C++ oder Python für die Standalone-Anwendung;
- C#/C++ für die Bibliotheken
- Unity/Unreal Engine zum Testen
- Entwicklungsumgebung kann frei gewählt werden.
- Gitlab der TU Ilmenau für Projektmanagement
- Agiles Vorgehensmodell wird empfohlen

### Kommunikation:
- Webex, Discord, eMail
- Gitlab TU Ilmenau

## 4. Ground station to manage experiments with multiple UAVs
### Szenario
In der Arbeitsgruppe ICS an der TU Ilmenau arbeiten wir in der Simulation und experimentell mit autonomen Multi Unmanned Aerial Vehicle (UAV)-Systemen. Unsere experimentelle Plattform besteht aus mehreren UAVs, die autonom fliegen können und durch verschiedene Technologien untereinander kommunizieren können. Dank eines Linux-Bordcomputers können wir verschiedene Algorithmen auf den UAVs implementieren und verschiedene Experimente aufbauen. 

Wenn wir ein Experiment mit mehreren UAVs durchführen, verbinden wir uns über ein Terminal mit jedem UAV, um die Mission des UAVs auszuführen. Für jedes UAV gibt es ein Terminal. Das Projektziel ist es, eine Bodenstation mit einer grafischen Benutzeroberfläche zu entwerfen und zu implementieren, die die Konfiguration, Überwachung und Steuerung eines Experiments mit mehreren UAVs erleichtert.
Die Hauptfunktionalitäten der Bodenstation sind:
- Experiment configuration: ermöglicht die Angabe der IDs der UAVs, die Teil des Experiments sind, und die Konfiguration von Parametern im Zusammenhang mit dem Experiment (z. B. Geschwindigkeit der UAVs).
- Experiment synchronization: stellt sicher, dass die UAVs das Experiment gleichzeitig oder mit einem bestimmten Versatz starten.
- Experiment monitoring: visualisiert die Position und den Zustand der einzelnen UAVs während des Experiments.
- Experiment control: ermöglicht es, allen UAVs Befehle zu erteilen (z. B. Landung, Rückkehr zum Start, Stopp)
- Error management: identifiziert und zeigt Fehler während des Experiments an (Verbindungsabbrüche, Algorithmusprobleme, etc.). Es ermöglicht dem Benutzer auch einige Aktionen wie Stopp oder Landung (siehe Missionskontrolle)
- Data processing: sammelt die Logdateien der UAVs und generiert Zahlen mit Informationen wie Flugbahnen, relative Abstände zwischen den UAVs, Missionszeit usw.
- Redundancy in the communication: zwei Kommunikationsverbindungen zu jedem UAV

Die entwickelte Bodenstation kann in unserer Simulationsumgebung entwickelt werden und soll mit den realen UAVs validiert werden.

### Entwicklung
- Programming language: Python
- OS: Linux- Ubuntu and Windows
- API: Dronekit
- Tools
    - Version Control: Github
    - Project management: free choice
    - UAV/Copter simulation: Morse Simulator, Ardupilot (SITL)
    - Communication: WiFi + Zigbee, LoRa, LTE

## 5. Prüfungsgenerator
### Beschreibung:
Dieses Projekt setzt sich als Ziel einen regelbasierten Prüfungsgenerator zu entwickeln. Insbesondere in der aktuellen Corona-Pandemie ist die Durchführung von Take-Home-Klausuren und  Onlineprüfungen ein wichtiges Thema geworden. Die Erstellung von unterschiedlichen Prüfungen kann hierbei, bei einer Vielzahl an notwendigen Versionen, sehr umfangreich sein. Mit diesem Tool soll es möglich sein sehr einfach neue Prüfungen zu erstellen, Fragen zu definieren, Gruppierungen anzulegen, Aufgaben zu randomisieren und vieles mehr. 

Durch eine GUI sollen Regeln definiert werden können, welche dazuführen, dass aus LaTeX-Snippets eine Prüfung automatisiert zusammengestellt wird. Dieses Regelwerk beinhaltet unter anderem: Maximale Anzahl an Punkten, Anzahl an Zusatzpunkten, Fragetypen, Fragekategorien oder voraussichtlich benötigte Zeit für die Klausur. Fragen sollen aus einer lesbaren Datenstruktur ausgelesen werden können (XML, JSON, Excel, ...).

Am Ende soll ein LaTeX-Dokument entstehen mit Titelblatt und Fragen, welches automatisiert in verschiedene Ausgabeformate (vorrangig PDF) konvertiert wird.

### Entwicklung:
- Entwicklungsumgebung: Visual Studio oder Qt
- Programmiersprache: Python, C# oder C++
- GUI: WPF, Qt, PyQt, ...
- Verwendete Tools: Gitlab (inkl. Wiki & Issue Board), Discord
- Projektmanagement: frei wählbar (Favoriten: agile Methoden wie SCRUM oder Kanban)

### Kommunikation:
Die Kommunikation gerne per Discord und alternativ per WebEx und Mail. Erster Kontakt bitte per Mail (s.u.) zur weiteren Absprache.

## 6. Visualize Neural Networks
### Hintergrund:
Künstliche neuronale Netze haben in den letzten Jahren zu bemerkenswerten technologischen Fortschritten in verschiedenen Bereichen beigetragen.
Durch die Nutzung von Deep Learning Architekturen, konnte die Komplexität der Aufgaben, die solche Netzwerke bewältigen können enorm gesteigert werden.
Andererseits stieg hierdurch auch die Komplexität der Netzwerke selbst, sodass deren Aufbau und Funktionsweise oft schwer zu vermitteln sind.
Eine geeignete Repräsentation, die sowohl technisch korrekt und informativ, als auch optisch ansprechend und leicht verständlich ist, wäre dabei von enormem Vorteil.
Aktuell existierende Darstellungen scheitern oft an mindestens einem dieser Punkte [1], [2], [3].

### Aufgabe:
Aufbauend auf einer bereits bestehenden Python-Implementierung, die die Visualisierung eines neuronalen Netzwerkes als LaTeX-Code erzeugt, soll eine Applikation erstellt werden, die diese Visualisierung automatisch aus einem bestehenden Netzwerk-Modell (Pytorch bzw. Tensorflow) erstellen kann.
Das Programm sollte daher zunächst die einzelnen Komponenten und deren Verbindungen erkennen und analysieren und diese dann in die entsprechenden Visualisierungs-Blöcke überführen.
Anschließend sollten manuelle Anpassungen des Nutzers möglich sein, um zusätzliche Bearbeitungsmöglichkeiten zu erlauben und mögliche Fehler zu korrigieren. 

### Entwicklung:
- Entwicklungsumgebung: beliebig
- Programmiersprache: Python, TeX (PGF/TikZ)
- Versionierung: Gitlab

### Kommunikation:
WebEx, Discord, E-Mail

## 7.  Remote AR
?

## 8.  Optimierte Visualisierung von Entwicklungskomponenten
### Szenario
Die steigende Anzahl an Funktionen in modernen Fahrzeugen und die zunehmende Komplexität der verbauten Systeme erfordern immer detailliertere und umfangreichere Beschreibung der Funktionalität der einzusetzenden Steuergeräte einzeln und im Verbund. Dazu ist eine Vielzahl an Dokumentation zu erstellen und vorzuhalten, bspw. zu den verwendeten Kommunikationsprotokollen und Bussystemen, den einzelnen Softwarefunktionen, Prozessschritten, oder auch Tests und Reports.

Dabei werden von einer Vielzahl von Mitarbeitern an unterschiedlichen Standorten und Unternehmen, teilweise auch in anderen Ländern technische Dokumente verfasst, die ihre Wirkung erst im Zusammenspiel entfalten.

Ziel des Projektes soll es daher sein, die in der technischen Dokumentation enthaltenen Daten in eine für den einzelnen Anwender optimierte Visualisierung zu übertragen. Dabei soll parallel nach mehreren Suchbegriffen gesucht werden können und die daraufhin gefundenen Sinnabschnitte in einem neuen Dokument zusammengestellt werden. Die Suchbegriffe sollen dabei selbst vom System um vermutete Schreibweisen - ausgehend von einem Basisbegriff und einer eventuellen Abkürzung - ergänzt werden, so dass unterschiedliche Schreibweisen, wie bspw. mit enthaltenen Bindestrichen oder Leerzeichen auch gefunden werden können.

Als Quellen dienen Verzeichnisse in einem Dateisystem, die Dokumente in gängigen Datenformaten im Büro- und Entwicklungsumfeld enthalten, wie PDF, DOCX, oder XLSX. Tritt ein Suchtreffer in mehreren Dateien auf und verweisen diese aufeinander, so sind die Zusammenhänge grafisch abstrakt darzustellen, inkl. der jeweiligen Anzahl der Suchtreffer. Hierbei ist eine übersichtliche Darstellung auch großer Datenmengen und ein intuitives Bewegen innerhalb der Visualisierung notwendig (Zoom, Verfolgung von Verzweigungen, etc.). Der konkrete Inhalt eines Suchtreffers bzw. der passende „Sinnabschnitt“ in dem er auftrat, soll anschließend in ein zur Suchanfrage neu erstelltes Dokument übernommen werden.

Die gewonnene Darstellung und Information soll sich abschließend auch exportieren lassen (z.B. HTML/PDF). Für den Praxiseinsatz sind außerdem eine intuitive Nutzeroberfläche und das Speichern/Laden der erstellten Konfigurationen erforderlich.

### Kommunikation
Da zur Zeit ja Präsenztermine zur Abstimmung leider nicht möglich sind, ist der Plan auf alternative Kommunikationswege auszuweichen. Glücklicherweise haben wir damit bereits Erfahrung aus den letzten Softwareprojekten, da auch dort viele Themen virtuell abgestimmt wurden. Gut funktioniert haben dabei Teams und Slack aber auch ähnliches ist möglich.
- MS Teams
- Slack

## 9.  REST-API für Metamodelldatenbanken
?

## 10. ? to be defined?? 
?

## 11. Smart City Ilmenau
?

## 12. Android-App zur 3D-Kopfvermessung für die Biomedizintechnik
?

## 13. E-AVR – Emulator für die ATmega µC-Familie zur Einbettung in verteilte Lernszenarien
### Beschreibung:
Konzeption und Entwicklung eines interaktiven Automatennetz-Entwicklungstools,
Unterstützung aller Algorithmen für sequentielle Schaltungen der Lehrveranstaltungen Rechnerorganisation, Technische Informatik und Schaltsysteme,
Export-Möglichkeit der Entwürfe in das GOLDi Remotelab

### Entwicklung:
- Programmiersprachen: HTML5, CSS, TypeScript
- Frameworks und Bibliotheken: JS Redux, Material Design WebComponents
- Tools: GitLab, NPM
- Ein Vorgehen nach dem Wasserfall-Modell wird empfohlen.

### Kommunikation:
DFNconftool, NextCloud TU Ilmenau, GitLab TU Ilmenau, Skype, E-Mail

## 14. Standard-Bibliothek für ausführbare UML-Modelle
### Motivation
In der modellgetriebenen Softwareentwicklung dienen Modelle zur Darstellung, Analyse und Problemlösung des betrachteten Sachverhalts über alle Stufen eines Entwicklungsprozesses hinweg. Hierzu werden Modelle nicht nur zur Beschreibung und Dokumentation von Entwürfen verwendet, sondern können beispielsweise genutzt werden, um automatisiert Artefakte (wie z.B. Quellcode) aus ihnen zu erzeugen. Dieses Vorgehen sowie die damit verbundene Abstraktion der technischen Details auf allgemeinere Konzepte soll die Effizienz von modernen Softwareentwicklungsprozessen erhöhen, Fehlerquellen vermeiden und gewährleisten, dass zeitliche und finanzielle Budgets eingehalten werden können.

Eine Modellierungssprache, die sich in der Domäne der System- und Softwareentwicklung als ein de facto Standard etabliert hat, ist die Unified Modeling Language (UML) der Object Management Group (OMG). Aktuelle Bestrebungen in modellgetriebenen Paradigmen im Zusammenhang mit UML-Modellen ist xUML (executableUML), also das Erzeugen von (ausführbaren) Anwendungen direkt und vollständig aus konzeptionellen Modellen; beispielsweise durch die Simulation/Ausführung eines Modells wie ein normales Programm.

Um die eher semi-formale UML wie eine kompilierbare Programmiersprache behandeln zu können, sind jedoch präzise Definitionen ihrer Ausführungssemantik notwendig (z.B. "Wie genau muss sich ein bestimmter Aspekt eines Aktivitätsdiagramms verhalten, wenn man es simulieren würde?"). Als ein erster Schritt zur Verwirklichung von xUML, standardisierte die OMG die Ausführungssemantik von UML-Aktivitätsdiagrammen in der fUML-Spezifikation (Semantics of a Foundational Subset for Executble UML Models). Diese Spezifikation enthält die Definition einer Ausführungsumgebung ("virtuelle Maschine") für solche UML-Modelle.

### Beschreibung
Im Forschungsprojekt MDE4CPP (Model-driven Engineering for C++) des Fachgebiets System- und Software-Engineering wird ein Framework für die modellgetriebene Entwicklung mit der Programmiersprache C++ realisiert. Es beinhaltet folgende Komponenten: 
- Implementierungen fundamentaler (Meta)Metamodelle (UML, Ecore) ; 
- zugehörige Quellcodegeneratoren ; 
- graphische Modell-Editoren; 
- Ausführungsumgebungen für UML-Modelle gemäß entsprechender Industriestandards der OMG (fUML, PSCS, PSSM).

Aufgrund der Plattformunabhängigkeit der UML kann die Erstellung feingranularer Verhalten für ausführbare UML-Modelle bisweilen sehr aufwendig sein. Das liegt daran, dass selbst elementare Operationen (welche in gewöhnlichen Programmiersprachen bereits integriert sind) von Hand für die spezifische Zielplattform nachmodelliert werden müssen (z.B. Ein- und Ausgaben, arithmetische Operationen, ...). Um hierfür eine standardisierte Schnittstelle für plattformunabhängige, ausführbare UML-Modelle zu schaffen, definierte die OMG eine Art Bibliotheks-Modell: die fUML Foundational Model Library (fUML Library). Die fUML Library ist selbst ein UML-Modell und definiert eine standardisierte Schnittstelle zur Modellierung von elementaren Funktionalitäten in Form von Klassen, Datentypen, Operationen und Parametern. Strukturell kann sie also analog zu einer Programmbibliothek einer Programmiersprache verstanden werden.

### Ziel dieses Softwareprojektes 
ist die Realisierung der fUML Foundational Model Library in MDE4CPP. Hierzu gehören die folgenden wesentlichen Aspekte:
- Erstellung des entsprechenden UML-Modells der fUML Library mit Hilfe der Modellierungsumgebung Eclipse Modeling Tools
- Implementierung der elementaren Funktionalitäten in C++
- Anpassung vorhandener Quellcodegeneratoren um das Modell vollständig generieren zu können
- Integration der fUML Library in den graphischen Modell-Editor UMLDesigner zur komfortablen Einbindung der Funktionalitäten in eigene Modelle
- Die Validierung der realisierten Implementierung anhand von Unit-Tests sowie Tests der Kompatibilität mit plattformübergreifenden UML-Ausführungsumgebungen
- Erstellung einer entsprechenden Sammlung von Test-Modellen (Test-Suite)

### Tutorials und Entwicklungsumgebung
Zur Einarbeitung in die zu verwendenden Werkzeuge sowie das MDE4CPP-Framework werden zu Beginn des Softwareprojektes Tutorials durch den Betreuer angeboten. Außerdem wird Ihnen eine funktionsfähige Entwicklungsumgebung mit allen benötigten Softwarekomponenten zur Verfügung gestellt.

### Entwicklung
- Programmierung in C++ und Java
- Entwicklung mit: Eclipse Modeling Framework (IDE), Acceleo (Quellcodegenerierung), Sirius (graphische Modell-Editoren), UMLDesigner
- Modellierungssprachen und -standards: UML, fUML
- Versionskontrolle: Git, Github
- Vorgehen: modellgetrieben, inkrementell, iterativ

### Kommunikation
WebEx, E-Mail, Github

## 15. Ball and Hoop
Entwicklung eines Positionserfassungssystems zum hochdynamischen Betrieb mittels optischer Sensorik

### Beschreibung:
Für den im Aufbau befindlichen Versuchsstand Ball & Hoop soll ein neues bilddatenbasiertes Sensorkonzept entwickelt werden. Aufgrund der physikalischen Gegebenheiten kann nicht nur eine einzige Kamera verwendet werden. Stattdessen sollen mehrere Kameras zur Anwendung kommen, die auf einer Kreisscheibe angeordnet sind. Die Kameras sollen mittels Raspberry Pi angeschlossen und ausgewertet werden und das Positionssignal an eine zentrale Rechnereinheit übergeben werden.

### Aufgabe:
Ziel des Projekts ist es, mithilfe der Bildverarbeitung die Kugelposition (und ggf. Kugelgeschwindigkeit) zu ermitteln und die Sensorwerte weitergeben zu können. Da die einzelnen Kameras nur Teilausschnitte einfangen können, spielt hierbei die Kommunikation zwischen den Rechnereinheiten eine wichtige Rolle. Die ausgewertete Kugelposition soll so aufbereitet werden, dass Sie als Sensorwert an eine zentrale Rechenheit (z.B. dSpace-Karte oder weiteren Raspberry Pi) weitergegeben werden kann. Weiterhin soll die Kommunikationsmöglichkeit zu einer dSpace-Karte ausgearbeitet und bewertet werden. Auf der dSpace-Karte sind die Regelgesetze hinterlegt und werden die Ansteuerungssignale der Aktorik berechnet und ausgegeben. An die Datenverarbeitung und Kommunikation werden dabei Echtzeitanforderungen gestellt.

### Durchführung und Kommunikation:
Für die Bearbeitung des Projekts stehen die Laborräume und Ausschattung des FG Regelungstechnik zur Verfügung. Finanzielle Mittel zur Hardwarebeschaffung stehen ebenso zur Verfügung. Die Kommunikation mit den Projektbetreuern kann vorort oder per Webkonferenz stattfinden (Webex, Zoom, Skype, MS Teams, DFNconf, ...).

## 16. Simulation framework for autonomous driving on small-scale vehicle
### Beschreibung:
Aufgrund der umfangreichen, zeitaufwändigen und gefährlichen Tests in einer realen Testumgebung ist ein effizientes Simulationsframework für die Entwicklungsprozedur von autonomen Fahrfunktionen notwendig. In diesem Softwareprojekt ist es das Ziel, die sich entwickelnden autonomen Fahrfunktionen in einer virtuellen Umgebung zu validieren. Simulatoren wie der Carmaker sind jedoch für industrielle Zwecke konzipiert und kosten sehr viel. Für den pädagogischen und akademischen Zweck benötigen wir ein Simulations-Framework in Lite-Version, das die notwendigen Komponenten zur Validierung von Steuerungs- und Wahrnehmungsalgorithmen enthält. Um eine Simulationsumgebung aufzubauen, benötigen wir:
- Eine virtuelle Umgebung mit gerenderten Verkehrsinfrastrukturen, wie z. B. Straßenbegrenzungen, Fahrspuren, Verkehrszeichen, Hindernisse und andere Fahrzeuge. Die simulierte Umgebung soll die reale Welt nachbilden, wie in der folgenden Abbildung zu sehen.
- Fahrzeuge, die durch die physikalische Beschreibung in Form des kinematischen Modells dargestellt werden können.
- Wahrnehmungsmodule, die es dem Objekt ermöglichen, mithilfe von Kameras, Laserscannern und Bewegungssensoren Informationen aus der Umgebung zu erkennen und zu extrahieren.

### Entwicklung:
Ziel ist es, ein Simulationsframework aufzubauen, das es Studenten oder Forschern ermöglicht, eigene Verkehrsszenarien und virtuelle Testfahrzeuge mit den notwendigen Sensoren zu entwerfen, um Informationen aus der virtuellen Umgebung zu extrahieren. Zu den Aufgaben gehören:
- Aufbau eines benutzerdefinierten Verkehrsszenarios, bestehend aus verschiedenen Straßenelementen (Gerade, Kurve, S-Kurve, Kreuzung und Parkplatz).
- Rendering des Verkehrsszenarios mit Straßenbegrenzungen, Fahrspuren, Verkehrszeichen.
- Konfigurieren der gewünschten Route der Fahrzeuge durch eine Liste von Manövern.
- Importieren Sie mehrere Fahrzeuge (z. B. mehr als drei Fahrzeuge) in das Verkehrsszenario. Diese Fahrzeuge müssen über das Lenkrad und die Drosselklappensteuerung manövrierbar sein, so dass Situationen wie z. B. das Folgen und Überholen von Fahrzeugen simuliert werden können.
- Aus den an den virtuellen Fahrzeugen angebrachten Sensoren können Informationen extrahiert werden, wie z. B. Bildrahmen, Laserscannerpunkte, Position und Geschwindigkeit in bestimmten Koordinatensystemen.

Wir empfehlen die Verwendung von Gazebo (ein Open-Source-3D-Robotersimulator) in Kombination mit ROS (Robotic Operation System).
- https://www.ros.org
- http://gazebosim.org

### Lernziel:
Neben den Hauptanforderungen dieses Softwareprojekts sind die Studenten gefordert:
- Effektives Arbeiten im Team und die Entwicklung eines effizienten Simulations-Frameworks.
- Um die notwendigen Englischkenntnisse der Studenten aufzubauen, beschließen wir, dass die offizielle Sprache in diesem Projekt Englisch ist, einschließlich der schriftlichen Arbeit, des Quellcodes und der Diskussionstreffen mit entsprechenden Betreuern.
- Um die Programmierarbeit in diesem Projekt aufrechtzuerhalten, wird ein Gitlab-Repository eingerichtet, um den Überblick über die Programmierarbeit zu behalten.


## 17. Real time representation and visualization of distributed software systems 
?
