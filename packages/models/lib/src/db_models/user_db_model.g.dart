// GENERATED CODE - DO NOT MODIFY BY HAND

// ignore_for_file: implicit_dynamic_parameter, cast_nullable_to_non_nullable, always_use_package_imports

part of 'user_db_model.dart';

// **************************************************************************
// TypeAdapterGenerator
// **************************************************************************

class UserDbModelAdapter extends TypeAdapter<UserDbModel> {
  @override
  final int typeId = 1;

  @override
  UserDbModel read(BinaryReader reader) {
    final numOfFields = reader.readByte();
    final fields = <int, dynamic>{
      for (int i = 0; i < numOfFields; i++) reader.readByte(): reader.read(),
    };
    return UserDbModel(
      uid: fields[0] as String?,
      name: fields[1] as String?,
      email: fields[2] as String?,
    );
  }

  @override
  void write(BinaryWriter writer, UserDbModel obj) {
    writer
      ..writeByte(3)
      ..writeByte(0)
      ..write(obj.uid)
      ..writeByte(1)
      ..write(obj.name)
      ..writeByte(2)
      ..write(obj.email);
  }

  @override
  int get hashCode => typeId.hashCode;

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is UserDbModelAdapter &&
          runtimeType == other.runtimeType &&
          typeId == other.typeId;
}
