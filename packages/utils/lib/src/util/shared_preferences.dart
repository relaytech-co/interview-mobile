import 'package:shared_preferences/shared_preferences.dart';

class SharedPreferencesClient {
  SharedPreferences? _sharedPreferences;

  Future<SharedPreferences> get instance async {
    return _sharedPreferences ??= await SharedPreferences.getInstance();
  }

  // call this method from iniState() function of mainApp().
  Future<SharedPreferences> getInstance() async {
    _sharedPreferences = await instance;
    return _sharedPreferences!;
  }

  Future<String?> getString(String key) async {
    final prefs = await instance;
    return prefs.getString(key);
  }

  Future<bool> setString(String key, String value) async {
    final prefs = await instance;
    return prefs.setString(key, value);
  }

  Future<bool> setBool(String key, {required bool value}) async {
    final prefs = await instance;
    return prefs.setBool(key, value);
  }

  Future<bool?> getBool(String key) async {
    final prefs = await instance;
    return prefs.getBool(key);
  }
}
