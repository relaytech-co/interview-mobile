import 'package:flutter/services.dart';
import 'package:url_launcher/url_launcher.dart';

Future<void> launchDialer(String phoneNumber) async {
  Clipboard.setData(ClipboardData(text: phoneNumber));

  final Uri dialerUri = Uri(
    scheme: 'tel',
    path: phoneNumber,
  );

  if (await canLaunchUrl(dialerUri)) {
    await launchUrl(dialerUri);
  } else {
    throw 'Could not launch $dialerUri';
  }
}

//MAVI Dec. 12 Leave this if we want to mask number in the future
// String maskPhoneNumber(String phoneNumber) {
//   // Step 1: Remove "+44"
//   phoneNumber = phoneNumber.replaceAll('+44', '');

//   // Step 2: Add "0" to the beginning if not present
//   if (!phoneNumber.startsWith('0')) {
//     phoneNumber = '0' + phoneNumber;
//   }

//   // Step 2: Add "141" to the beginning
//   phoneNumber = '141' + phoneNumber;

//   return phoneNumber;
// }
