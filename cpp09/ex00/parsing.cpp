/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:34:05 by hucorrei          #+#    #+#             */
/*   Updated: 2023/10/25 11:56:24 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
pour input.txt:
controler la date 
controler année bissextile
controler le nombre de jour dans le mois
controler le nombre de jour dans le mois de fevrier
controler le nombre de jour dans le mois de fevrier en année bissextile
valeur entre 0 et 1000
delimiteur |
format de la date

pour data.csv:
--OK:lire et remplir STL map avec les données dates - valeurs
mini parsing
    --ok:verifier si fichier vide ou plusieurs lignes vides
    --ok:verifier les dates et le format de la date
    --ok:verifier les date doublons = erreur
    --ok:delimiteur ,
    --ok:apres le delimiteur directement une valeur double (pas de string) avec une precision de 2 chiffres apres la virgule (ex: 1.00)
    --ok:1er ligne date,exchange_rate
lire et controler data.csv
si pas d'erreur transferer les dates et valeurs dans un STL map
lire et controler input.txt ligne par ligne
    si pas d'erreur setup 2 variable date et value
        afficher la date, la valeur et le resultat de la recherche
        ex : 2011-01-03 => 3 = 0.9
    si erreur afficher erruer : 
        Error: not a positive number. 
        Error: too large a number.
        Error: bad input => 2001-42-42
*/