extension UriExtensions on Uri {
  /// Appends [path] into this [Uri].
  /// This is just a convenience [replace] operation that takes into account the
  /// current [path] value.
  ///
  /// e.g.:
  /// https://some-url.com + '/some/path' = https://some-url.com/some/path
  /// https://some-url.com/with/path + '/some/path' = https://some-url.com/with/path/some/path
  Uri appendPath(
    String path, {
    String? query,
    Map<String, dynamic>? queryParameters,
  }) {
    return replace(
      pathSegments: [
        ...pathSegments,
        ...path.split('/'),
      ].where((path) => path.isNotEmpty),
      query: query,
      queryParameters: queryParameters,
    );
  }
}
