- [Introduction](#introduction)
  - [Risk Scenarios](#risk-scenarios)
  - [Security Goals](#security-goals)
    - [Message](#message)
  - [Security Engineering](#security-engineering)
  - [Lecture Roadmap](#lecture-roadmap)
- [Security Requirements](#security-requirements)
  - [Vulnerabilities](#vulnerabilities)
    - [Human](#human)
    - [Organizational](#organizational)
    - [Technical](#technical)
    - [Summary](#summary)
  - [Threats](#threats)
    - [Attackers](#attackers)
    - [Attack Methods](#attack-methods)
    - [Damager Potential](#damager-potential)
    - [Summary](#summary-1)
  - [Risk Analysis](#risk-analysis)
  - [Summary](#summary-2)
- [Security Policies and Models](#security-policies-and-models)
  - [Security Policies](#security-policies)
  - [Security Models](#security-models)
    - [Access Control Models](#access-control-models)
      - [IBAC](#ibac)
      - [RBAC](#rbac)
      - [ABAC](#abac)
      - [Summary](#summary-3)
    - [Information Flow Models](#information-flow-models)
      - [Denning](#denning)
      - [MLS](#mls)
      - [BLP](#blp)
      - [Biba](#biba)
      - [Summary](#summary-4)
    - [Non-interference Models](#non-interference-models)
    - [Hybrid Models](#hybrid-models)
      - [Brewer-Nash](#brewer-nash)
      - [LR-CW](#lr-cw)
      - [MLS-CW](#mls-cw)
- [Practical Security Engineering](#practical-security-engineering)
  - [Model Engineering](#model-engineering)
  - [Model Specification](#model-specification)
    - [CorPS](#corps)
    - [SELinux Policy Language](#selinux-policy-language)
  - [Summary](#summary-5)
- [Security Mechanisms](#security-mechanisms)
  - [Authorization](#authorization)
    - [Access Control Lists](#access-control-lists)
    - [Capability Lists](#capability-lists)
    - [Interceptors](#interceptors)
    - [Summary](#summary-6)
  - [Cryptographic Mechanisms](#cryptographic-mechanisms)
    - [Encryption](#encryption)
      - [Symmetric](#symmetric)
      - [Asymmetric](#asymmetric)
    - [Cryptographic Hashing](#cryptographic-hashing)
    - [Digital Signatures](#digital-signatures)
    - [Cryptographic Attacks](#cryptographic-attacks)
  - [Identification and Authentication](#identification-and-authentication)
    - [Passwords](#passwords)
    - [Biometrics](#biometrics)
    - [Cryptographic Protocols](#cryptographic-protocols)
      - [SmartCards](#smartcards)
      - [Authentication Protocols](#authentication-protocols)
  - [Summary](#summary-7)
- [Security Architectures](#security-architectures)
  - [Design Principles](#design-principles)
  - [Operating Systems Architectures](#operating-systems-architectures)
    - [Nizza](#nizza)
    - [SELinux](#selinux)
  - [Distributed Systems Architectures](#distributed-systems-architectures)
    - [CORBA](#corba)
    - [Web Services](#web-services)
    - [Kerberos](#kerberos)
  - [Summary](#summary-8)

# Introduction
## Risk Scenarios
Reducing Operational Risks: What responsibilities can we bear?

Critical Properties
- Security + Safety
- Reliability
- Correctness
- Availability
- Real Time
- Scalability
- Openness

Examples:
- Information Systems
- Communication Systems
- Energy Grid Management
- Traffic Management
- Consumer Technology

Responsibility for risks -> guaranteed properties!

Relevance of Security: Security properties if any IT system are mission-critial - independet of its application domain

## Security Goals
Our Faculty's Education and Examination Management System
- Maintains:
  - Course profiles (examination form/date, credit points)
  - Students records (personal data, registration to examinations, grades)
- Services:
  - Enrolment/expulsion of students
  - Registration to examination
  - Registration of examination marks
  - Information and attestations desk
- Operational Risks
  - Conditio sine qua non: Provability of information properties
  - Fake registration to examinations: integrity, non-repudiability ("nicht-abstreitbar")
  - Leakage of grades, personal data: confidentiality, integrity
  - Forgery of attestations: authenticity, integrity

Industry Control Systems
- e.g. Factorys, energy and water plants (public infrastructure)
  - "Chinese Hacking Team Caught Takin over decoy water plant"
  - "Internet Attack shuts off the Heat in Finland"
- Operational risks: Integrity & Availability of public community support systems

[Self Study Task]() Read about these two scenarios. Find one or more recent examples for attacks on public infrastructure, including some technical details, in the news. Keep all these scenarios in mind, we will come back to them in the next chapter:
- [Hacker breached 63 universities and government agencies](https://www.computerworld.com/article/3170724/hacker-breached-63-universities-and-government-agencies.html)
- [Ransomeware attacks on public services](https://www.nytimes.com/2019/08/22/us/ransomware-attacks-hacking.html)
- [Unsecured Databases](https://www.cnet.com/news/2019-data-breach-hall-of-shame-these-were-the-biggest-data-breaches-of-the-year/)
- [Worst data leaks and breaches in the last decade](https://www.cnet.com/how-to/14-of-the-worst-data-leaks-breaches-scrapes-and-security-snafus-in-the-last-decade/)

### Message
- Goal of IT Security: **Reduction of Operational Risks of IT Systems**
- Elementary: Protection of
  - Confidentiality
  - Integrity
  - Availability
  - Non-repudiability

Specific Security Goals: Terms
- Confidentiality: the property of information to be available only to anauthorized user group
- Integrity: the property of information to be protected against unauthorized modification
- Availability: the property of information to be available in an reasonable time frame
- Authenticity: the property to be able to identify the author of an information
- Non-repudiability: the combination of integrity and authenticity

|                            | Safety                                                           | Security                                                          |
| -------------------------- | ---------------------------------------------------------------- | ----------------------------------------------------------------- |
| Goal                       | To protect environment against hazards caused by system failures | To protect IT systems against hazards caused by malicious attacks |
|                            | Technical failures: power failure, ageing, dirt                  | Industrial espionage, fraud, blackmailing                         |
|                            | Human errors: stupidity, lacking education, carelessness         | Terrorism, vandalism                                              |
|                            | Force majeure: fire, lightning, earth quakes                     |
| => making sure things work | in the presence of system failures                               | in the face of an intelligent and maliciousadversary              |

## Security Engineering
Security Goals in Practice
- ... are diverse and complex to achieve
- ... require multiple stakeholders to cooperate
- ... involve cross-domain expertise

Security Engineering:
- Is a methodology that tries to tackle this complexity.
- Goal: Engineering IT systems that are *secure by design*.
- Approach: Stepwise increase of guarantees -> formal methods required!

Steps in Security Engineering:
![](Assets/Systemsicherheit-engineering-process.png)

## Lecture Roadmap
1. Security Requirements: Vulnerabilites, Threats, Risks
2. Security Policies and Models: Access Control, Information Flow, Non-Interference
3. Practical Security Engineering: Model Engineering, Model, Specification, Model Implementation
4. Security Mechanisms: FYI Authorization, Authentication, Cryptography
5. Security Architectures: TCBs and Reference Monitors, Nizza,SELinux, Kerberos


# Security Requirements
## Vulnerabilities
### Human
### Organizational
### Technical
### Summary
## Threats
### Attackers
### Attack Methods
### Damager Potential
### Summary
## Risk Analysis
## Summary

# Security Policies and Models
## Security Policies
## Security Models
### Access Control Models
#### IBAC
#### RBAC
#### ABAC
#### Summary
### Information Flow Models
#### Denning
#### MLS
#### BLP
#### Biba
#### Summary
### Non-interference Models
### Hybrid Models
#### Brewer-Nash
#### LR-CW
#### MLS-CW

# Practical Security Engineering
## Model Engineering 
## Model Specification 
### CorPS
### SELinux Policy Language
## Summary

# Security Mechanisms
## Authorization
### Access Control Lists
### Capability Lists
### Interceptors
### Summary
## Cryptographic Mechanisms
### Encryption
#### Symmetric
#### Asymmetric
### Cryptographic Hashing
### Digital Signatures
### Cryptographic Attacks
## Identification and Authentication
### Passwords
### Biometrics
### Cryptographic Protocols
#### SmartCards
#### Authentication Protocols
## Summary

# Security Architectures
## Design Principles
## Operating Systems Architectures
### Nizza
### SELinux 
## Distributed Systems Architectures
### CORBA 
### Web Services 
### Kerberos 
## Summary 