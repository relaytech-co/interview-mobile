// import 'package:flutter/rendering.dart';
// import 'package:hive/hive.dart';
// import 'package:hive_flutter/hive_flutter.dart';
// import 'package:models/models.dart';

// /// {@template background_request_resource}
// /// Resource responsible for retrieving stored background requests
// /// {@endtemplate}
// class BackgroundRequestResource {
//   /// {@macro background_request_resource}
//   const BackgroundRequestResource({
//     required this.box,
//   });
//   final Box<BackgroundDbRequestModel> box;

//   List<BackgroundDbRequestModel>? getPendingBackgroundRequests() {
//     final requests = box.values.toList();

//     return requests;
//   }

//   Future<void> saveRequest(BackgroundDbRequestModel request) async {
//     try {
//       box.add(request);
//     } catch (err) {
//       debugPrint(err.toString());
//     }
//   }

//   // Future<void> deleteOldPODs() async {
//   //   final pods = box.values.toList();
//   //   final now = DateTime.now();
//   //   final oldPODs =
//   //       pods.where((element) => now.difference(element.timestamp ?? now).inDays > 3).toList();
//   //   for (var i = 0; i < oldPODs.length; i++) {
//   //     final pod = oldPODs[i];
//   //     final indexOf = pods.indexOf(pod);
//   //     if (box.isNotEmpty) {
//   //       box.deleteAt(indexOf);
//   //     }
//   //   }
//   // }

//   // Future<void> deletePOD(List<int> image) async {
//   //   final pods = box.values.toList();
//   //   final pod = pods.where((element) => element.image == image).toList();
//   //   if (pod.isNotEmpty) {
//   //     final indexOf = pods.indexOf(pod.first);
//   //     if (box.isNotEmpty) {
//   //       box.deleteAt(indexOf);
//   //     }
//   //   }
//   // }
// }
