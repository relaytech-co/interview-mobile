String relaySupportUri(
        {required String token, required String driverId, required String courierEmail}) =>
    'https://relaytech.co/new-chatbot-dixa?token=$token&operative_email=$courierEmail&operative_id=$driverId&operative_type=car';

const int geofencingDistanceInMeters = 50;

const maxRoutesAllowed = 5;
const plannerActionFooterHeight = 140.0;
const plannerActionFooterWithErrorHeight = 160.0;
const plannerZoneTutorial = 'got_zone_planner_tutorial';
