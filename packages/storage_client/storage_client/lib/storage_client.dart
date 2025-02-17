library storage_client;

/// {@template storage_exception}
/// Exception thrown if a storage operation fails.
/// {@endtemplate}
class StorageException implements Exception {
  /// {@macro storage_exception}
  const StorageException(this.error, [this.stackTrace]);

  /// Error thrown during the storage operation.
  final Object error;

  /// Optional stack trace for the exception.
  final StackTrace? stackTrace;
}

/// A Dart Storage Client Interface
abstract class StorageClient {
  /// Returns value for the provided [key].
  /// Read returns `null` if no value is found for the given [key].
  /// * Throws a [StorageException] if the read fails.
  Future<String?> read({required String key});

  /// Writes the provided [key], [value] pair asynchronously.
  /// * Throws a [StorageException] if the write fails.
  Future<void> write({required String key, required String value});

  /// Removes the value for the provided [key] asynchronously.
  /// * Throws a [StorageException] if the delete fails.
  Future<void> delete({required String key});

  /// Removes all key, value pairs asynchronously.
  /// * Throws a [StorageException] if the delete fails.
  Future<void> clear();
}
