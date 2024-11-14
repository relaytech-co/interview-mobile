// GENERATED CODE - DO NOT MODIFY BY HAND

// ignore_for_file: implicit_dynamic_parameter, cast_nullable_to_non_nullable, always_use_package_imports

part of 'login_with_qr_response.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

LoginWithQrResponse _$LoginWithQrResponseFromJson(Map<String, dynamic> json) =>
    $checkedCreate(
      'LoginWithQrResponse',
      json,
      ($checkedConvert) {
        final val = LoginWithQrResponse(
          name: $checkedConvert('pitstop_name', (v) => v as String),
          email: $checkedConvert('pitstop_email', (v) => v as String),
          uid: $checkedConvert('pitstop_uid', (v) => v as String),
          jwtToken: $checkedConvert('jwt_token', (v) => v as String),
        );
        return val;
      },
      fieldKeyMap: const {
        'name': 'pitstop_name',
        'email': 'pitstop_email',
        'uid': 'pitstop_uid',
        'jwtToken': 'jwt_token'
      },
    );

Map<String, dynamic> _$LoginWithQrResponseToJson(
        LoginWithQrResponse instance) =>
    <String, dynamic>{
      'pitstop_name': instance.name,
      'pitstop_email': instance.email,
      'pitstop_uid': instance.uid,
      'jwt_token': instance.jwtToken,
    };
