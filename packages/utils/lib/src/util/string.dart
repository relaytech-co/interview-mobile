List<String> exceptions = [
  'a',
  'abaft',
  'about',
  'above',
  'afore',
  'after',
  'along',
  'amid',
  'among',
  'an',
  'apud',
  'as',
  'aside',
  'at',
  'atop',
  'below',
  'but',
  'by',
  'circa',
  'down',
  'for',
  'from',
  'given',
  'in',
  'into',
  'lest',
  'like',
  'mid',
  'midst',
  'minus',
  'near',
  'next',
  'of',
  'off',
  'on',
  'onto',
  'out',
  'over',
  'pace',
  'past',
  'per',
  'plus',
  'pro',
  'qua',
  'round',
  'sans',
  'save',
  'since',
  'than',
  'thru',
  'till',
  'times',
  'to',
  'under',
  'until',
  'unto',
  'up',
  'upon',
  'via',
  'vice',
  'with',
  'worth',
  'the","and',
  'nor',
  'or',
  'yet',
  'so'
];

extension TitleCase on String {
  String toTitleCase() {
    List<String> words = this.split(' ');
    String ret = '';
    for (final word in words) {
      if (containsDigits(word)) {
        ret += word + ' ';
      } else {
        if (word.isNotEmpty) {
          int i = 0;
          while (i < word.length && RegExp(r'\W').hasMatch(word[i])) {
            ret += word[i];
            i++;
          }
          if (word.length > i) {
            ret +=
                '${word[i].toUpperCase()}${(word.length > 1) ? word.substring(i + 1).toLowerCase() : ''} ';
          } else {
            ret += ' ';
          }
        }
      }
    }
    return ret.trim();
  }

  bool containsDigits(String input) {
    RegExp digitPattern = RegExp(r'\d');
    return digitPattern.hasMatch(input);
  }
}
