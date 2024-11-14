import 'package:flutter_image_compress/flutter_image_compress.dart';
import 'dart:typed_data';

abstract class ImageCompressor {
  Future<Uint8List?> compressWithFile({
    required String path,
    required int minHeight,
    required int minWidth,
    required int quality,
    required bool keepExif,
  });
}

class RImageCompressor implements ImageCompressor {
  @override
  Future<Uint8List?> compressWithFile({
    required String path,
    required int minHeight,
    required int minWidth,
    required int quality,
    required bool keepExif,
  }) {
    return FlutterImageCompress.compressWithFile(
      path,
      minHeight: minHeight,
      minWidth: minWidth,
      quality: quality,
      keepExif: keepExif,
    );
  }
}
