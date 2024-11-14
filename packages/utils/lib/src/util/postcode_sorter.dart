// ignore_for_file: public_member_api_docs

mixin PostcodeSorter {
  static int comparePostcodes(String a, String b) {
    final aPostcode = a.split(' ');
    final aAreaAndDistrict = aPostcode[0];

    final bPostcode = b.split(' ');
    final bAreaAndDistrict = bPostcode[0];

    final aArea = getLetters(aAreaAndDistrict);
    final bArea = getLetters(bAreaAndDistrict);

    if (aArea == bArea) {
      final aDistrict = getNumbers(aAreaAndDistrict);
      final bDistrict = getNumbers(bAreaAndDistrict);
      if (aDistrict == bDistrict) {
        final aSectorAndUnit = aPostcode[1];
        final bSectorAndUnit = bPostcode[1];

        final aSector = getNumbers(aSectorAndUnit);
        final bSector = getNumbers(bSectorAndUnit);

        if (aSector == bSector) {
          final aUnit = getLetters(aSectorAndUnit);
          final bUnit = getLetters(bSectorAndUnit);
          return aUnit.compareTo(bUnit);
        } else {
          return aSector.compareTo(bSector);
        }
      } else {
        return aDistrict.compareTo(bDistrict);
      }
    } else {
      return aArea.compareTo(bArea);
    }
  }

  static String getLetters(String input) {
    RegExp regex = RegExp(r'[a-zA-Z]');

    Iterable<Match> matches = regex.allMatches(input);

    String result = matches.map((match) => match.group(0)!).join('');

    return result;
  }

  static int getNumbers(String input) {
    // Use a regular expression to match only numeric characters
    RegExp regex = RegExp(r'\d+');

    // Use the findall method to get all matches in the input string
    Iterable<Match> matches = regex.allMatches(input);

    // Convert the matched strings to integers and return them as a list
    final numbers = matches.map((match) => int.parse(match.group(0)!)).toList().join();

    return int.parse(numbers);
  }
}
