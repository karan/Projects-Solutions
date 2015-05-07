__author__ = 'brian'


def convert_to(text):
    """Pig Latin is a game of alterations played on the English language game. To create the Pig Latin
    form of an English word the initial consonant sound is transposed to the end of the word and an
    ay is affixed (Ex.: "banana" would yield anana-bay). Read Wikipedia for more information on rules."""

    consonants = 'bcdfghjklmnpqrstvwxz'
    counter = 0
    result = []
    for word in text.split():
        if word.startswith('y'):
            counter += 1

        while word[counter] in consonants:
            counter += 1

        if counter == 0:
            result.append(word + 'way')
        else:
            result.append(word[counter:] + word[:counter] + 'ay')
            counter = 0
    return ' '.join(result)