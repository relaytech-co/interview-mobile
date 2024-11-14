import 'dart:math';

class GeolocationUtils {
  /// Returns the distance between two points in meters.
  static double distanceBetween(double lat1, double lon1, double lat2, double lon2) {
    final double earthRadius = 6371000; // meters
    final double dLat = _toRadians(lat2 - lat1);
    final double dLon = _toRadians(lon2 - lon1);
    final double a = sin(dLat / 2) * sin(dLat / 2) +
        cos(_toRadians(lat1)) * cos(_toRadians(lat2)) * sin(dLon / 2) * sin(dLon / 2);
    final double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return earthRadius * c;
  }

  static double _toRadians(double degrees) {
    return degrees * pi / 180;
  }

  /// Returns identifier for a shipment's geofence
  /// Ensures consistent format throughout the app
  /// Format: `<routeUid>_<shipmentUid>`
  static String shipmentGeofenceIdentifier({
    required String routeUid,
    required String shipmentUid,
  }) {
    return '${routeUid}_$shipmentUid';
  }
}
